/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:10:31 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:20:00 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		lentab(char **tabe)
{
	int			i;

	i = 0;
	while (tabe[i])
		i++;
	return (i);
}

char			**aloc(char **env)
{
	char		**envi;
	int			i;

	if (env)
	{
		envi = (char **)ft_memalloc(sizeof(char *) * (lentab(env) + 1));
		i = 0;
		while (env[i])
		{
			envi[i] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(env[i]) + 1));
			envi[i] = ft_strcpy(envi[i], env[i]);
			i++;
		}
		envi[i] = NULL;
		return (envi);
	}
	return (env);
}
