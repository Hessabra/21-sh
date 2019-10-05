/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotywhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:25:38 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 18:40:26 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_quotis 	nbr_quote2(char *arg, int *bs, char c)
{
	t_quotis		nbr;
	int				mark;
	int				start;

	nbr.s = 0;
	nbr.d = 0;
	nbr.n = 0;
	start = 0;
	while (*arg)
	{
		mark = 1;
		if (*arg == 92)
		{
			(*bs > 0) ? mark = 0 : mark;
			arg += ft_entier(*bs);
			bs++;
		}
		if (*arg && !start && *arg == c)
		{
			if (c == 39)
				start = 1;
			else if (c == 34 && mark)
				start = -1;
		}
		else if (start && *arg && *arg == 39 && ft_parite(nbr.d))
			(nbr.s)++;
		else if (start && mark && *arg && *arg == 34 && ft_parite(nbr.s))
			(nbr.d)++;
		else if (start && mark && *arg && ft_parite(nbr.d) && ft_parite(nbr.s))
			(nbr.n) += 2;
		arg++;
	}
	if (start)
	{
		if (c == 39)
			nbr.s++;
		else if (c == 34 && mark)
			nbr.d++;
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
	while ((g_ctrl_dsig && g_herdoc_sig) && (!ft_parite(last.s) || !ft_parite(last.d)))
	{
		if (!ft_parite(last.d))
			ft_printf("\nDquote>>\n");
		else
			ft_printf("\nQuote>>\n");
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
