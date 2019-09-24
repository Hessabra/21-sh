/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlineh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:43:37 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/24 13:44:07 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

char	*ft_readlineh(char *line, t_read *insert, int fd)
{
	char	key[BUFF_SIZE];
	int		ret;

	ft_setting(insert);
	while (1)
	{
		ft_bzero(key, BUFF_SIZE);
		if ((ret = read(fd, &key, BUFF_SIZE)) == -1 ||
				key[0] == ENTER_KEY || !ft_key_detect(key, insert))
		{
			line = ft_strdup(insert->line);
			ft_strdel(&insert->line);
			ft_strdel(&insert->topast);
			return (line);
		}
	}
}