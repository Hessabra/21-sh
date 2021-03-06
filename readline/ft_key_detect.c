/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/15 20:36:42 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int		ft_key_moves(char *key, t_read *insert)
{
	if (MOVE_RIGHT)
		ft_movecursor_right(insert);
	else if (MOVE_LEFT)
		ft_movecursor_left(insert, key);
	else if (MOVE_UP)
		ft_movecursor_up(insert);
	else if (MV_DWN)
		ft_movecursor_down(insert);
	else if (MOVE_START)
		ft_movestart(insert);
	else if (MOVE_END)
		ft_moveend(insert);
	else if (MV_NEXT)
		ft_movecursor_next_word(insert);
	else if (MV_BACK)
		ft_movecursor_back_word(insert, key);
	else
		return (0);
	return (1);
}

int		ft_keyfer_moves(char *key, t_read *insert)
{
	insert->curlinelen = ft_curlinelen(insert, insert->liney);
	if (COPY || COPY2 || COPY3)
		ft_copy(insert, key);
	if (CUT || CUT1 || CUT2)
		ft_cut(insert, key);
	else if (DELETE)
		ft_delete_char(insert, key);
	else if (DELETE_LINE)
		ft_clear_screen(insert);
	else if (key[0] == 4)
		ft_delete_onechar(insert);
	else if (PAST && insert->topast)
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

char	*check_char(char *key)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(key));
	i = 0;
	j = 0;
	while (key[i] != '\0')
	{
		if (key[i] != '\n' && !ft_isprint(key[i]))
			i++;
		else if (key[i - 1] == '[' && (key[i] == 'C' ||
		key[i] == 'D' || key[i] == 'A' || key[i] == 'D'))
			i++;
		else
			tmp[j++] = key[i];
		i++;
	}
	return (tmp);
}

int		ft_key_detect(char *key, t_read *insert)
{
	if (ft_isprint(key[0]) || key[0] == '\n')
	{
		key = check_char(key);
		ft_addtoline(key, insert);
		ft_strdel(&key);
		return (1);
	}
	else if (ft_keyfer_moves(key, insert))
		return (1);
	else if (ft_key_moves(key, insert))
		return (1);
	return (-1);
}
