/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counpi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:21:45 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 02:50:40 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	erro(char c)
{
	ft_putstr_fd("\nSyntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}

int			counpi(char **str)
{
	int		pi;
	int		i;
	int		x;
	int		err;

	i = 0;
	pi = 0;
	err = 1;
	while (err && **str && (**str < 33 || **str == 124 || **str == 38))
	{
		if (**str == '|')
		{
			pi++;
			x = i;
		}
		if (((pi && **str == 38) || (pi == 2 && x > 1)) && !(err = 0))
			erro(**str);
		else if (pi > 1 && !(err = 0))
			ft_putstr_fd("\nLogical operator.. Not to it yet\n", 2);
		(*str)++;
		if (err && pi && **str == '\0' && !(err = 0))
			ft_putstr_fd("\nSyntax error near unexpected token `newline'\n", 2);
		i++;
	}
	return (err);
}
