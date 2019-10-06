/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:03:09 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 04:59:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dolo.h"

int			condition_dolo(int quot, int bs, char *s, t_dolor t)
{
	if (quot == 2 && (ft_entier(bs) % 2) &&
		s[t.i + ft_entier(bs)] != '"' &&
		s[t.i + ft_entier(bs)] != '$')
		return (1);
	return (0);
}

void		lastelse_dolo(char **fin, char *s, t_dolor *t)
{
	(*fin) = ft_jandf((*fin), ft_strsub(s, t->i, 1), 1, 1);
	(t->i)++;
}

void		initi_dolo(char **fin, int *i, int *backslash)
{
	(*fin) = ft_strdup("");
	*i = 0;
	*backslash = 1;
}

void		replace_dolo(int *backslash, int markdown, char **fin)
{
	*backslash = 0;
	while (*backslash < markdown)
	{
		*fin = ft_jandf(*fin, "\\", 1, 0);
		(*backslash)++;
	}
	*backslash = 1;
}

void		intent_dolo(int *i, int **bs, int *backslash, char *s)
{
	*i += ft_entier(**bs);
	if (**bs > 0 || s[*i] == '~')
		*backslash = 0;
	(*bs)++;
}
