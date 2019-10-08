/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:44:57 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:29:58 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		allocatequote_2(char ***args, int i, int len_ar, char *arg)
{
	(*args)[i] = (char *)ft_mema(sizeof(char) * (len_ar + 1));
	if (len_ar > 0 && (*arg == 34 || *arg == 39))
		(*args)[i] = ft_strsub(arg, 1, len_ar - 2);
	else
		(*args)[i] = ft_strsub(arg, 0, ft_entier(len_ar));
}

void		allocatequote_3(char **arg, int *len_ar, int *bs, int i)
{
	while (**arg && **arg < 33)
		(*arg)++;
	*len_ar = lenthargs_4(*arg, bs, i);
}

void		allocatequote_4(char **arg, int *nbr_ar, int *bs, int *i)
{
	while (**arg && **arg < 33)
		arg++;
	*nbr_ar = nbr_arg(*arg, bs);
	*i = 0;
}
