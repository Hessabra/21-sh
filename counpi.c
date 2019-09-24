/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counpi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:21:45 by hessabra          #+#    #+#             */
/*   Updated: 2019/07/22 15:23:37 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         counpi(char **str)
{
    int     pi;
    int     i;
    int     x;

    i = 0;
    pi = 0;
    while (**str && (**str == ' ' || **str == 124 || **str == 38))
    {
        if (**str == '|')
        {
            pi++;
            x = i;
        }
        if ((pi && **str == 38) || (pi == 2 && x > 1))
        {
            ft_putstr("\nSyntax error near unexpected token `");
            ft_putchar(**str);
            ft_putstr("'\n");
            return (0);
        }
        if (pi > 1)
        {
            ft_putstr("\nLogical operator.. Not to it yet\n");
            return (0);
        }
        (*str)++;
        if (pi && **str == '\0')
        {
            ft_putstr("\nSyntax error near unexpected token `newline'\n");
            return (0);
        }
        i++;
    }
    return (1);
}