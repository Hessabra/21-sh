/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:03:36 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 01:06:35 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOLO_H
# define DOLO_H
# include "../minishell.h"

int		condition_dolo(int quot, int bs, char *s, t_dolor t);
void	lastelse_dolo(char **fin, char *s, t_dolor *t);
void	replace_dolo(int *backslash, int markdown, char **fin);
void	initi_dolo(char **fin, int *i, int *backslash);
void	intent_dolo(int *i, int **bs, int *backslash, char *s);

#endif
