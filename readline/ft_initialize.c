/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:27:17 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/22 14:55:29 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_setterm(void)
{
	char	*termtype;
	char	term_buffer[2048];
	int		success;

	termtype = getenv("TERM");
	if (termtype == 0)
		ft_putstr("Specify a terminal type with `setenv TERM <yourtype>'.\n");
	success = tgetent(term_buffer, termtype);
	if (success < 0)
		ft_putstr("Could not access the termcap data base.\n");
	if (success == 0)
		ft_putstr("Terminal type `%s' is not defined.\n");
	ft_cannonical_mod();
}

void	ft_cannonical_mod(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		ft_putstr("Unable to set terminal");
}

void	ft_setting(t_read *insert)
{
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	insert->line = ft_memalloc(LINE_MAX);
	insert->topast = ft_memalloc(LINE_MAX);
	insert->winsize = ws.ws_col;
	insert->linex = 0;
	insert->liney = 0;
	insert->linelen = 0;
	insert->totaly = 0;
	insert->curlinelen = 0;
	insert->tmplinex = 0;
	insert->index = 0;
}
