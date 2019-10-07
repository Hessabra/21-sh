/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:11:15 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 23:24:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	racc(int i, char ***env, char **arg)
{
	ft_putstr("\e[35;1m\x1B[100mNooo don't leave me TT-TT\e[0m\n");
	dfre(*env);
	dfre(arg);
	ft_defult_term();
	exit(i);
}

int			exi(char **arg, char ***env)
{
	int		i;

	if (arg[1])
	{
		if (arg[2])
		{
			ft_putendl_fd("Too many arguments...", 2);
			return (0);
		}
		i = 0;
		while (arg[1][i])
		{
			if (ft_isdigit(arg[1][i]) == 0)
			{
				ft_putendl_fd("I need a number to proceed...", 2);
				racc(1, env, arg);
			}
			i++;
		}
		if (ft_strequ(arg[1], "0") == 0)
			racc(1, env, arg);
	}
	racc(0, env, arg);
	return (1);
}
