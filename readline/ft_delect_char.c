/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delect_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:27:58 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 14:55:22 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_remove_fromline(t_read *insert)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(insert->line, 0, insert->index - 1);
	tmp2 = ft_strsub(insert->line, insert->index,
			insert->linelen - ft_strlen(tmp));
	ft_bzero(insert->line, 4096);
	insert->line = ft_strcpy(insert->line, tmp);
	insert->line = ft_strcat(insert->line, tmp2);
	free(tmp);
	free(tmp2);
}

void	ft_delete_char(t_read *insert, char *buf)
{
	if (insert->index > 0)
	{
		if (insert->linex == 0)
			insert->tmplinex = ft_curlinelen(insert, insert->liney - 1);
		ft_remove_line(insert);
		ft_remove_fromline(insert);
		ft_putstr(insert->line);
		insert->linelen--;
		insert->totaly = ft_totaly_count(insert);
		ft_cursor_lastpos(insert);
		ft_movecursor_left(insert, buf);
	}
}
