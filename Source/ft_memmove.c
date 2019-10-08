/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:19:37 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:20:00 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*x;
	const char	*y;
	char		*z;
	size_t		i;

	x = (char *)dest;
	y = (const char *)src;
	i = 0;
	z = (char *)ft_memalloc(sizeof(char) * n);
	if (z == NULL)
		return (NULL);
	while (i < n)
	{
		z[i] = y[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		x[i] = z[i];
		i++;
	}
	free(z);
	return (x);
}
