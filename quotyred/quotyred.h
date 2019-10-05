/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 01:06:52 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 19:06:22 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTYRED_H
# define QUOTYRED_H
# include "../minishell.h"

typedef struct		s_len_arg
{
	int             i;
	int             j;
	int             hd;
	int             mixed;
}					t_len_arg;

typedef struct		s_nbr_arg
{
	int             result;
	int             marq;
	int             j;
	int             i;
}					t_nbr_arg;

typedef struct		s_alloc_args
{
	int				i;
	int				len_ar;
	int				nbr_ar;
}					t_alloc_args;

void				zaapi(char *str, int *i, int **bs, char c);
void				zaapin(char *str, int *i, int **bs);
void				alloc_args_2(t_alloc_args *aa, char **arg, int **token,
					int *bs);
void				alloc_args_3(t_alloc_args *aa, char **arg, int **token,
					int *bs);
int					alloc_args_4(t_alloc_args *aa, char *arg, char ***args,
					int **token);
int					len_arg2(char *arg, int *bs, int m, int **tok);
int					nbr_arg2(char *str, int *bs);

#endif
