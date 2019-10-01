/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocsuite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:26:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 00:32:08 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_makesure(int *ppvr, int **token, int start, int index_now)
{
	int			i;
	int			j;
	int			count;

	i = start;
	count = 0;
	while (i < index_now)
	{
		if (ppvr[i] < -1 && ppvr[i] > -5)
		{
			j = 0;
			while (token[i][j] > -1)
			{
				if (token[i][j] == 7)
					count++;
				j++;
			}
		}
		i++;
	}
	return (count);
}