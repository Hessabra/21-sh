/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:04:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/15 17:54:17 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		lentab(char **tabe)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tabe[i])
	{
		i++;
		j++;
	}
	return (j);
}

static void		racc1(char ***envi, char **env, char *arg)
{
	int		i;
	int		k;
	int		x;
	char	*tmp;

	i = 0;
	k = 0;
	x = ft_know(env, arg);
	while (env[i])
	{
		if (i != x)
		{
			tmp = (*envi)[k];
			(*envi)[k] = ft_strdup(env[i]);
			ft_strdel(&tmp);
			k++;
		}
		i++;
	}
	tmp = (*envi)[k];
	(*envi)[k] = NULL;
	ft_strdel(&tmp);
}

static int		nbr_deletedvar(char **arg, char **env)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (arg[i])
	{
		if (ft_know(env, arg[i]) > -1)
			result++;
		i++;
	}
	return (result);
}

char			**unstenv(char **arg, char ***env)
{
	int			i;
	char		**envi;

	envi = (char **)ft_mema(sizeof(char *) * (lentab(*env) + 1
			- nbr_deletedvar(arg, *env)));
	if (!arg[1])
	{
		ft_putendl_fd("I need more arguments...", 2);
		dfre(envi);
		return (*env);
	}
	i = 0;
	while (arg[i])
	{
		racc1(&envi, *env, arg[i]);
		i++;
	}
	dfre(*env);
	return (envi);
}
