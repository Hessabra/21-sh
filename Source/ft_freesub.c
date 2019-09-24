/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:57:19 by hessabra          #+#    #+#             */
/*   Updated: 2019/06/25 22:04:31 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_freesub(char *str, unsigned int start, size_t lenth)
{
	char    *new;

	new = ft_strsub(str, start, lenth);
	free(str);
	return (new);
}