/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:39:21 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:29:58 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	findingtimes(char *s)
{
	int		i;
	int		mark;
	int		result;

	mark = 1;
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 92)
		{
			mark = 1;
			i++;
		}
		if (mark == 1 && s[i] == 92)
		{
			result++;
			mark = 0;
		}
		i++;
	}
	return (result);
}

void		effectornot(int **n, char *s)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	j = 0;
	*n = (int *)ft_mema(sizeof(int) * (findingtimes(s) + 1));
	while (s[i])
	{
		while (s[i] && s[i] == 92 && (count++))
			i++;
		if (count)
		{
			if (!(count % 2))
				(*n)[j] = -1 * count;
			else
				(*n)[j] = count;
			j++;
			count = 0;
		}
		(s[i]) ? i++ : i;
	}
	(*n)[j] = 0;
}
