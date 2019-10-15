/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_quotynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:03:31 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/15 17:05:48 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			add_quotynbr(t_quotis *last, t_quotis help)
{
	last->d += help.d;
	last->n += help.n;
	last->s += help.s;
}
