/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:09:17 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/02 01:10:51 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addtotab(char **table, char *line)
{
	char	**new;
	int		len;
	int		i;

	if (table)
		len = ft_tablen(table) + 1;
	else
		len = 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	*(new + len) = 0;
	i = 0;
	while (table && *(table + i))
	{
		*(new + i) = *(table + i);
		i++;
	}
	*(new + i) = ft_strdup(line);
	return (new);
}
