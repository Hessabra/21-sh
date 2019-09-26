/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:12:40 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/26 15:25:45 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipe.h"
# define PIPE_OUT 0
# define PIPE_IN 1

void			close_all(int ***fd, int x)
{
	int			j;

	j = 0;
	while (j < x)
	{
		close((*fd)[j][0]);
		close((*fd)[j][1]);
		j++;
	}
}

void			mainpipe(t_ppvr a, char **env, int start, int **token)
{
	pid_t		exec_pid;
	int 		i;
	int			status;
	int			**fd;
	char		*path;

	path = NULL;
	i = start;
	
	fd = (int **)malloc(sizeof(int *) * a.x);

	a.x += start;

	while (i < a.x)
	{
		fd[i - start] = (int *)malloc(sizeof(int) * 2);
		if (pipe(fd[i - start]) < 0)
		{
			ft_putstr("fail to pipe");
			exit(0);
		}
		i++;
	}

	i = start;

	while (i <= a.x)
	{
		exec_pid = fork();
		if (exec_pid == 0)
		{
			if (i > start)
				if (dup2(fd[i - start - 1][PIPE_OUT], 0) < 0)
				{
					ft_putstr("fail to dup2\n");
					exit(0);
				}
			if (i == start || i + 1 <= a.x)
				if (dup2(fd[i - start][PIPE_IN], 1) < 0)
				{
					ft_putstr("fail to dup2\n");
					exit(0);
				}
			close_all(&fd, a.x);
			if (a.ppvr[i] == -4)
				usered(a.arg[i], token[i], &env);
			else
				if (!(ft_strequ(a.arg[i][0], "exit") || ft_strequ(a.arg[i][0], "cd") ||
					ft_strequ(a.arg[i][0], "setenv") || ft_strequ(a.arg[i][0], "unsetenv")))
						execve2(a.arg[i], env, path);
			exit(0);
		}
		else
			i++;
	}
	close_all(&fd, a.x);
	waitpid(exec_pid, &status, 0);
}