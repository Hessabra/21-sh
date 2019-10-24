/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:22:02 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/11 00:52:52 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			***triplp(t_triplp *tp, int *bs, char **env, t_ppvr a)
{
	t_triplp2	tp2;
	int			lentab;
	char		***tabe;

	dprintf(2, "hi1\b");
	lentab = ft_tablen(tp->arg);
	dprintf(2, "hi%d\b", lentab);
	tabe = (char ***)ft_mema(sizeof(char **) * (lentab + 1));
	tp2.i = -1;
	tp->token = (int **)ft_mema(sizeof(int *) * (lentab + 1));
	tp2.bs = bs;
	while (++(tp2.i) < lentab)
	{
		dprintf(2,"hello");
		if (a.ppvr[tp2.i] == -2 || a.ppvr[tp2.i] == -3 || a.ppvr[tp2.i] == -4)
			tabe[tp2.i] = quotyred(tp, &tp2, env, a.nbr_quot);
		else
		{
			(tp->token)[tp2.i] = (int *)ft_mema(sizeof(int));
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
