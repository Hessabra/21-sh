/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:51:06 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/11 01:06:04 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	allocc(t_read *insert)
{
	if (insert->topast == NULL)
		insert->topast = ft_memalloc(LINE_MAX);
	else if (insert->topast)
	{
		ft_strdel(&insert->topast);
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

void	ft_cut1(t_read *insert)
{
	char *tmp;

	insert->topast = ft_strncpy(insert->topast,
	insert->line, insert->index);
	tmp = ft_strsub(insert->line, insert->index, ft_strlen(insert->line));
	ft_bzero(insert->line, LINE_MAX);
	insert->line = ft_strcpy(insert->line, tmp);
	insert->index = ft_strlen(insert->line);
	insert->linelen = ft_strlen(insert->line);
	ft_strdel(&tmp);
}

void	ft_cut11(t_read *insert)
{
	ft_cut1(insert);
	ft_remove_line(insert);
	ft_putstr(insert->line);
	insert->totaly = ft_totaly_count(insert);
	insert->liney = insert->totaly;
	insert->linex = ft_curlinelen(insert, insert->liney);
}

void	ft_cut(t_read *insert, char *key)
{
	allocc(insert);
	if (CUT)
	{
		insert->topast = ft_strncpy(insert->topast, insert->line +
		insert->index, insert->linelen - insert->index);
		ft_bzero(insert->line + insert->index, LINE_MAX - insert->index);
	}
	else if (CUT2)
	{
		insert->topast = ft_strncpy(insert->topast,
			insert->line, insert->linelen);
		ft_clear_screen(insert);
		return ;
	}
	else if (CUT1)
	{
		ft_cut11(insert);
		return ;
	}
	insert->linelen = ft_strlen(insert->line);
	ft_remove_line(insert);
	ft_putstr(insert->line);
	insert->totaly = ft_totaly_count(insert);
	ft_cursor_lastpos(insert);
}
