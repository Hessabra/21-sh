/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:54:41 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:06:52 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDI_H
# define CDI_H
# include "minishell.h"

void		envch(char ***env);
void		envech(char ***env, char *tmp);
int			erro(char *arg);

#endif
