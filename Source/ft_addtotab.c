/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:15:24 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/22 16:17:29 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addtotab(char **table, char *line)
{
	char	**new;
	int		len;
	int		i;

	if (table)
		len = ft_lentab(table) + 1;
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
	free(table);
	return (new);
}
