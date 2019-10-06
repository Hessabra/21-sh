/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usetoken_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:17:27 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 00:34:49 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usetoken.h"

void				getnresetfd(int i)
{
	static int		fd[3];

	if (i == 0)
	{
		fd[0] = dup2(0, 100);
		fd[1] = dup2(1, 101);
		fd[2] = dup2(2, 102);
	}
	else if (i == 1)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		dup2(fd[2], 2);
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
	}
}

static int			little_usetoken_2(t_usetok *u, int *token, char **args)
{
	if (token[u->i + 1] == 11 && token[u->i] != 4
			&& (u->fdw = open(args[u->i + 1], O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		u->error = 1;
		ft_putstr_fd("File error\n", 2);
		return (0);
	}
	return (1);
}

static void			little_usetoken(t_usetok *u, int *token, char **args)
{
	if (little_usetoken_2(u, token, args) && token[u->i + 1] == 11 &&
			token[u->i] == 4 && (u->fdw = open(args[u->i + 1], O_WRONLY |
			O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		u->error = 1;
		ft_putstr_fd("File error\n", 2);
	}
	else
	{
		if (token[u->i + 1] == 10)
		{
			u->fdw = ft_atoi(args[u->i + 1]);
			(!checkfd(u->fdw, NULL, 2)) ? u->error = 1 : u->fd;
		}
		if (token[u->i] == 1 || token[u->i] == 2 || token[u->i] == 4)
			dup2(u->fdw, u->fd);
		if (token[u->i] == 3)
		{
			dup2(u->fdw, 1);
			dup2(u->fdw, 2);
		}
		if (token[u->i] == 5)
			close(u->fd);
	}
}

static void			big_usetoken(t_usetok *u, int *token, char **args,
		char ***string_heredoc)
{
	if (token[u->i] == 6 && (u->fdw = open(args[u->i + 1], O_RDONLY)) == -1)
	{
		u->error = 1;
		ft_putstr_fd("File error\n", 2);
	}
	if (token[u->i] == 8)
	{
		u->fdw = ft_atoi(args[u->i + 1]);
		(!checkfd(u->fdw, NULL, 0)) ? u->error = 1 : u->fd;
	}
	if (token[u->i] != 7)
		dup2(u->fdw, u->fd);
	if (token[u->i] == 7)
	{
		u->new = **string_heredoc;
		(*string_heredoc)++;
	}
}

void				elif_usetoken(t_usetok *u, int *token, char **args,
		char ***string_heredoc)
{
	if (token[u->i] == 8 && token[u->i + 1] == 11 && (u->error = 1))
		checkfd(u->fd, args[u->i + 1], 1);
	else if (token[u->i] >= 1 && token[u->i] <= 5)
		little_usetoken(u, token, args);
	else if (token[u->i] >= 6 && token[u->i] <= 8)
		big_usetoken(u, token, args, string_heredoc);
}
