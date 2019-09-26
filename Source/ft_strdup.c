/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:46:17 by helmanso          #+#    #+#             */
/*   Updated: 2018/10/17 12:46:56 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	return (ft_strcpy(str, src));
}
