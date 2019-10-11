/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:02:17 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/11 01:59:18 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	racc1(char ***env, char *tmp, int x)
{
	int		j;

	ft_strdel((&(*env)[x]));
	(*env)[x] = (char *)ft_mema(sizeof(char) * (ft_strlen(tmp) + 1));
	j = 0;
	while (tmp[j])
	{
		(*env)[x][j] = tmp[j];
		j++;
	}
	(*env)[x][j] = '\0';
	ft_strdel(&tmp);
}

static int	racc2(char **arg)
{
	if (arg[1] && arg[2] && arg[3])
	{
		ft_putendl_fd("OwO... Sorry too much arguments", 2);
		return (1);
	}
	if (!ft_isalpha(arg[1][0]))
	{
		ft_putendl_fd("UwU... The starting char should be alpha only", 2);
		return (1);
	}
	if (!ft_alnu(arg[1]))
	{
		ft_putendl_fd("Oups! Variable name must only be with alphanumeric", 2);
		return (1);
	}
	return (0);
}

void		stenv(char **arg, char ***env)
{
	int		x;
	char	*tmp;

	if (arg[1])
	{
		if (racc2(arg))
			return ;
		x = ft_know(*env, arg[1]);
		if (arg[2])
			tmp = ft_jandf(ft_strjoin(arg[1], "="), arg[2], 1, 0);
		else
			tmp = ft_strjoin(arg[1], "=");
		if (x == -1)
		{
			*env = ft_tabjoin(env, tmp);
			ft_strdel(&tmp);
		}
		else
			racc1(&(*env), tmp, x);
	}
}
