/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 02:29:53 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/26 20:56:35 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include "cdi.h"

static void		racc1(char *ar, char *arg, int *y)
{
	if (ar)
		ft_putendl_fd("Too much arguments...", 2);
	else
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(arg, 2);
	}
	*y = 0;
}

static void		racc2(char **env, int *y)
{
	int			x;

	if ((x = ft_know(env, "HOME")) > -1)
		if (chdir(env[x] + 5))
		{
			ft_putendl_fd("I can't change to home directory...", 2);
			*y = 0;
		}
}

void			cdi(char **arg, char ***env)
{
	int			x;
	int			y;
	char		*tmp;

	y = 1;
	tmp = (char *)malloc(sizeof(char) * 1000);
	tmp = getcwd(tmp, 100);
	if (!(arg[1]))
		racc2(*env, &y);
	else if (arg[2])
		racc1(arg[3], arg[1], &y);
	else if (ft_strequ(arg[1], "-"))
	{
		if ((x = ft_know(*env, "OLDPWD")) > -1)
			if (chdir((*env)[x] + 7))
				y = erro((*env)[x] + 7);
	}
	else if (chdir(arg[1]))
		y = erro(arg[1]);
	if (y)
	{
		envech(&(*env), tmp);
		envch(&(*env));
	}
	free(tmp);
}
