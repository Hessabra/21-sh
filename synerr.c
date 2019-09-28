/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synerr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:31:07 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/27 18:30:06 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int        counred(char **str)
{
    int     in;
    int     out;
    int     i;
    int     x;

    i = 0;
    in = 0;
    out = 0;
    while (**str && (**str == ' ' || **str == '>' || **str == '<'))
    {
        if (**str == '>' || **str == '<')
            x = i;
        if (**str == '>')
            out++;
        else if (**str == '<')
            in++;
        if ((in && out) || ((in == 2 || out == 2) && x > 1) || in > 2 || out > 2)
        {
            ft_putstr_fd("\nSyntax error near unexpected token `", 2);
            ft_putchar_fd(**str, 2);
            ft_putstr_fd("'\n", 2);
            return (0);
        }
        (*str)++;
        if ((in || out) && **str == '\0')
        {
            ft_putstr_fd("\nSyntax error near unexpected token `newline'\n", 2);
            return (0);
        }
        if ((in || out) && (**str == ';' || **str == '|'))
        {
            ft_putstr_fd("\nSyntax error near unexpected token `", 2);
            ft_putchar_fd(**str, 2);
            ft_putstr_fd("'\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

static void        zaapi(char **str, int *bs, int *i, char c)
{
    (*str)++;
    while (**str && **str != c)
    {
        if (c != 39 && **str == 92)
        {
            *str += ft_entier(bs[*i]) - 1;
            (bs[*i] > 0) ? (*str)++ : *str;
            (*i)++;
        }
       (*str)++;
    }
}

int                synerr(char *str, int *bs)
{
    int     i;

    i = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    if (*str == '|' || *str == ';')
    {
        ft_putstr_fd("\nSyntax error near unexpected token `", 2);
        ft_putchar_fd(*str, 2);
        ft_putstr_fd("'\n", 2);
        return (0);
    }
    while (*str)
    {
        if (*str == 59)
        {
            str++;
            while (*str == ' ' || *str == '\t' || *str == '\n')
                str++;
            if (*str == '>' || *str == '<' || *str == '|')
            {
                ft_putstr_fd("\nSyntax error near unexpected token `", 2);
                ft_putchar_fd(*str, 2);
                ft_putstr_fd("'\n", 2);
                return (0);
            }
        }
        if (*str == '|' && !counpi(&str))
            return (0);
        if ((*str == '>' || *str == '<') && !counred(&str))
            return (0);
        if (*(str + 1) && (*str == 34 || *str == 39))
            zaapi(&str, bs, &i, *str);
        if (*str == 92)
        {
            str += ft_entier(bs[i]) - 1;
            (bs[i] > 0) ? str++: str;
            i++;
        }
        str++;
    }
    return (1);
}   