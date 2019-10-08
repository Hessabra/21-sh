/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:33:35 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 23:35:35 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_1(char **arg, char ***env)
{
	int		i;

	i = 1;
	if (ft_strequ(arg[0], "bye") || ft_strequ("exit", arg[0]))
		i = exi(arg, env);
	else if (ft_strequ(arg[0], "setenv"))
	{
		stenv(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "unsetenv"))
	{
		*env = unstenv(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "echo"))
		i = ech(arg);
	return (i);
}

int		builtin_2(char **arg, char ***env)
{
	int			i;

	if (ft_strequ(arg[0], "cd"))
	{
		cdi(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "env"))
	{
		i = 0;
		while ((*env)[i])
		{
			ft_putstr((*env)[i]);
			ft_putchar('\n');
			i++;
		}
		return (0);
	}
	return (1);
}
