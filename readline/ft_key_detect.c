/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 14:55:36 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int	ft_key_moves(char *key, t_read *insert)
{
	if (MOVE_RIGHT)
		ft_movecursor_right(insert, key);
	else if (MOVE_LEFT)
		ft_movecursor_left(insert, key);
	else if (MOVE_UP)
		ft_movecursor_up(insert, key);
	else if (MOVE_DOWN)
		ft_movecursor_down(insert, key);
	else if (MOVE_START)
		ft_movestart(insert, key);
	else if (MOVE_END)
		ft_moveend(insert, key);
	else if (MOVE_NEXT_WORD)
		ft_movecursor_next_word(insert, key);
	else if (MOVE_BACK_WORD)
		ft_movecursor_back_word(insert, key);
	else
		return (0);
	return (1);
}

int	ft_keyfer_moves(char *key, t_read *insert)
{
	if (COPY)
		ft_copy(insert, key);
	else if (CUT)
		ft_cut(insert, key);
	else if (DELETE)
		ft_delete_char(insert, key);
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
	if (ft_keyfer_moves(key, insert))
		return (1);
	else if (ft_key_moves(key, insert))
		return (1);
	else if (ft_isprint(key[0]))
	{
		ft_addtoline(key, insert);
		insert->curlinelen = ft_curlinelen(insert, insert->liney);
		return (1);
	}
	return (-1);
}
