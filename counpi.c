/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counpi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:21:45 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/26 15:31:23 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	erro(char c)
{
	ft_putstr_fd("\nSyntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}

static int	condition1(int err, char str)
{
	if (err && str && (str < 33 || str == 124 || str == 38 || str == 59))
		return (1);
	return (0);
}

static int	condition2(int pi, int *err, int x, char str)
{
	if ((str == 59 || (pi && str == 38) || (pi == 2 && x > 1)) && !(*err = 0))
		return (1);
	return (0);
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
	while (condition1(err, **str))
	{
		if (**str == '|')
		{
			pi++;
			x = i;
		}
		if (condition2(pi, &err, x, **str))
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
