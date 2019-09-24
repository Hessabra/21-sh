/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:00:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 17:47:29 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_clear_screen(t_read *insert)
{
	ft_remove_line(insert);
	ft_do_termcap(DELETE_AFTER_CURSOR);
	ft_setting(insert);
}

void	ft_add_history(char *line, t_read *insert)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strsub(line, 0, ft_strlen(line));
	insert->history = ft_addtotab(insert->history, temp);
	free(temp);
	insert->indexfor_history = ft_tablen(insert->history);
}

void	ft_history_back(t_read *insert)
{
	if (!insert->history)
		return ;
	else
	{
		if (insert->indexfor_history > 1)
		{
			ft_clear_screen(insert);
			ft_addtoline(insert->history[insert->indexfor_history - 1], insert);
			insert->indexfor_history--;
		}
	}
}

void	ft_history_forwad(t_read *insert)
{
	if (!insert->history)
		return ;
	else
	{
		if (insert->indexfor_history < ft_lentab(insert->history) - 1)
		{
			ft_clear_screen(insert);
			insert->indexfor_history++;
			ft_addtoline(insert->history[insert->indexfor_history], insert);
		}
	}
}
