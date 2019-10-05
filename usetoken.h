/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usetoken.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:20:03 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 00:19:49 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USETOKEN_H
# define USETOKEN_H
# include "minishell.h"

typedef struct	s_usetok
{
	int			fd;
	int			fdw;
	int			i;
	int			error;
	int			fd_p[2];
	pid_t		pid_fork;
	char		*path;
	char		**cmd;
	char		*new;
	t_dolore	k;
}				t_usetok;

int				cmdcl(char **args, int *token, int c);
void			chack(char **args, int **token);
void			zappi(int *token, int *i);
char			**usetoken(char **args, int **token);
int				checkfd(int fd, char *amb, int x);
void            elif_usetoken(t_usetok *u, int *token, char **args,
		char ***string_heredoc);

#endif
