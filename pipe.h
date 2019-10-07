/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:23:48 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 22:33:53 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include "minishell.h"

typedef struct  s_pipe
{
	int         i;
	int         *ppvr;
	char        ***arg;
}               t_pipe;

void		close_all(int ***fd, int x);
void		protected_dup2(int fd1, int fd2);
void		protected_pipe(int *fd);
void		exec_pipe(char **arg, char **env);
void		init_pipe(int *i, int start, int end, int ***fd);
int		    pipey(int nbr_pipe, char ***arg, char **env);
void        pipe2(int *pp, int *ppp, char **env, t_pipe pi);
void		dupnclose_pipe(int ***fd, int i, int start, int end);

#endif
