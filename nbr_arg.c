/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:13:48 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 22:32:40 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	racc(int marq, char str, int i)
{
	if (marq == 1 && (str == 39 || (str == 34 && i)))
		return (0);
	if (str == 39 || (str == 34 && i))
		return (1);
	return (marq);
}

int			nbr_arg(char *str, int *bs)
{
	int		result;
	int		marq;
	int		j;
	int		i;

	result = 0;
	i = -1;
	j = 0;
	marq = 1;
	while (str[j] && (i = 1))
	{
		if (str[j] == 92)
		{
			(*bs > 0) ? i = 0 : i;
			j += ft_entier(*bs);
			bs++;
		}
		if (str[j] == 39 || str[j] == 34)
			marq = racc(marq, str[j], i);
		(i && str[j] && (str[j] == ' ' && marq) && str[j + 1] &&
				str[j + 1] > 32) ? result++ : result;
		j++;
	}
	(i != -1) ? result++ : result;
	return (result);
}
