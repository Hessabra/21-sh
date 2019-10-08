/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:35:46 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 20:55:55 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void		protected_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
	{
		ft_putendl_fd("Fail to dup2", 2);
		exit(0);
	}
}

void		protected_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		ft_putendl_fd("Fail to pipe", 2);
		exit(0);
	}
}

void		exec_pipe(char **arg, char **env)
{
	char		*path;

	path = NULL;
	if (ft_strequ(arg[0], "cat") ||
		ft_strequ(arg[0], "wc") ||
		ft_strequ(arg[0], "sort") ||
		ft_strequ(arg[0], "head"))
		ft_defult_term();
	if (!(ft_strequ(arg[0], "exit") ||
		ft_strequ(arg[0], "cd") ||
		ft_strequ(arg[0], "setenv") ||
		ft_strequ(arg[0], "unsetenv")))
		execve2(arg, env, path);
}

void		init_pipe(int *i, int start, int end, int ***fd)
{
	*i = start;
	*fd = (int **)ft_mema(sizeof(int *) * (end - start));
	while (*i < end)
	{
		(*fd)[*i - start] = (int *)ft_mema(sizeof(int) * 2);
		protected_pipe((*fd)[*i - start]);
		(*i)++;
	}
	*i = start;
}

void		dupnclose_pipe(int ***fd, int i, int start, int end)
{
	if (i > start)
		protected_dup2((*fd)[i - start - 1][0], 0);
	if (i < end)
		protected_dup2((*fd)[i - start][1], 1);
	close_all(fd, end - start);
}
