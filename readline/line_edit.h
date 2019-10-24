/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:14:45 by helmanso          #+#    #+#             */
/*   Updated: 2019/10/14 15:59:28 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LINE_EDIT_H
# define _LINE_EDIT_H

# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/wait.h>
# include <ctype.h>
# include <termcap.h>
# include <fcntl.h>
# include "../Source/libft.h"
# define BUFF_SIZE 4000
# define LINE_MAX  200000
# define ENTER_KEY 10
# define MOVE_RIGHT (key[2] == 67 && key[1] == 91 && key[0] == 27)
# define MOVE_LEFT (key[2] == 68 && key[1] == 91 && key[0] == 27)
# define MOVE_UP (key[3] == 65 && key[2] == 91 && key[1] == 27 && key[0] == 27)
# define MV_DWN (key[3] == 66 && key[2] == 91 && key[1] == 27 &&  key[0] == 27)
# define MOVE_START (key[2] == 72 && key[1] == 91 && key[0] == 27)
# define MOVE_END (key[2] == 70 && key[1] == 91 && key[0] == 27)
# define MV_NEXT (key[3] == 67 && key[2] == 91 && key[1] == 27 && key[0] == 27)
# define MV_BACK (key[3] == 68 && key[2] == 91 && key[1] == 27 && key[0] == 27)
# define PAST (key[0] == 16)
# define COPY (key[0] == 21)
# define COPY2 (key[0] == 9)
# define COPY3 (key[0] == 12)
# define CUT (key[0] == 24)
# define CUT1 (key[0] == 2)
# define CUT2 (key[0] == 14)
# define DELETE (key[0] == 127)
# define DELETE_LINE (key[0] == 18)
# define HISTORY_MOVE_BACK (key[2] == 65 && key[1] == 91 && key[0] == 27)
# define HISTORY_MOVE_NEXT (key[2] == 66 && key[1] == 91 && key[0] == 27)
# define CURSOR_UP  "up"
# define CURSOR_DOWN "sf"
# define CURSOR_RIGHT "nd"
# define CURSOR_LEFT "le"
# define CURSOR_CORNER "cr"
# define DELETE_AFTER_CURSOR "cd"

typedef	struct	s_read
{
	char	*line;
	char	*topast;
	int		winsize;
	int		linelen;
	int		linex;
	int		liney;
	int		tmplinex;
	int		tmpliney;
	int		curlinelen;
	int		totaly;
	int		index;
	int		info;
	char	**history;
	int		indexfor_history;
	int		is_quote;
	int		a;

}				t_read;

t_read			*g_insert;
pid_t			g_pid_cmd;
int				g_herdoc_sig;
int				g_ctrl_dsig;
int				g_is_pipe;
void			ft_setting(t_read *insert);
void			ft_cannonical_mod(void);
void			ft_setterm();
int				ft_key_detect(char *key, t_read *insert);
void			ft_addtoline(char *key, t_read *insert);
void			ft_do_termcap(char *termcap);
int				ft_totaly_count(t_read *insert);
int				ft_curlinelen(t_read *insert, int liney);
void			ft_movecursor_right(t_read *insert);
void			ft_defult_term();
void			ft_movecursor_left(t_read *insert, char *key);
void			ft_delete_char(t_read *insert, char *key);
int				ft_totaly_count(t_read *insert);
void			ft_cursor_lastpos(t_read *insert);
void			ft_remove_line(t_read *insert);
void			ft_movecursor_down(t_read *insert);
void			ft_movecursor_up(t_read *insert);
void			ft_movecursor_back_word(t_read *insert, char *key);
void			ft_movecursor_next_word(t_read *insert);
void			ft_movestart(t_read *insert);
void			ft_moveend(t_read *insert);
void			ft_copy(t_read *insert, char *key);
void			ft_cut(t_read *insert, char *key);
void			ft_history_back(t_read *insert);
void			ft_history_forwad(t_read *insert);
void			ft_add_history(char *line, t_read *insert);
void			ft_delete_onechar(t_read *insert);
void			sigint_handler(int sig);
void			ft_clear_screen(t_read *insert);
void			ft_syncwin_size(t_read *insert);
void			sigwinch_handler(int sig);
void			ft_signal_handler(t_read *insert, t_read *g_insert);
void			ft_cannonical_mod();
void			prompt();
void			ft_setting1(t_read *insert);
#endif
