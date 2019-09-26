/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:57:01 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/26 15:56:56 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void    ft_signal_handler(t_read *insert, t_read *g_insert)
{
    g_insert = insert;
    g_insert->index = insert->index;
	signal(SIGINT, sigint_handler);
	signal(SIGWINCH, sigwinch_handler);
}

void    sigwinch_handler(int sig)
{
    char *tmp;
    int     tmpindex;
    char     *key;

    key = 0;
    tmpindex = g_insert->index;
    tmp = ft_strdup(g_insert->line);
    ft_clear_screen(g_insert);
    ft_syncwin_size(g_insert);
	ft_addtoline(tmp, g_insert);
    (void)sig;
}

void    sigint_handler(int sig)
{
    ft_clear_screen(g_insert);
    (void)sig;
    if (g_insert->history)
    g_insert->indexfor_history = ft_tablen(g_insert->history);
}
