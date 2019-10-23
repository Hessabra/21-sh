/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ech.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 01:54:37 by hessabra          #+#    #+#             */
/*   Updated: 2019/06/26 22:43:37 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		tiret(int *i, char *c)
{
	if (ft_strequ(c, "-"))
	{
		(*i)++;
		return (-1);
	}
	if (ft_strequ(c, "-n"))
	{
		(*i)++;
		return (0);
	}
	return (1);
}

int				ech(char **arg)
{
	int			i;
	int			j;
	int			m;

	i = 1;
	m = tiret(&i, arg[1]);
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			write(1, &(arg[i][j]), 1);
			j++;
		}
		i++;
		(arg[i]) ? write(1, " ", 1) : i;
	}
	(m) ? write(1, "\n", 1) : m;
	return (0);
}
