/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:22:02 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 02:25:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			***triplp(t_triplp *tp, int *bs, char **env, t_ppvr a)
{
	t_triplp2	tp2;
	int			lentab;
	char		***tabe;

	lentab = ft_tablen(tp->arg);
	tabe = (char ***)malloc(sizeof(char **) * (lentab + 1));
	tp2.i = -1;
	tp->token = (int **)ft_memalloc(sizeof(int *) * (lentab + 1));
	tp2.bs = bs;
	while (++(tp2.i) < lentab)
	{
		if (a.ppvr[tp2.i] == -2 || a.ppvr[tp2.i] == -3 || a.ppvr[tp2.i] == -4)
			tabe[tp2.i] = quotyred(tp, &tp2, env, a.nbr_quot);
		else
		{
			(tp->token)[tp2.i] = (int *)malloc(sizeof(int));
			(tp->token)[tp2.i][0] = -1;
			tabe[tp2.i] = quotyline((tp->arg)[tp2.i], &(tp2.bs), env,
			a.nbr_quot);
		}
	}
	(tp->token)[tp2.i] = NULL;
	tabe[tp2.i] = 0;
	dfre(tp->arg);
	return (tabe);
}
