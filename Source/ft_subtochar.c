/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtochar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:09:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/04/30 01:36:51 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sub2char(char *str, int c)
{
	char		*bow;
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	bow = (char *)malloc(sizeof(char) * i + 1);
	if (bow == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		bow[i] = str[i];
		i++;
	}
	bow[i] = '\0';
	return (bow);
}
