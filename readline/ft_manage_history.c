/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:00:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/08 01:15:57 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_setting1(t_read *insert)
{
	insert->linex = 0;
	insert->liney = 0;
	insert->linelen = 0;
	insert->totaly = 0;
	insert->curlinelen = 0;
	insert->tmplinex = 0;
	insert->index = 0;
	ft_bzero(insert->line, LINE_MAX);
}

void	ft_clear_screen(t_read *insert)
{
	ft_remove_line(insert);
	ft_do_termcap(DELETE_AFTER_CURSOR);
	ft_setting1(insert);
}

void	ft_add_history(char *line, t_read *insert)
{
	char	*temp;
	int		i;

	i = 0;
	if (insert->history &&
	insert->indexfor_history == ft_tablen(insert->history)
	&& !ft_strcmp(line, ""))
		return ;
	if (insert->history &&
	insert->indexfor_history < ft_tablen(insert->history)
	&& !ft_strcmp(line, ""))
		insert->indexfor_history = ft_tablen(insert->history);
	else
	{
		temp = ft_strsub(line, 0, ft_strlen(line));
		insert->history = ft_addtotab(insert->history, temp);
		free(temp);
		insert->indexfor_history = ft_tablen(insert->history);
	}
}

void	ft_history_back(t_read *insert)
{
	if (!insert->history)
		return ;
	else
	{
		if (insert->indexfor_history > 0)
		{
			ft_clear_screen(insert);
			insert->indexfor_history--;
			ft_addtoline(insert->history[insert->indexfor_history], insert);
		}
	}
}

void	ft_history_forwad(t_read *insert)
{
	if (!insert->history)
		return ;
	else
	{
		if (insert->indexfor_history == ft_tablen(insert->history) - 1)
		{
			ft_clear_screen(insert);
			insert->indexfor_history++;
		}
		if (insert->indexfor_history < ft_tablen(insert->history))
		{
			ft_clear_screen(insert);
			insert->indexfor_history++;
			ft_addtoline(insert->history[insert->indexfor_history], insert);
		}
	}
}
