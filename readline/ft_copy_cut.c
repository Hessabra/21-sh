/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:51:06 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/10 20:51:55 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	allocc(t_read *insert)
{
	if (insert->topast == NULL)
		insert->topast = ft_memalloc(LINE_MAX);
	else if (insert->topast)
	{
		ft_strdel(&(insert->topast));
		insert->topast = ft_memalloc(LINE_MAX);
	}
}

void	ft_copy(t_read *insert, char *key)
{
	allocc(insert);
	if (COPY)
		insert->topast = ft_strncpy(insert->topast,
		insert->line, insert->index);
	else if (COPY2)
		insert->topast = ft_strncpy(insert->topast, insert->line +
		insert->index, insert->linelen - insert->index);
	else if (COPY3)
		insert->topast = ft_strcpy(insert->topast, insert->line);
}

void	ft_cut(t_read *insert)
{
	allocc(insert);
	insert->topast = ft_strncpy(insert->topast, insert->line + insert->index,
			insert->linelen - insert->index);
	ft_bzero(insert->line + insert->index, 4096 - insert->index);
	insert->linelen = ft_strlen(insert->line);
	ft_remove_line(insert);
	ft_putstr(insert->line);
	insert->totaly = ft_totaly_count(insert);
	ft_cursor_lastpos(insert);
}
