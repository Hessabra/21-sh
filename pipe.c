/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:12:40 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:25:21 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

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

void			mainpipe(t_racc4_p *rp, t_ppvr a, char **env, int **token)
{
	pid_t		exec_pid;
	int			i;
	int			status;
	int			**fd;

	getnresetfd(0);
	init_pipe(&i, rp->i, a.x, &fd);
	while (i <= a.x)
		if ((exec_pid = fork()) == 0)
		{
			dupnclose_pipe(&fd, i, rp->i, a.x);
			if (a.ppvr[i] == -4 || a.ppvr[i] == -3 || a.ppvr[i] == -2)
			{
				rp->string_heredoc += ft_makesure(a.ppvr, token, rp->i, i);
				usered(a.arg[i], token[i], &env, &(rp->string_heredoc));
			}
			else
				exec_pipe(a.arg[i], env);
			exit(0);
		}
		else
			i++;
	close_all(&fd, a.x - rp->i);
	getnresetfd(1);
	waitpid(exec_pid, &status, 0);
}
