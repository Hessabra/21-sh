/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:22:02 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/23 19:06:30 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char        ***triplp(char **arg, int *bs, char **env, t_ppvr a, int ***token)
{
    int     i;
    int     lentab;
    char    ***tabe;

    lentab = ft_lentab(arg);   
    tabe = (char ***)malloc(sizeof(char **) * (lentab + 1));
    i = 0;
    *token = (int **)malloc(sizeof(int *) * (lentab + 1));
    while (i < lentab)
    {
        if (a.ppvr[i] == -1 || a.ppvr[i] == -2 || a.ppvr[i] == -3)
            tabe[i] = quotyred(arg[i], &bs, env, a.nbr_quot, token[i]);
        else
        {
            (*token)[i] = NULL;
            tabe[i] = quotyline(arg[i], &bs, env, a.nbr_quot);
        }
        i++;
    }
    tabe[i] = 0;
    dfre(arg);
    return (tabe);
}