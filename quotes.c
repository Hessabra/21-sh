/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:56:01 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:29:58 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			zaapi(char *str, int *i, int **bs, char c)
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
	return (1);
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

int					lenthargs_4(char *arg, int *bs, int m)
{
	static int		start = 0;
	int				i;
	int				hd;
	int				mixed;

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
			(zaapi(arg, &i, &bs, arg[i])) ? i++ : i;
		}
		else
		{
			(i > 0) ? mixed = -1 : mixed;
			zaapin(arg, &i, &bs);
		}
	}
	return (i * mixed);
}

static void			allocatequote(char *arg, char ***args, char **env, int **bs)
{
	int				i;
	int				nbr_ar;
	int				len_ar;

	allocatequote_4(&arg, &nbr_ar, *bs, &i);
	*args = (char **)ft_mema(sizeof(char *) * (nbr_ar + 1));
	while (*arg && i < nbr_ar)
	{
		allocatequote_3(&arg, &len_ar, *bs, i);
		allocatequote_2(args, i, len_ar, arg);
		if (len_ar < 0)
			(*args)[i] = mixed((*args)[i], bs, env);
		else
		{
			if (*arg == 34)
				(*args)[i] = line((*args)[i], env, bs, 2);
			else if (*arg == 39)
				line(((*args))[i], env, bs, 1);
			else
				(*args)[i] = line((*args)[i], env, bs, 0);
		}
		i++;
		arg += ft_entier(len_ar);
	}
	(*args)[i] = NULL;
}

char				**quotyline(char *arg, int **bs, char **env,
					t_quotis nbr_quot)
{
	char		**args;

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
