/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:07:50 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 13:07:58 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!(substring = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
