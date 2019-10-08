/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:31:52 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 02:57:18 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		unknown_cmd(char *cmd)
{
	ft_putstr_fd("Me : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("?! Sadly, I don't know this...\n", 2);
}

void		pipe_main(t_ppvr *a, t_racc4_p *rp, int **token, char **env)
{
	g_is_pipe = 0;
	a->x = rp->i;
	while (ft_entier(a->ppvr[a->x]) == 1 || a->ppvr[a->x] == -4)
		(a->x)++;
	dprintf(2, "start == %d end == %d ", rp->i, a->x);
	g_pid_cmd = fork();
	if (g_pid_cmd == 0)
	{
		mainpipe(rp, *a, env, token);
		wait(NULL);
		exit(0);
	}
	else
	{
		waitpid(g_pid_cmd, NULL, 0);
		rp->string_heredoc += ft_makesure(a->ppvr, token,
								rp->i, (a->x) + 1);
	}
	rp->i = a->x;
}

void		nexec_main(char **env, char *path, char **arg)
{
	g_pid_cmd = fork();
	if (g_pid_cmd == 0)
	{
		if (ft_strequ(arg[0], "cat") ||
				ft_strequ(arg[0], "wc"))
			ft_defult_term();
		if (!execve2(arg, env, path))
			exit(1);
	}
	else
		wait(NULL);
}
