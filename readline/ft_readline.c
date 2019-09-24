/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:21:08 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 16:17:58 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

char	*ft_readline(char *line, t_read *insert)
{
	char	key[BUFF_SIZE];
	int		ret;

	ft_setting(insert);
	while (1)
	{
		ft_bzero(key, BUFF_SIZE);
		if ((ret = read(0, &key, BUFF_SIZE)) == -1 ||
				key[0] == ENTER_KEY || !ft_key_detect(key, insert))
		{
			line = ft_strdup(insert->line);
			ft_strdel(&insert->line);
			ft_strdel(&insert->topast);
			return (line);
		}
	}
}
