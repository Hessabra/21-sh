/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/26 15:55:49 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int	ft_key_moves(char *key, t_read *insert)
{
	if (MOVE_RIGHT)
		ft_movecursor_right(insert);
	else if (MOVE_LEFT)
		ft_movecursor_left(insert, key);
	else if (MOVE_UP)
		ft_movecursor_up(insert);
	else if (MOVE_DOWN)
		ft_movecursor_down(insert);
	else if (MOVE_START)
		ft_movestart(insert);
	else if (MOVE_END)
		ft_moveend(insert);
	else if (MOVE_NEXT_WORD)
		ft_movecursor_next_word(insert);
	else if (MOVE_BACK_WORD)
		ft_movecursor_back_word(insert, key);
	else
		return (0);
	return (1);
}

int	ft_keyfer_moves(char *key, t_read *insert)
{
	insert->curlinelen = ft_curlinelen(insert, insert->liney);
	if (COPY)
		ft_copy(insert);
	if (CUT)
		ft_cut(insert);
	else if (DELETE)
		ft_delete_char(insert, key);
	else if (key[0] == 4)
		ft_delete_onechar(insert);
	else if (PAST)
	{
		ft_addtoline(insert->topast, insert);
		insert->curlinelen = ft_curlinelen(insert, insert->liney);
	}
	else if (HISTORY_MOVE_NEXT)
		ft_history_forwad(insert);
	else if (HISTORY_MOVE_BACK)
		ft_history_back(insert);
	else
		return (0);
	return (1);
}

int	ft_key_detect(char *key, t_read *insert)
{
	if (ft_isprint(key[0]) || key[0] == '\n')
	{
		ft_addtoline(key, insert);
		//insert->curlinelen = ft_curlinelen(insert, insert->liney);
		return (1);
	}
	if (ft_keyfer_moves(key, insert))
		return (1);
	else if (ft_key_moves(key, insert))
		return (1);
	return (-1);
}
