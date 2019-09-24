/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:51:06 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 14:55:08 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_copy(t_read *insert, char *buf)
{
	ft_bzero(insert->topast, 4096);
	if (buf[0] == 11)
		insert->topast = ft_strncpy(insert->topast, insert->line +
				insert->index, insert->linelen - insert->index);
}

void	ft_cut(t_read *insert, char *buf)
{
	int i;

	ft_bzero(insert->topast, 4096);
	insert->topast = ft_strncpy(insert->topast, insert->line + insert->index,
			insert->linelen - insert->index);
	ft_bzero(insert->line + insert->index, 4096 - insert->index);
	insert->linelen = ft_strlen(insert->line);
	ft_remove_line(insert);
	ft_putstr(insert->line);
	insert->totaly = ft_totaly_count(insert);
	ft_cursor_lastpos(insert);
}
