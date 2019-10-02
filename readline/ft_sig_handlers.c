/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/02 02:35:44 by helmanso         ###   ########.fr       */
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
	int		tmpindex;
	char	*key;

	key = 0;
	tmpindex = g_insert->index;
	tmp = ft_strdup(g_insert->line);
	ft_clear_screen(g_insert);
	ft_syncwin_size(g_insert);
	ft_addtoline(tmp, g_insert);
	(void)sig;
}

void	sigint_handler(int sig)
{
	if (g_insert->is_quote == 1)
	{
		g_insert->is_quote = -1;
		ioctl(0, TIOCSTI, "\12");
		ft_putchar('\n');
		return ;
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
		prompt();
	}
	(void)sig;
	if (g_insert->history)
		g_insert->indexfor_history = ft_tablen(g_insert->history);
}
