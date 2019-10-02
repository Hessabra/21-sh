/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counpi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:21:45 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 03:59:53 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			counpi(char **str)
{
	int		pi;
	int		i;
	int		x;

	i = 0;
	pi = 0;
	while (**str && (**str < 33 || **str == 124 || **str == 38))
	{
		if (**str == '|')
		{
			pi++;
			x = i;
		}
		if ((pi && **str == 38) || (pi == 2 && x > 1))
		{
			ft_putstr_fd("\nSyntax error near unexpected token `", 2);
			ft_putchar_fd(**str, 2);
			ft_putstr_fd("'\n", 2);
			return (0);
		}
		if (pi > 1)
		{
			ft_putstr_fd("\nLogical operator.. Not to it yet\n", 2);
			return (0);
		}
		(*str)++;
		if (pi && **str == '\0')
		{
			ft_putstr_fd("\nSyntax error near unexpected token `newline'\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
