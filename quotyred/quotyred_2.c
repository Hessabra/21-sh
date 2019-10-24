/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 01:05:31 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 04:06:35 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotyred.h"

static void			nbr_arg2_2(char *str, int *bs, t_nbr_arg *na)
{
	na->i = 1;
	if (na->marq == 1 && (str[na->j] == '>' || str[na->j] == '<'))
	{
		if (na->j > 0 && str[na->j - 1] != ' ' && str[na->j - 1] != '\t' &&
				str[na->j - 1] != '\n')
			na->result++;
		if (str[na->j + 1] == str[na->j])
		{
			na->j++;
			na->marq = 0;
		}
		if (str[na->j + 1] != ' ' && str[na->j + 1] != '\t' &&
				str[na->j + 1] != '\n')
			na->result++;
		na->marq = 1;
	}
	if (str[na->j] == 92)
	{
		(*bs > 0) ? na->i = 0 : na->i;
		na->j += ft_entier(*bs);
		bs++;
	}
}

int					nbr_arg2(char *str, int *bs)
{
	t_nbr_arg		na;

	na.result = 0;
	na.i = -1;
	na.j = 0;
	na.marq = 1;
	while (str[na.j])
	{
		nbr_arg2_2(str, bs, &na);
		if (str[na.j] == 39 || str[na.j] == 34)
		{
			if (na.marq == 1 && (str[na.j] == 39 || (str[na.j] == 34 && na.i)))
				na.marq = 0;
			else if (str[na.j] == 39 || (str[na.j] == 34 && na.i))
				na.marq = 1;
		}
		if (na.i && str[na.j] && (str[na.j] == ' ' && na.marq) &&
				str[na.j + 1] && str[na.j + 1] > 32)
			(na.result)++;
		(na.j)++;
	}
	if (na.i != -1)
		(na.result)++;
	return (na.result);
}
