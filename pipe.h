/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:23:48 by hessabra          #+#    #+#             */
/*   Updated: 2019/07/18 17:16:21 by hessabra         ###   ########.fr       */
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

int		pipey(int nbr_pipe, char ***arg, char **env);
void        pipe2(int *pp, int *ppp, char **env, t_pipe pi);

#endif