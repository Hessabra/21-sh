/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_addition1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:38:52 by helmanso          #+#    #+#             */
/*   Updated: 2019/09/26 15:56:35 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	ft_remove_line1(t_read *insert)
{
	int i;

	i = insert->liney;
	if (i)
		while (i--)
			ft_do_termcap(CURSOR_UP);
	ft_do_termcap(CURSOR_CORNER);
}

void	ft_movestart(t_read *insert)
{
	ft_remove_line1(insert);
	insert->linex = 0;
	insert->liney = 0;
	insert->index = 0;
}

void	ft_moveend(t_read *insert)
{
	while (insert->index < insert->linelen)
		ft_movecursor_right(insert);
}
