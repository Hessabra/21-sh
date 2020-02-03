/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:11 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 04:06:01 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			nbrope(char *str, int j)
{
	if (j == -1)
		return (3);
	if (j == -2)
		return (4);
	if (*str == '|')
		return (1);
	if (*str == ';')
		return (2);
	return (0);
}