/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:13:48 by hessabra          #+#    #+#             */
/*   Updated: 2019/07/02 19:32:14 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     nbr_arg(char *str, int *bs)
{
    int result;
    int marq;
    int j;
    int i;

    result = 0;
    i = -1;
    j = 0;
    marq = 1;
    while(str[j])
    {
        i = 1;
        if (str[j] == 92)
        {
            (*bs > 0) ? i = 0 : i;
            j += ft_entier(*bs);
            bs++;
        }
        if (str[j] == 39 || str[j] == 34)
        {
            if (marq == 1 && (str[j] == 39 || (str[j] == 34 && i)))
                marq = 0;
            else if (str[j] == 39 || (str[j] == 34 && i))
                marq = 1;
        }
        if (i && str[j] && (str[j] == ' ' && marq) && str[j + 1] && str[j + 1] > 32)
            result++;
        j++;
    }
    if (i != -1)
        result++;
    return (result);
}