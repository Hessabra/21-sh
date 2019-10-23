/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 05:33:32 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/23 16:40:32 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mixed.h"

int			firstif_lenpart(int *i, char *str, int **bs)
{
	*i = 0;
	if (str[*i] != 34 && str[*i] != 39)
	{
		while (str[*i] && str[*i] != 34 && str[*i] != 39)
		{
			if (str[*i] == 92)
			{
				*i += ft_entier(**bs);
				(**bs > 0) ? (*i)++ : *i;
				(*bs)++;
			}
			else
				(*i)++;
		}
		return (0);
	}
	return (1);
}

int			secondif_lenpart(int *i, char *str)
{
	if (str[*i] == 39)
	{
		(*i)++;
		while (str[*i] && str[*i] != 39)
			(*i)++;
		(*i)++;
		return (0);
	}
	return (1);
}
