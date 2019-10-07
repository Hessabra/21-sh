/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotywhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:25:38 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 23:19:43 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_nbr_quote2(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

static int		nbr_quote2_2(char **arg, int *mark, int **bs)
{
	if (**arg == 92)
	{
		(**bs > 0) ? *mark = 0 : *mark;
		*arg += ft_entier(**bs);
		(*bs)++;
	}
	return (1);
}

static void		nbr_quote2_3(char *arg, int mark, t_quotis *nbr, int start)
{
	if (start && *arg && *arg == 39 && ft_parite(nbr->d))
		(nbr->s)++;
	else if (start && mark && *arg && *arg == 34 && ft_parite(nbr->s))
		(nbr->d)++;
	else if (start && mark && *arg && ft_parite(nbr->d) && ft_parite(nbr->s))
		(nbr->n) += 2;
}

static t_quotis	nbr_quote2(char *arg, int *bs, char c)
{
	t_quotis	nbr;
	int			mark;
	int			start;

	init_nbr_quote2(&(nbr.s), &(nbr.d), &(nbr.n), &start);
	while (*arg && (mark = 1) && nbr_quote2_2(&arg, &mark, &bs))
	{
		if (*arg && !start && *arg == c)
		{
			if (c == 39)
				start = 1;
			else if (c == 34 && mark)
				start = -1;
		}
		else
			nbr_quote2_3(arg, mark, &nbr, start);
		arg++;
	}
	if (start)
	{
		(c == 39) ? nbr.s++ : c;
		(c == 34 && mark) ? nbr.d++ : c;
	}
	return (nbr);
}

int				quotiwhile(t_quotis last, char **arg, int **bs, t_read *insert)
{
	t_quotis	help;
	char		*buff;
	int			*tmbs;

	*arg = ft_jandf(*arg, "\n", 1, 0);
	g_ctrl_dsig = 1;
	while ((g_ctrl_dsig && g_herdoc_sig) && (!ft_parite(last.s)
			|| !ft_parite(last.d)))
	{
		(!ft_parite(last.d)) ? ft_printf("\nDq>>\n") : ft_printf("\nSq>>\n");
		buff = ft_readline(buff, insert);
		effectornot(&tmbs, buff);
		if (buff && g_ctrl_dsig)
		{
			help = nbr_quote2(buff, tmbs, (!ft_parite(last.s)) ? 39 : 34);
			last.d += help.d;
			last.n += help.n;
			last.s += help.s;
			if (!ft_parite(last.s) || !ft_parite(last.d))
				buff = ft_jandf(buff, "\n", 1, 0);
			*arg = ft_jandf(*arg, buff, 0, 1);
		}
		*bs = jointetoile(*bs, tmbs);
	}
	return (1);
}
