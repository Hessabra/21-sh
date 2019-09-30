/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:56:01 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/30 04:28:28 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void        zaapi(char *str, int *i, int **bs, char c)
{
    (*i)++;
    while (str[*i] && str[*i] != c)
    {
        if (c != 39 && str[*i] == 92)
        {
            *i += ft_entier(**bs) - 1;
            (**bs > 0) ? (*i)++ : *i;
            (*i)++;
        }
       (*i)++;
    }
}

static void        	zaapin(char *str, int *i, int **bs)
{
    while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n'
		&& str[*i] != '>' && str[*i] != 34 && str[*i] != 39
		&& !ft_strnequ(str + *i, "&>", 2) && str[*i] != '<')
    {
        if (str[*i] == 92)
        {
            *i += ft_entier(**bs) - 1;
            (**bs > 0) ? (*i)++ : *i;
            (*i)++;
        }
       (*i)++;
    }
}

static int		lenthargs(char *arg, int *bs, int m)
{
	// int     	i;
	// int     	mark;
	// char    	x;
	// int			mixed;
	// static int  j = 0;

	// (m == 0) ? j = 0 : j;
	// x = 0;
	// if (arg[0] == 39)
	// 	x = 39;
	// else if (arg[0] == 34)
	// 	x = 34;
	// i = 0;
	// if (x)
	// 	i = 1;
	// mark = 1;
	// mixed = 1;
	// if (!x)
	// {
	// 	while (arg[i] && ((arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n')
	// 		|| (mark == 0 && (arg[i] == ' '
	// 		|| arg[i] == '\t' || arg[i] == '\n'))))
	// 	{
	// 		mark = 1;
	// 		if (arg[i] == 92)
	// 		{
	// 			(bs[j] > 0) ? mark = 0 : mark;
	// 			i += ft_entier(bs[j]);
	// 			j++;
	// 		}

	// 		if (mark == 1 && (arg[i] == 34 || arg[i] == 39))
	// 		{
	// 			x = arg[i];
	// 			i++;
				
	// 			while (arg[i] && (arg[i] != x || (mixed < 0 && arg[i] > 32)))
	// 			{
	// 				if (arg[i] == 92 && x == 34)
	// 				{
	// 					(bs[j] > 0) ? mark = 0 : mark;
	// 					i += ft_entier(bs[j]) - 1;
	// 					(bs[j] > 0 && arg[i + 1] && arg[i + 1] != 39) ? i++ : i;
	// 					j++;
	// 				}
	// 				i++;
	// 				if (arg[i] == x && mark == 1 && arg[i + 1] && arg[i + 1] > 32)
	// 					mixed = -1;
	// 				mark = 1;
	// 			}
	// 			(mixed < 0) ? i++ : i;
	// 			mixed = -1;
	// 		}
	// 		else
	// 			i++;
	// 	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	// 	i++;
	// }
	// else
	// {
	// 	while (arg[i] && (arg[i] != x || (mixed < 0 && arg[i] > 32)))
	// 	{
	// 		if (arg[i] == 92 && x == 34)
	// 		{
	// 			(bs[j] > 0) ? mark = 0 : mark;
	// 			i += ft_entier(bs[j]) - 1;
	// 			(bs[j] > 0 && arg[i + 1] && arg[i + 1] != 39) ? i++ : i;
	// 			j++;
	// 		}
	// 		i++;
	// 		if (arg[i] == x && mark == 1 && arg[i + 1] && arg[i + 1] > 32)
	// 			mixed = -1;
	// 		mark = 1;
	// 	}
	// 		(mixed < 0) ? i++ : i;
	// }
	// return (i * mixed);
	static int start = 0;
	int		i;
	int		hd;
	int		mixed;
	
	mixed = 1;
	(m == 0) ? start = 0 : start;
	i = 0;
	hd = 1;
	while (arg[i] && arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n'
	&& arg[i] != '>' && !ft_strnequ(arg + i, "&>", 2) && arg[i] != '<')
	{
		if ((i == 0 || arg[i - 1] > 32) && (arg[i] == 34 || arg[i] == 39))
		{
			hd = -1;
			(i > 0) ? mixed = -1 : mixed;
			zaapi(arg, &i, &bs, arg[i]);
			i++;
		}
		else
		{
			(i > 0) ? mixed = -1 : mixed;
			zaapin(arg, &i, &bs);
		}
	}
	return(i * mixed);
}

/*
 * This function allocates in a double pointer that we've sent in the parame-
 * ters depending on quotes no quotes saving at the same time wheteir the 
 * input rgument used to have quotes on them or not with 1 for quotes and 0 
 * for not and in the ned there is -1 to mark the end.
 */
static void	allocatequote(char *arg, char ***args, char **env, int **bs)
{
	// int i;
	// int	nbr_ar;
	// int stop;
	// int quot;

	// nbr_ar = nbr_arg(arg, *bs);
	// ft_putnbr(nbr_ar);
	// *args = (char **)malloc(sizeof(char *) * (nbr_ar + 1));
	// i = 0;
	// while (i < nbr_ar && *arg)
	// {
	// 	while (*arg && *arg < 33)
	// 		arg++;
	// 	quot = 0;
	// 	(*arg == 39 || *arg == 34) ? quot = 1 : quot;
	// 	(*arg == 34) ? quot = 2 : quot;
	// 	stop = lenthargs(arg, *bs, i);
	// 	dprintf(2,"\n nbr_ar == %d arg == %s stop == %d\n", nbr_ar, arg, stop);
	// 	(stop < 0) ? quot = 3 : quot;
	// 	if (stop)
	// 	{
	// 		if (quot == 3)
	// 		{
	// 			(*args)[i] = ft_strsub(arg, 0, ft_entier(stop) - 1);
	// 			(*args)[i] = mixed((*args)[i], bs, env);
	// 		}
	// 		else if (stop > 0 && (*arg == 34 || *arg == 39))
	// 		{
	// 			(*args)[i] = ft_strsub(arg, 1, ft_entier(stop) - 1);
	// 			(*args)[i] = line((*args)[i], env, bs, quot);
	// 		}
	// 		else
	// 		{
	// 			(*args)[i] = ft_strsub(arg, 0, ft_entier(stop) - 1);
	// 			(*args)[i] = line((*args)[i], env, bs, quot);
	// 		}
	// 		i++;
	// 	}
	// 	arg = ft_strsub(arg, ft_entier(stop), ft_strlen(arg));
	// 	if (i > 0 && quot)
	// 		arg++;
	// }
	// (*args)[i] = NULL;
	int				i;
	int				nbr_ar;
	int				len_ar;

	while (*arg && *arg < 33)
		arg++;
	nbr_ar = nbr_arg(arg, *bs);
	*args = (char **)malloc(sizeof(char *) * (nbr_ar + 1));

	i = 0;
	while (*arg && i < nbr_ar)
	{
		while (*arg && *arg < 33)
			arg++;
		len_ar = lenthargs(arg, *bs, i);
		(*args)[i] = (char *)malloc(sizeof(char) * (len_ar + 1));
		if (len_ar > 0 && (*arg == 34 || *arg == 39))
			(*args)[i] = ft_strsub(arg, 1, len_ar - 2);
		else
			(*args)[i] = ft_strsub(arg, 0, ft_entier(len_ar));
		if (len_ar < 0)
			(*args)[i] = mixed((*args)[i], bs, env);
		else
		{
			if (*arg == 34)
				line((*args)[i], env, bs, 2);
			else if (*arg == 39)
				line(((*args))[i], env, bs, 1);
			else
				line((*args)[i], env, bs, 0);
		}
		i++;
		arg += ft_entier(len_ar);
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
			nbr_quot.s++;
		}
		nbr_quot.s = 0;
	}
	else
		allocatequote(arg, &args, env, bs);
	
	return (args);
}