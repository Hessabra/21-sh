/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:27:09 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 03:29:00 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			zaapi(char *str, int *i, int **bs, char c)
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

static void			zaapin(char *str, int *i, int **bs)
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

static int			nbr_arg2(char *str, int *bs)
{
	int				result;
	int				marq;
	int				j;
	int				i;

	result = 0;
	i = -1;
	j = 0;
	marq = 1;
	while(str[j])
	{
		i = 1;

		if (marq == 1 && (str[j] == '>' || str[j] == '<'))
		{
			if (j > 0 && str[j - 1] != ' ' && str[j - 1] != '\t' && str[j - 1] != '\n')
				result++;
			if (str[j + 1] == str[j])
			{
				j++;
				marq = 0;
			}
			if (str[j + 1] != ' ' && str[j + 1] != '\t' && str[j + 1] != '\n')
				result++;
			marq = 1;
		}
		if (str[j] == 92)
		{
			(*bs > 0) ? i = 0 : i;
			j += ft_entier(*bs);
			bs++;
		}
		if (str[j] == 39 || str[j] == 34)
		{
			if (marq == 1 && (str[j] == 39 || (str[j] == 34 && i)))
				marq = 0;
			else if (str[j] == 39 || (str[j] == 34 && i))
				marq = 1;
		}
		if (i && str[j] && (str[j] == ' ' && marq) && str[j + 1] && str[j + 1] > 32)
			result++;
		j++;
	}
	if (i != -1)
		result++;
	return (result);
}

static int			len_arg2(char *arg, int *bs, int m, int **tok)
{
	static int		start = 0;
	static int		mark = 0;
	int				i;
	int				j;
	int				hd;
	int				mixed;

	(*tok)[m] = 0;
	mixed = 1;
	(m == 0) ? start = 0 : start;
	i = 0;
	if (arg[i] == '<' || arg[i] == '>' || ft_strnequ(arg, "&>", 2))
	{
		if (arg[i] == '<')
		{
			i++;
			(*tok)[m] = 6;
			if (arg[i] == '<')
			{
				i++;
				(*tok)[m] = 7;
			}
			else if (arg[i] == '&')
			{
				i++;
				(*tok)[m] = 8;
			}
		}
		else if (arg[i] == '>')
		{
			(*tok)[m] = 1;
			i++;
			if (arg[i] == '>')
			{
				i++;
				(*tok)[m] = 4;
			}
			else if (arg[i] == '&')
			{
				(*tok)[m] = 2;
				i++;
				if (arg[i] == '-')
				{
					i++;
					(*tok)[m] = 5;
				}
			}
		}
		else if (arg[i] == '&')
		{
			(*tok)[m] = 3;
			i += 2;
		}
		j = i;
		while (arg[j] && arg[j] < 33)
			j++;
		(arg[j] > 32) ? mark = 1 : mark;
	}
	else
	{
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
		if (mark == 1)
		{
			mark = 0;
			((*tok)[m - 1] == 6) ? (*tok)[m] = 11 : mark;
			((*tok)[m - 1] == 7) ? (*tok)[m] = 12 * hd : mark;
			if ((*tok)[m - 1] == 1 || (*tok)[m - 1] == 3 || (*tok)[m - 1] == 4)
				(*tok)[m] = 11;
			else if ((*tok)[m - 1] == 2 || (*tok)[m - 1] == 8)
				(*tok)[m] = 10;
		}
		if (arg[i] && arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n')
		{
			((arg[i] == '>' || arg[i] == '<') && hd == 1 && (*tok)[m] < 10) ? (*tok)[m] = 9 : (*tok)[m];

		}
	}
	return(i * mixed);
}

static int			*alloc_args(char *arg, char ***args, char **env, int **bs)
{
	int				i;
	int				nbr_ar;
	int				len_ar;
	int				*token;

	while (*arg && *arg < 33)
		arg++;
	nbr_ar = nbr_arg2(arg, *bs);
	token = (int *)malloc(sizeof(int) * (nbr_ar + 1));
	*args = (char **)malloc(sizeof(char *) * (nbr_ar + 1));

	i = 0;
	while (*arg && i < nbr_ar)
	{
		while (*arg && *arg < 33)
			arg++;
		len_ar = len_arg2(arg, *bs, i, &token);
		(*args)[i] = (char *)malloc(sizeof(char) * (len_ar + 1));
		if (len_ar > 0 && (*arg == 34 || *arg == 39))
			(*args)[i] = ft_strsub(arg, 1, len_ar - 2);
		else
			(*args)[i] = ft_strsub(arg, 0, ft_entier(len_ar));
		if (token[i] == 1 && (len_ar < 0 || *arg == 34 || *arg == 39))
			token[i] = 0;
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
	token[i] = -1;
	i = 0;
	while (token[i] > -1)
	{
		ft_putnbr_fd(token[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
	return (token);
}

/* 
 *  In the first case I should make another spliting functions
 *  that takes into consideration the '\' (ascii code 92)
 * 	>>>> DONE
 */

char				**quotyred(char *arg, int **bs, char **env, t_quotis nbr_quot, int **token)
{
	char			**args;

	nbr_quot.d = 0;
	*token = alloc_args(arg, &args, env, bs);
	return (args);
}
