/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 04:13:42 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 05:15:19 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotyred.h"

void		alloc_args_2(t_alloc_args *aa, char **arg, int **token, int *bs)
{
	while (**arg && **arg < 33)
		(*arg)++;
	aa->nbr_ar = nbr_arg2(*arg, bs);
	*token = (int *)malloc(sizeof(int) * (aa->nbr_ar + 1));
	aa->i = 0;
}

void		alloc_args_3(t_alloc_args *aa, char **arg, int **token, int *bs)
{
	while (**arg && **arg < 33)
		(*arg)++;
	aa->len_ar = len_arg2(*arg, bs, aa->i, token);
}

int			alloc_args_4(t_alloc_args *aa, char *arg, char ***args, int **token)
{
	(*args)[aa->i] = (char *)malloc(sizeof(char) * (aa->len_ar + 1));
	if (aa->len_ar > 0 && (*arg == 34 || *arg == 39))
		(*args)[aa->i] = ft_strsub(arg, 1, aa->len_ar - 2);
	else
		(*args)[aa->i] = ft_strsub(arg, 0, ft_entier(aa->len_ar));
	if ((*token)[aa->i] == 1 && (aa->len_ar < 0 || *arg == 34 || *arg == 39))
		(*token)[aa->i] = 0;
	return (0);
}