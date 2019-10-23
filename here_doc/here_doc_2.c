/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 05:12:07 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 05:20:21 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

void		lastif_here_doc(int *fct, int *i, int *j, int *token)
{
	if (*fct == nbr_heredocppvr(token))
	{
		*fct = 0;
		(*j)++;
	}
	(*i)++;
}

void		init_here_doc(int *i, int *j, int *fct)
{
	*i = 0;
	*j = 0;
	*fct = 0;
}
