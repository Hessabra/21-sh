/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:11 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/18 13:39:33 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * "1" = pipe
 * "2" = point virgule
 * "3" = >
 * "4" = 2>
 * "5" = 2>&
 * "6" = >>
 * "7" = 2>>
 * "8" = <
 * "9" = <<
 */

int         nbrope(char *str, int j)
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