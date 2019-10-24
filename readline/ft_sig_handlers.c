/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/14 16:03:39 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_signal_handler(t_read *insert, t_read *g_insert)
{
	g_insert = insert;
	g_insert->index = insert->index;
	ft_cannonical_mod();
	signal(SIGINT, sigint_handler);
	signal(SIGWINCH, sigwinch_handler);
}

void	sigwinch_handler(int sig)
{
	char	*tmp;
	char	*key;

	key = 0;
	tmp = ft_strdup(g_insert->line);
	ft_clear_screen(g_insert);
	ft_syncwin_size(g_insert);
	ft_addtoline(tmp, g_insert);
	ft_strdel(&tmp);
	(void)sig;
}

void	sigint_handler(int sig)
{
	if (g_pid_cmd != 0 && g_is_pipe)
		ft_putchar('\n');
	else if (g_herdoc_sig == 1 && g_is_pipe)
	{
		g_herdoc_sig = 0;
		ioctl(0, TIOCSTI, "\12");
	}
	else
	{
		ft_remove_line(g_insert);
		ft_do_termcap(DELETE_AFTER_CURSOR);
		g_insert->linex = 0;
		g_insert->liney = 0;
		g_insert->linelen = 0;
		g_insert->totaly = 0;
		g_insert->curlinelen = 0;
		g_insert->tmplinex = 0;
		g_insert->index = 0;
		(void)sig;
		if (g_insert->history)
			g_insert->indexfor_history = ft_tablen(g_insert->history);
	}
}
