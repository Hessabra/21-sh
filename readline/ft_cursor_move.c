/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:24:54 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/10 14:43:45 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int		ft_deletemulti(t_read *insert)
{
	int	i;

	if (insert->tmplinex >= insert->winsize)
	{
		i = insert->winsize;
		insert->linex = insert->winsize - 1;
	}
	else
	{
		i = insert->tmplinex;
		insert->linex = insert->tmplinex;
	}
	return (i);
}

int		ft_formove(t_read *insert)
{
	int	i;

	i = ft_curlinelen(insert, insert->liney);
	if (i >= insert->winsize)
		insert->linex = insert->winsize - 1;
	else
		insert->linex = i;
	return (i);
}

int		ft_fornor(t_read *insert)
{
	int	i;

	insert->linex = 0;
	i = 0;
	return (i);
}

void	ft_movecursor_left(t_read *insert, char *buf)
{
	int i;

	i = 0;
	if (insert->index > 0)
	{
		if (!insert->liney || (insert->linex && insert->liney))
		{
			ft_do_termcap(CURSOR_LEFT);
			insert->linex--;
		}
		else if (insert->liney > 0 && insert->linex == 0)
		{
			insert->liney--;
			if ((insert->liney == 0 && insert->line[0] == '\n') || insert->a)
				ft_fornor(insert);
			else if (buf[0] == 127)
				i = ft_deletemulti(insert);
			else
				i = ft_formove(insert);
			ft_do_termcap(CURSOR_UP);
			while (i--)
				ft_do_termcap(CURSOR_RIGHT);
		}
		insert->index--;
	}
}

void	ft_movecursor_right(t_read *insert)
{
	if (insert->index < insert->linelen)
	{
		if (insert->linex < (insert->winsize - 1) &&
				insert->line[insert->index] != '\n')
		{
			ft_do_termcap(CURSOR_RIGHT);
			insert->linex++;
		}
		else
		{
			ft_do_termcap("cr");
			ft_do_termcap("sf");
			insert->linex = 0;
			insert->liney++;
		}
		insert->index++;
	}
}
