/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usetoken_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:31:20 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 00:34:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usetoken.h"

static void	fill_usetok(t_usetok *u, int **token, char **args, int cas)
{
	if (cas == 0)
	{
		u->i = 0;
		u->k.i = 0;
		u->k.x = 0;
		u->error = 0;
		u->cmd = usetoken(args, token);
		u->new = NULL;
	}
	else if (cas == 1)
	{
		u->fd = 1;
		zappi(*token, &(u->i));
		((*token)[u->i] >= 6 && (*token)[u->i] <= 8) ? (u->fd = 0) : u->fd;
		if ((*token)[u->i] == 9)
		{
			u->fd = ft_atoi(args[u->i]);
			(u->i)++;
		}
	}
}

static int	exec_usetoken_1(t_usetok u, char ***env)
{
	if (ft_strequ(u.cmd[0], "cat") || ft_strequ(u.cmd[0], "wc") ||
			ft_strequ(u.cmd[0], "sort"))
		ft_defult_term();
	if ((ft_strequ(u.cmd[0], "exit") || ft_strequ(u.cmd[0], "cd") ||
			ft_strequ(u.cmd[0], "setenv") || ft_strequ(u.cmd[0], "unsetenv"))
			&& racco1(u.cmd, env))
	{
		racco3(u.cmd, env);
		return (0);
	}
	return (1);
}

static void	exec_usetoken_2(t_usetok u, char **env)
{
	if (u.new)
		if (pipe(u.fd_p) < 0)
		{
			ft_putstr_fd("\nOoupsy pipe c \n", 2);
			// exit(1);
		}
	if ((u.pid_fork = fork()) == 0)
	{
		if (u.new)
		{
			close((u.fd_p)[PIPE_WRITE]);
			close(0);
			dup2((u.fd_p)[PIPE_READ], 0);
		}
		u.path = NULL;
		execve2(u.cmd, env, u.path);
		exit(0);
	}
	else
	{
		close((u.fd_p)[PIPE_READ]);
		ft_putstr_fd(u.new, (u.fd_p)[PIPE_WRITE]);
		close((u.fd_p)[PIPE_WRITE]);
		waitpid(u.pid_fork, NULL, 0);
	}
}

void		usered(char **args, int *token, char ***env, char ***string_heredoc)
{
	t_usetok	u;

	getnresetfd(0);
	fill_usetok(&u, &token, args, 0);
	while (args[u.i])
	{
		fill_usetok(&u, &token, args, 1);
		elif_usetoken(&u, token, args, string_heredoc);
		(u.i)++;
	}
	if (!u.error && u.cmd != NULL && exec_usetoken_1(u, env))
		exec_usetoken_2(u, *env);
	getnresetfd(1);
}
