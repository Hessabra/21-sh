/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:22:02 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/28 23:12:29 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        ***triplp(char **arg, int *bs, char **env, t_ppvr a, int ***token)
{
	int     i;
	int     lentab;
	char    ***tabe;

	lentab = ft_tablen(arg);
	tabe = (char ***)malloc(sizeof(char **) * (lentab + 1));
	i = 0;
	*token = (int **)ft_memalloc(sizeof(int *) * (lentab + 1));
	while (i < lentab)
	{
		if (a.ppvr[i] == -2 || a.ppvr[i] == -3 || a.ppvr[i] == -4)
			tabe[i] = quotyred(arg[i], &bs, env, a.nbr_quot, &(*token)[i]);
		else
		{
			(*token)[i] = (int *)malloc(sizeof(int));
			(*token)[i][0] = -1;
			tabe[i] = quotyline(arg[i], &bs, env, a.nbr_quot);
		}
		i++;
	}
	(*token)[i] = NULL;
	tabe[i] = 0;
	dfre(arg);
	return (tabe);
}
