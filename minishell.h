/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:08:30 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 03:55:41 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "readline/line_edit.h"
# include <unistd.h>
# include "Source/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# define PIPE_WRITE 1
# define PIPE_READ 0

typedef struct	s_dolore
{
	int			i;
	int			x;
	int			*stop;
}				t_dolore;

typedef struct	s_dolor
{
	int			i;
	int			x;
}				t_dolor;

typedef struct s_quotis
{
	int     s;
	int     d;
	int     n;

}				t_quotis;

typedef struct	s_ppvr
{
	char	***arg;
	int		*ppvr;
	int		x;
	t_quotis    nbr_quot;
}				t_ppvr;

int			len_arg2(char *arg, int *bs, int m, int **tok);
int			nbr_arg2(char *str, int *bs);
int			ft_makesure(int *ppvr, int **token, int start, int index_now);
int         *applyint(int **tabe, int x);
char        **quotyred(char *arg, int **bs, char **env, t_quotis nbr_quot, int **token);
int         *jointetoile(int *a, int *b);
int     	isint(char *str);
int         nbrope(char *str, int j);
char		*ft_readline(char *line, t_read *insert);
char		*ft_readlineh(char *line, t_read *insert, int fd);
int			nbr_arg(char *str, int *bs);
void		effectornot(int  **n, char *s);
void		dfre(char **tabe);
char		**aloc(char **env);
int			exi(char **arg, char ***env);
void		pidh(void);
int			synerr(char *str, int *bs);
char		*checking(char *command, char *env, int x);
int			ft_know(char **env, char *name);
int			ft_alnu(char *str);
char		**ft_tabjoin(char ***tabe, char *el);
void		stenv(char **arg, char ***env);
char		**unstenv(char **arg, char ***env);
int			ech(char **arg);
void		cdi(char **arg, char ***env);
void		mansig(int sig);
char		*dolor(char *arg, char **env);
char		*dolor1(char *s, char **env, int **bs, int quot);
char		*dolor2(char *s, char **env);
char		*line(char *arg, char **env, int **bs, int quot);
char        **quotyline(char *arg, int **bs, char **env, t_quotis nbr_quot);
char        *mixed(char *str, int **bs, char **env);
char		**ft_ppvr(char *str, int *bs, int **ppvr);
char        ***triplp(char **arg, int *bs, char **env, t_ppvr a, int ***token);
int         counpi(char **str);
int			execve2(char **arg, char **environ, char *path);
int			pipey(int nbr_pipe, char ***arg, char **env);
int			racco1(char **arg, char ***env);
int			racco3(char **arg, char ***env);
char		**use_heredoc(int *ppvr, int **token, char ***arg, char **env, t_read insert);
int         spaceornot(char *str);
char        *mixed2(char *str, int **bs, char **env);
void		mainpipe(t_ppvr a, char **env, int i, int **token, char ***string_heredoc);
int			quotiwhile(t_quotis last, char **arg, int **bs, t_read *insert);
void        getnresetfd(int i);
void        usered(char **args, int *token, char ***env, char ***string_heredoc);

#endif
