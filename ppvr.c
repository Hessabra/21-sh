/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppvr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:06:18 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:20:00 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		zaapi(char *str, int *i, int **bs, char c)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
	{
		if (c != 39 && str[*i] == 92)
		{
			*i += ft_entier(**bs) - 1;
			(**bs > 0) ? (*i)++ : *i;
			(*i)++;
		}
		(*i)++;
	}
}

static int		ft_count(char *str, int *bs)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i + 1] && (str[i] == 39 || str[i] == 34))
			zaapi(str, &i, &bs, str[i]);
		if (str[i] == '|' || str[i] == ';' || !str[i + 1])
			nb++;
		else if (str[i] == 92)
		{
			i += ft_entier(*bs) - 1;
			(*bs > 0 && (str[i + 1] != 39)) ? i++ : i;
			bs++;
		}
		i++;
		if (nb == 0 && !str[i])
			nb++;
	}
	return (nb);
}

static int		ft_size(char *str, int p, int **bs, int *ppvr)
{
	int			i;
	int			j;
	int			k;

	i = p;
	j = 1;
	while (str[i] && str[i] != '|' && str[i] != ';')
	{
		if (str[i] == '>' || str[i] == '<')
			j = -1;
		if (str[i + 1] && (str[i] == 39 || str[i] == 34))
			zaapi(str, &i, bs, str[i]);
		if (str[i] == 92)
		{
			i += ft_entier(**bs) - 1;
			(**bs > 0 && str[i + 1] != 39) ? i++ : i;
			(*bs)++;
		}
		i++;
	}
	k = j;
	(str[i] == '|' && j == -1) ? j = -2 : j;
	*ppvr = nbrope(str + i, j) * k;
	return (i - p - 1);
}

static void		ft_ppvr_2(int *p, int *ppvr, int *ippvr, t_splitbs *ij)
{
	if (ft_entier(ppvr[*ippvr]) == 1 ||
		ft_entier(ppvr[*ippvr]) == 2 ||
		ppvr[*ippvr] == -3 || ppvr[*ippvr] == -4)
		(*p)++;
	else if (ft_entier(ppvr[*ippvr]) == 4)
		*p += 2;
	(ij->i)++;
	(*ippvr)++;
}

char			**ft_ppvr(char *str, int *bs, int **ppvr)
{
	t_ppvrf		pf;
	t_splitbs	ij;
	int			p[1];
	char		**tab_str;

	ij.i = 0;
	*p = 0;
	pf.lenarg = ft_count(str, bs);
	tab_str = (char **)ft_memalloc(sizeof(char *) * (pf.lenarg + 1));
	*ppvr = (int *)ft_memalloc(sizeof(char *) * (pf.lenarg + 1));
	if (tab_str && !(pf.ippvr = 0))
	{
		while (ij.i < pf.lenarg && !(ij.j = 0))
		{
			pf.len = ft_size(str, *p, &bs, &((*ppvr)[pf.ippvr])) + 1;
			tab_str[ij.i] = (char *)ft_memalloc(sizeof(char) * (pf.len + 1));
			while (ij.j < pf.len)
				tab_str[ij.i][(ij.j)++] = str[(*p)++];
			tab_str[ij.i][ij.j] = '\0';
			ft_ppvr_2(&(*p), *ppvr, &(pf.ippvr), &ij);
		}
		(*ppvr)[pf.ippvr] = 9;
		tab_str[pf.lenarg] = 0;
	}
	return (tab_str);
}
