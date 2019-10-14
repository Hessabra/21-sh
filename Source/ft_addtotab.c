/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:09:17 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/11 23:36:04 by helmanso         ###   ########.fr       */
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
	new = (char**)ft_mema(sizeof(char*) * (len + 1));
	*(new + len) = 0;
	i = 0;
	while (table && *(table + i))
	{
		*(new + i) = ft_strdup(*(table + i));
		i++;
	}
	*(new + i) = ft_strdup(line);
	return (new);
}
