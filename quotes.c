/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:56:01 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/23 19:37:53 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		lenthargs(char *arg, int *bs, int m)
{
	int     	i;
	int     	mark;
	char    	x;
	int			mixed;
	static int  j = 0;

	(m == 0) ? j = 0 : j;
	x = 0;
	if (arg[0] == 39)
		x = 39;
	else if (arg[0] == 34)
		x = 34;
	i = 0;
	if (x)
		i = 1;
	mark = 1;
	mixed = 1;
	if (!x)
	{
		while (arg[i] && ((arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n')
			|| (mark == 0 && (arg[i] == ' '
			|| arg[i] == '\t' || arg[i] == '\n'))))
		{
			mark = 1;
			if (arg[i] == 92)
			{
				(bs[j] > 0) ? mark = 0 : mark;
				i += ft_entier(bs[j]);
				j++;
			}

			if (mark == 1 && (arg[i] == 34 || arg[i] == 39))
			{
				x = arg[i];
				i++;
				
				while (arg[i] && (arg[i] != x || (mixed < 0 && arg[i] > 32)))
				{
					if (arg[i] == 92 && x == 34)
					{
						(bs[j] > 0) ? mark = 0 : mark;
						i += ft_entier(bs[j]) - 1;
						(bs[j] > 0 && arg[i + 1] && arg[i + 1] != 39) ? i++ : i;
						j++;
					}
					i++;
					if (arg[i] == x && mark == 1 && arg[i + 1] && arg[i + 1] > 32)
						mixed = -1;
					mark = 1;
				}
				(mixed < 0) ? i++ : i;
				mixed = -1;
			}
			else
				i++;
		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
		i++;
	}
	else
	{
		while (arg[i] && (arg[i] != x || (mixed < 0 && arg[i] > 32)))
		{
			if (arg[i] == 92 && x == 34)
			{
				(bs[j] > 0) ? mark = 0 : mark;
				i += ft_entier(bs[j]) - 1;
				(bs[j] > 0 && arg[i + 1] && arg[i + 1] != 39) ? i++ : i;
				j++;
			}
			i++;
			if (arg[i] == x && mark == 1 && arg[i + 1] && arg[i + 1] > 32)
				mixed = -1;
			mark = 1;
		}
			(mixed < 0) ? i++ : i;
	}
	return (i * mixed);
}

/*
 * This function allocates in a double pointer that we've sent in the parame-
 * ters depending on quotes no quotes saving at the same time wheteir the 
 * input rgument used to have quotes on them or not with 1 for quotes and 0 
 * for not and in the ned there is -1 to mark the end.
 */
static void	allocatequote(char *arg, char ***args, char **env, int **bs)
{
	int i;
	int	nbr_ar;
	int stop;
	int quot;

	nbr_ar = nbr_arg(arg, *bs);
	ft_putnbr(nbr_ar);
	*args = (char **)malloc(sizeof(char *) * (nbr_ar + 1));
	i = 0;
	while (i < nbr_ar && *arg)
	{
		while (*arg == ' ' || *arg == '\t' || *arg == '\n')
			arg++;
		quot = 0;
		(*arg == 39 || *arg == 34) ? quot = 1 : quot;
		(*arg == 34) ? quot = 2 : quot;
		stop = lenthargs(arg, *bs, i);
		(stop < 0) ? quot = 3 : quot;
		if (stop)
		{
			if (quot == 3)
			{
				(*args)[i] = ft_strsub(arg, 0, ft_entier(stop) - 1);
				(*args)[i] = mixed((*args)[i], bs, env);
			}
			else if (stop > 0 && (*arg == 34 || *arg == 39))
			{
				(*args)[i] = ft_strsub(arg, 1, ft_entier(stop) - 1);
				(*args)[i] = line((*args)[i], env, bs, quot);
			}
			else
			{
				(*args)[i] = ft_strsub(arg, 0, ft_entier(stop) - 1);
				(*args)[i] = line((*args)[i], env, bs, quot);
			}
			i++;
		}
		arg = ft_strsub(arg, ft_entier(stop), ft_strlen(arg));
		if (i > 0 && quot)
			arg++;
	}
	(*args)[i] = NULL;
}

/* 
 *  In the first case I should make another spliting functions
 *  that takes into consideration the '\' (ascii code 92)
 * 	>>>> DONE
*/
 
char **quotyline(char *arg, int **bs, char **env, t_quotis nbr_quot)
{
	char **args;

	if (nbr_quot.s == 0 && nbr_quot.d == 0)
	{
		args = ft_splitbs(arg, *bs);
		while (args[nbr_quot.s])
		{
			args[nbr_quot.s] = line(args[nbr_quot.s], env, bs, 0);
			ft_putstr("\n");
			ft_putstr(args[nbr_quot.s]);
			ft_putstr("\n");
			nbr_quot.s++;
		}
		nbr_quot.s = 0;
	}
	else
		allocatequote(arg, &args, env, bs);
	
	return (args);
}