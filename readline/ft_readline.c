/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:21:08 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/26 16:00:43 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void    ft_printdetails(t_read *insert)
{

	insert->info = open("/dev/ttys004", O_RDWR);
	ft_putstr_fd("insert->x-> ", insert->info);
	ft_putnbr_fd(insert->linex, insert->info);
	ft_putstr_fd("insert->y-> ", insert->info);
	ft_putnbr_fd(insert->liney, insert->info);
	ft_putstr_fd("insert->curlen ", insert->info);
	ft_putnbr_fd(insert->curlinelen, insert->info);
	ft_putstr_fd("insert->winsize ", insert->info);
	ft_putnbr_fd(insert->winsize, insert->info);
	ft_putchar_fd('\n', insert->info);
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
		ft_printdetails(insert);
		if ((ret = read(0, &key, BUFF_SIZE)) == -1 ||
				(key[0] == ENTER_KEY && key[1] == 0) || !ft_key_detect(key, insert))
		{
			ft_moveend(insert);
			line = ft_strdup(insert->line);
			ft_strdel(&insert->line);
			ft_strdel(&insert->topast);
			return (line);
		}
		insert->curlinelen = ft_curlinelen(insert, insert->liney);

	}


}

/*int		main(void)
{
	t_read	insert;
	char	*line;

	ft_setterm();
	line = ft_strnew(0);
	while (1)
	{
		ft_putstr("AYAYAYYAYAYAYAY -->\n");
		line = ft_readline(line, &insert);
		if (!ft_strcmp(line, "exit"))
		{
			ft_strdel(&line);
			break;
		}
		ft_add_history(line, &insert);
		ft_putchar('\n');
		ft_strdel(&line);
	}
}*/
