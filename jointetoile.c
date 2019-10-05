/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jointetoile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:41:50 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 05:25:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			lenab(int *a)
{
	int				i;

	i = 0;
	while (a[i] != 0)
		i++;
	return (i);
}

int					*jointetoile(int *a, int *b)
{
	int				lena;
	int				i;
	int				*c;
	int				*tmp;

	i = 0;
	lena = lenab(a);
	c = (int *)malloc(sizeof(int) * (lena + lenab(b) + 1));
	tmp = a;
	while (*a && (c[i] = *a))
	{
		a++;
		i++;
	}
	free(tmp);
	tmp = b;
	while (*b && (c[i] = *b))
	{
		b++;
		i++;
	}
	c[i] = 0;
	free(tmp);
	return (c);
}
