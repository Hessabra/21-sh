/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:57:21 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/30 03:15:18 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  lenpart(char *str, int **bs)
{
    int     i;

    i = 0;
    if (str[i] != 34 && str[i] != 39)
    {
        while (str[i] && str[i] != 34 && str[i] != 39)
        {
            if (str[i] == 92)
            {
                i += ft_entier(**bs);
                (**bs > 0) ? i++ : i;
                (*bs)++;
            }
            else
                i++;
        }
    }
    else if (str[i] == 39)
    {
        i++;
        while (str[i] && str[i] != 39)
            i++;
        i++;
    }
    else
    {
        i++;
        while (str[i] && str[i] != 34)
        {
            if (str[i] == 92)
            {
                i += ft_entier(**bs);
                (**bs > 0) ? i++ : i;
                (*bs)++;
            }
            else
                i++;
        }
            i++;
    }
    return (i);
}

static int  nbrparts(char *str, int *bs)
{
    int     res;
    int     i;

    res = 0;
    while ((i = lenpart(str, &bs)))
    {
        res++;
        str += i;
    }
    return (res);
}

static void splity(char *str, char ***tmp, int **bs, char **env)
{
    int     quot;
    int     i;
    int     rem2;
    int     rem;
    int     *bs2;
    
    i = 0;
    bs2 = *bs;
    while ((rem = lenpart(str, &bs2)))
    {
        rem2 = rem;
        (*str == 39 || *str == 34) ? rem -= 2 : rem;
        quot = 0;
        (*str == 39) ? quot = 1 : quot;
        (*str == 34) ? quot = 2 : quot;
        if (quot == 0)
        {
            (*tmp)[i] = ft_strsub(str, 0, rem);   
        }
        else
        {
            (*tmp)[i] = ft_strsub(str, 1, rem);
        }
        (*tmp)[i] = line((*tmp)[i], env, bs, quot);
        i++;
        str += rem2;
    }
}

char        *mixed(char *str, int **bs, char **env)
{
    char    *new;
    char    **tmp;
    int     i;
    int     nbr_pa;
    
    nbr_pa = nbrparts(str, *bs);
    tmp = (char **)malloc(sizeof(char *) * (nbr_pa + 1));
    splity(str, &tmp, bs, env);
    tmp[nbr_pa] = NULL;
    new = ft_strdup("");
    i = 0;
    while (tmp[i])
    {
        new = ft_jandf(new, tmp[i], 1, 1);
        i++;
    }
    //free error ''''''>''''
    //    free(tmp);
    return (new);
}
