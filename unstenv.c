/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:04:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/10 20:49:44 by hessabra         ###   ########.fr       */
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

static char		**racc1(char **envi, char **env, char *arg)
{
	int		i;
	int		k;
	int		x;

	i = 0;
	k = 0;
	if ((x = ft_know(env, arg)) > -1)
	{
		while (env[i])
		{
			if (i != x)
			{
				envi[k] = ft_strdup(env[i]);
				k++;
			}
			i++;
		}
		envi[k] = NULL;
		return (envi);
	}
	return (env);
}

char			**unstenv(char **arg, char ***env)
{
	int			i;
	char		**envi;

	envi = (char **)ft_mema(sizeof(char *) * (lentab(*env) + 1));
	if (!arg[1])
	{
		ft_putendl_fd("I need more arguments...", 2);
		dfre(envi);
		return (*env);
	}
	i = 0;
	while (arg[i])
	{
		envi = racc1(envi, *env, arg[i]);
		i++;
	}
	return (envi);
}
