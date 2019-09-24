/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:58:28 by hessabra          #+#    #+#             */
/*   Updated: 2018/10/18 20:57:33 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*bow;
	size_t	i;

	if (s == NULL)
		return (NULL);
	bow = (char *)malloc(sizeof(char) * (len + 1));
	if (bow == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		bow[i] = s[start];
		i++;
		start++;
	}
	bow[i] = '\0';
	return (bow);
}
