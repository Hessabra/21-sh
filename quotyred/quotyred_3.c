/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 02:38:10 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 22:00:38 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotyred.h"

static int		first_if_lenarg(t_len_arg *la, int **tok, char *arg, int m)
{
	if (arg[la->i] == '<')
	{
		la->i++;
		(*tok)[m] = 6;
		if (arg[la->i] == '<' && ((la->i)++))
			(*tok)[m] = 7;
		else if (arg[la->i] == '&' && ((la->i)++))
			(*tok)[m] = 8;
		return (0);
	}
	else if (arg[la->i] == '>')
	{
		(*tok)[m] = 1;
		(la->i)++;
		if (arg[la->i] == '>' && ((la->i)++))
			(*tok)[m] = 4;
		else if (arg[la->i] == '&' && ((la->i)++))
		{
			(*tok)[m] = 2;
			if (arg[la->i] == '-' && ((la->i)++))
				(*tok)[m] = 5;
		}
		return (0);
	}
	return (1);
}

static void		first_if_lenarg_2(t_len_arg *la, int **tok, char *arg, int m)
{
	if (la->k)
	{
		if (arg[la->i] == '&')
		{
			(*tok)[m] = 3;
			la->i += 2;
		}
	}
	la->j = la->i;
	while (arg[la->j] && arg[la->j] < 33)
		(la->j)++;
}

static void		second_while_lenarg(t_len_arg *la, char *arg, int *bs)
{
	la->hd = 1;
	while (arg[la->i] && arg[la->i] != ' ' && arg[la->i] != '\t' &&
			arg[la->i] != '\n' && arg[la->i] != '>' &&
			!ft_strnequ(arg + la->i, "&>", 2) && arg[la->i] != '<')
	{
		if ((la->i == 0 || arg[la->i - 1] > 32) && (arg[la->i] == 34 ||
					arg[la->i] == 39))
		{
			la->hd = -1;
			(la->i > 0) ? la->mixed = -1 : la->mixed;
			zaapi(arg, &(la->i), &bs, arg[la->i]);
			(la->i)++;
		}
		else
		{
			(la->i > 0) ? la->mixed = -1 : la->mixed;
			zaapin(arg, &(la->i), &bs);
		}
	}
}

static void		second_if_lenarg_2(int **tok, int m, t_len_arg la)
{
	la.i = 0;
	((*tok)[m - 1] == 6) ? (*tok)[m] = 11 : m;
	((*tok)[m - 1] == 7) ? (*tok)[m] = 12 : m;
	if ((*tok)[m - 1] == 1 || (*tok)[m - 1] == 3 || (*tok)[m - 1] == 4)
		(*tok)[m] = 11;
	else if ((*tok)[m - 1] == 2 || (*tok)[m - 1] == 8)
		(*tok)[m] = 10;
}

int				len_arg2(char *arg, int *bs, int m, int **tok)
{
	static int	mark = 0;
	t_len_arg	la;

	(*tok)[m] = 0;
	la.mixed = 1;
	la.i = 0;
	if (arg[la.i] == '<' || arg[la.i] == '>' || ft_strnequ(arg, "&>", 2))
	{
		la.k = first_if_lenarg(&la, tok, arg, m);
		first_if_lenarg_2(&la, tok, arg, m);
		(arg[la.j] > 32) ? mark = 1 : mark;
	}
	else
	{
		second_while_lenarg(&la, arg, bs);
		if (mark == 1 && !(mark = 0))
			second_if_lenarg_2(tok, m, la);
		if (arg[la.i] && arg[la.i] != ' ' && arg[la.i] != '\t' &&
				arg[la.i] != '\n')
		{
			((arg[la.i] == '>' || arg[la.i] == '<') && la.hd == 1 &&
				(*tok)[m] < 10) ? (*tok)[m] = 9 : (*tok)[m];
		}
	}
	return (la.i * la.mixed);
}
