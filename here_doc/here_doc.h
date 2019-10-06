/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 05:12:26 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 05:23:01 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H
# include "../minishell.h"

int			nbr_heredocppvr(int *token);
void		lastif_here_doc(int *fct, int *i, int *j, int *token);
void		init_here_doc(int *i, int *j, int *fct);

#endif