/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:51:44 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/10 20:39:18 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_cursor_lastpos(t_read *insert)
{
	int	yline;
	int	i;

	yline = insert->totaly;
	if (!((insert->curlinelen + 1) % insert->winsize))
		insert->totaly++;
	while (yline--)
		ft_do_termcap(CURSOR_UP);
	ft_do_termcap(CURSOR_CORNER);
	i = 0;
	while (i++ < insert->liney)
		ft_do_termcap(CURSOR_DOWN);
	i = 0;
	while (i++ < insert->linex)
		ft_do_termcap(CURSOR_RIGHT);
}

void	ft_remove_line(t_read *insert)
{
	int	i;

	i = insert->liney;
	if (i)
		while (i--)
			ft_do_termcap(CURSOR_UP);
	ft_do_termcap(CURSOR_CORNER);
	ft_do_termcap(DELETE_AFTER_CURSOR);
}

char	*ft_addinput(char *buf, t_read *insert)
{
	char	*tmpline;

	tmpline = ft_strsub(insert->line, insert->index,
			insert->linelen - insert->index);
	ft_bzero(insert->line + insert->index, LINE_MAX - insert->index);
	insert->line = ft_strcat(insert->line, buf);
	insert->line = ft_strcat(insert->line, tmpline);
	ft_strdel(&tmpline);
	return (insert->line);
}

void	ft_addtoline(char *buf, t_read *insert)
{
	int		i;

	i = ft_strlen(buf);
	ft_remove_line(insert);
	insert->line = ft_addinput(buf, insert);
	ft_putstr(insert->line);
	insert->linelen += i;
	insert->totaly = ft_totaly_count(insert);
	ft_cursor_lastpos(insert);
	while (i--)
		ft_movecursor_right(insert);
}
