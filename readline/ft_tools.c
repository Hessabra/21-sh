/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:09:23 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/26 15:57:06 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int		ft_curlinelen(t_read *insert, int liney)
{
	int x;
	int y;
	int index;

	x = 0;
	y = 0;
	index = 0;
	while (index < insert->linelen)
	{
		x++;
		if (insert->line[index] == '\n' || x == insert->winsize)
		{
			x = 0;
			y++;
		}
		if (y == liney)
		{
			while (++index < insert->linelen && insert->line[index] != '\n')
				x++;
			return (insert->curlinelen = x);
		}
		index++;
	}
	return (insert->curlinelen = x);
}

int		countbigy(char *buf)
{
	int i;

	i = 0;
	while (*buf++)
	{
		if (*buf == '\n')
			i++;
	}
	return (i);
}

int		ft_totaly_count(t_read *insert)
{
	int index;
	int x;
	int y;

	index = 1;
	x = 0;
	y = 0;
	if (insert->linelen == 0)
		return (0);
/*	if (insert->line[0] == '\n')
		ft_do_termcap(CURSOR_UP);*/
	while (index != insert->linelen)
	{
		x++;
		if (insert->line[index] == '\n')
			x = -1;
		else if (x == insert->winsize)
		{
			y++;
			x = 0;
		}
		index++;
	}
	y += countbigy(insert->line);
	return (y);
}

int		h_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_do_termcap(char *termcap)
{
	tputs(tgetstr(termcap, NULL), 1, &h_putchar);
}
