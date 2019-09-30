/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotywhile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:25:38 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/30 18:28:02 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_quotis 	nbr_quote2(char *arg, int *bs, char c)
{
	t_quotis	nbrs;
	int			mark;
	int			start;

	nbrs.s = 0;
	nbrs.d = 0;
	nbrs.n = 0;
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
		else if (start && *arg && *arg == 39 && ft_parite(nbrs.d))
			(nbrs.s)++;
		else if (start && mark && *arg && *arg == 34 && ft_parite(nbrs.s))
			(nbrs.d)++;
		else if (start && mark && *arg && ft_parite(nbrs.d) && ft_parite(nbrs.s))
			(nbrs.n)+=2;
		arg++;
	}
	if (start)
	{
		if (c == 39)
			nbrs.s++;
		else if (c == 34 && mark)
			nbrs.d++;
	}
	return (nbrs);
}
int		quotiwhile(t_quotis last, char **arg, int **bs, t_read *insert)
{
	t_quotis    help;
	char        *buff;
    int         *tmbs;

	while (!ft_parite(last.s) || !ft_parite(last.d))
	{
		if (insert->is_quote == -1)
		{
			insert->is_quote = 0;
			return (0);
		}
		else 
			insert->is_quote = 1;
		if (!ft_parite(last.d))
			ft_printf("\nDquote>>\n");
		else
			ft_printf("\nQuote>>\n");
		buff = ft_readline(buff, insert);
        effectornot(&tmbs, buff);
		if (buff)
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