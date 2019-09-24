/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mansig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:00:56 by hessabra          #+#    #+#             */
/*   Updated: 2019/05/24 21:22:45 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pidh(void)
{
	ft_putstr("\e[35;1m\x1B[100mWhat can I do for you ;) >>\n\e[0m");
}

void	mansig(int sig)
{
	signal(SIGINT, SIG_DFL);
	if (sig == SIGINT)
		ft_printf("\nIt was a CTRL-C wlh :3\n");
	if (pid == 0)
		pidh();
}
