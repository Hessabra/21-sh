/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synerr_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 05:49:04 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/15 11:47:08 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "synerr.h"

int			counred_2(int in, int out, int x, char c)
{
	if ((in && out) || ((in == 2 || out == 2) && x > 1) || in > 2 || out > 2)
	{
		ft_putstr_fd("\nSyntax error near unexpected token `", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int			counred_3(int in, int out, char c)
{
	if ((in || out) && c == '\0')
	{
		ft_putstr_fd("\nSyntax error near unexpected token `newline'\n", 2);
		return (0);
	}
	if ((in || out) && (c == ';' || c == '|'))
	{
		ft_putstr_fd("\nSyntax error near unexpected token `", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int			counvi(char **str)
{
	(*str)++;
	while (**str && **str < 33)
		(*str)++;
	if (**str && (**str == ';' || **str == '|' || **str == '>'
		|| **str == '<' || **str == '&'))
	{
		ft_putstr_fd("\nSyntax error near unexpected token `", 2);
		ft_putchar_fd(**str, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int			synerr_2(char **str)
{
	(*str)++;
	while (**str && **str < 33)
		(*str)++;
	if (**str == '&' || (**str == '<'))
	{
		ft_putstr_fd("\nSyntax error near unexpected token `", 2);
		ft_putchar_fd(**str, 2);
		ft_putstr_fd("'\n", 2);
		return (0);
	}
	return (1);
}

int			synerr_3(char **str)
{
	if (**str == 59)
	{
		(*str)++;
		while (**str && **str < 33)
			(*str)++;
		if (**str == '>' || **str == '<' || **str == '|')
		{
			ft_putstr_fd("\nSyntax error near unexpected token `", 2);
			ft_putchar_fd(**str, 2);
			ft_putstr_fd("'\n", 2);
			return (0);
		}
	}
	return (1);
}
