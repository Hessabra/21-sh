/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:30:18 by helmanso          #+#    #+#             */
/*   Updated: 2019/01/14 12:44:28 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_freetab(char ***table)
{
    char **temp;

    if (!table || !*table)
        return ;
    temp = *table;
    while (*temp)
        ft_strdel(&(*temp++));
    free(*table);
    *table = NULL;
}