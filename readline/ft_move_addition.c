/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:31:58 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/11 18:57:43 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_movecursor_next_word(t_read *insert)
{
	int i;

	i = insert->index;
	while (insert->line[i] && insert->line[i] == '\n')
	{
		ft_movecursor_right(insert);
		i++;
	}
	while (insert->line[i] && (insert->line[i]
	!= ' ' && insert->line[i] != '\n'))
	{
		ft_movecursor_right(insert);
		i++;
	}
	while (insert->line[i] && (insert->line[i] == ' '))
	{
		ft_movecursor_right(insert);
		i++;
	}
}

void	ft_movecursor_back_word(t_read *insert, char *key)
{
	int i;

	i = insert->index;
	if (insert->line[i] && (insert->line[i - 1] == ' '
	|| insert->line[i] == '\n'))
	{
		i--;
		ft_movecursor_left(insert, key);
	}
	while ((i > 0) && ((insert->line[i] == ' ' || insert->line[i] == '\0')))
	{
		ft_movecursor_left(insert, key);
		i--;
	}
	while ((i > 0) && (insert->line[i] != ' ' && insert->line[i] != '\n'))
	{
		ft_movecursor_left(insert, key);
		i--;
	}
	if (i > 0 && insert->line[i] == ' ')
		ft_movecursor_right(insert);
}

void	ft_movecursor_up(t_read *insert)
{
	int i;
	int j;
	int tmpx;
	int tmpy;

	if (insert->liney == 0)
	{
		ft_movestart(insert);
		return ;
	}
	tmpx = insert->linex;
	tmpy = insert->liney - 1;
	j = ft_curlinelen(insert, insert->liney) + 1;
	i = ft_curlinelen(insert, insert->liney - 1);
	ft_movestart(insert);
	while (insert->liney < tmpy)
		ft_movecursor_right(insert);
	if (j > i && tmpx > i)
		tmpx = i;
	while (tmpx--)
		ft_movecursor_right(insert);
}

void	ft_movecursor_down(t_read *insert)
{
	int i;
	int j;
	int tmpx;
	int tmpy;

	if (insert->liney == insert->totaly)
	{
		ft_moveend(insert);
		return ;
	}
	tmpx = insert->linex;
	tmpy = insert->liney + 1;
	j = ft_curlinelen(insert, insert->liney) + 1;
	i = ft_curlinelen(insert, insert->liney + 1);
	ft_movecursor_right(insert);
	while (insert->liney < tmpy)
		ft_movecursor_right(insert);
	if (j > i && tmpx > i)
		tmpx = i;
	while (tmpx--)
		ft_movecursor_right(insert);
}
