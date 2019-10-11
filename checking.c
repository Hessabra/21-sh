/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 08:12:26 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/11 00:52:11 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	racc1(char *pwd)
{
	chdir(pwd);
	ft_strdel(&pwd);
}

static int	racc3(char **pwd, char *command)
{
	*pwd = (char *)ft_mema(sizeof(char) * 1000);
	*pwd = getcwd(*pwd, 1000);
	if (command[0] != '.')
		chdir("/");
	if (!(access(command, F_OK)))
	{
		racc1(*pwd);
		return (1);
	}
	return (0);
}

char		*checking(char *command, char *env, int x)
{
	char	*pwd;
	char	**paths;
	int		i;

	if (racc3(&pwd, command))
		return (command);
	else if (x > -1 && command[0] != '.')
	{
		paths = ft_strsplit(env, ':');
		i = 0;
		while (paths[i])
		{
			chdir(paths[i]);
			if (!(access(command, F_OK)))
			{
				racc1(pwd);
				return (paths[i]);
			}
			i++;
		}
		dfre(paths);
	}
	racc1(pwd);
	return (NULL);
}
