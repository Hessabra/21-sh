/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:21:08 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/14 16:02:08 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_defult_term(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= (ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
}

void	prompt(void)
{
	ft_putstr("\e[35;1mWhat can I do for you ;) >>\n\e[0m");
}

char	*ft_readline(char *line, t_read *insert)
{
	char	key[BUFF_SIZE];
	int		ret;

	ft_setting(insert);
	g_insert = insert;
	ft_signal_handler(insert, g_insert);
	while (1)
	{
		ft_bzero(key, BUFF_SIZE);
		ft_syncwin_size(insert);
		if ((ret = read(0, &key, BUFF_SIZE)) == -1 ||
				(key[0] == ENTER_KEY && key[1] == 0) ||
				!ft_key_detect(key, insert))
		{
			ft_moveend(insert);
			line = ft_strdup(insert->line);
			ft_strdel(&insert->line);
			return (line);
		}
		insert->curlinelen = ft_curlinelen(insert, insert->liney);
	}
}
