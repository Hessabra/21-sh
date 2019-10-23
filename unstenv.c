/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:04:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/15 21:47:14 by hessabra         ###   ########.fr       */
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

	dfre(*envi);
	i = 0;
	k = 0;
	x = ft_know(env, arg);
	(x > -1) ? i = 1 : 0;
	*envi = (char **)ft_mema(sizeof(char *) * (lentab(env) + 1 - i));
	i = 0;
	while (env[i])
	{
		if (i != x)
		{
			(*envi)[k] = ft_strdup(env[i]);
			k++;
		}
		i++;
	}
	(*envi)[k] = NULL;
}

char			**unstenv(char **arg, char ***env)
{
	int			i;
	char		**envi;

	envi = NULL;
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
