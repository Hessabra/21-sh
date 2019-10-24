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

static int	racc(int marq, char str)
{
	if (marq == 0 && str == 39)
		return (1);
	if (marq == 0 && str == 34)
		return (2);
	if (str == 39 || str == 34)
		return (0);
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
	marq = 0;
	while (str[j] && (i = 1))
	{
		if (marq != 1 && str[j] == 92)
		{
			(*bs > 0) ? j++ : 1;
			j += ft_entier(*bs);
			bs++;
		}
		if (str[j] == 39 || str[j] == 34)
			marq = racc(marq, str[j]);
		(!marq && str[j] && str[j] < 33 && str[j + 1] &&
				str[j + 1] > 32) ? result++ : result;
		j++;
	}
	(i != -1) ? result++ : result;
	return (result);
}
