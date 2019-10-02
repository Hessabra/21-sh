/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:07:51 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 04:06:54 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	makesure(int *tabe, int x)
{
	int		i;

	i = 0;
	while (tabe[i] != -1)
	{
		if (tabe[i] == x)
			return (0);
		i++;
	}
	return (1);
}

static int	lentabint(int *tabe)
{
	int		i;

	i = 0;
	while (tabe[i] != -1)
		i++;
	return (i);
}

static int	*newinttab(int **tabe, int x)
{
	int		i;
	int		new_len;
	int		*new;

	new_len = lentabint(*tabe);
	new = (int *)malloc(sizeof(int) * (new_len + 2));
	i = 0;
	while (i < new_len)
	{
		new[i] = (*tabe)[i];
		i++;
	}
	new[i] = x;
	i++;
	new[i] = -1;
	free(*tabe);
	return (new);
}

int			*applyint(int **tabe, int x)
{
	int		*new;

	if (makesure(*tabe, x))
		new = newinttab(tabe, x);
	else
		return (*tabe);
	return (new);
}
