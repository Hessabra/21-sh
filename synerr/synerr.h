/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synerr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 05:48:12 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 06:22:37 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNERR_H
# define SYNERR_H
# include "../minishell.h"

int			counred_2(int in, int out, int x, char c);
int			counred_3(int in, int out, char c);
int			synerr_2(char **str);
int			synerr_3(char **str);

#endif
