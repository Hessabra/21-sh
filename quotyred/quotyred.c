/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:27:09 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 19:08:34 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotyred.h"

void				zaapi(char *str, int *i, int **bs, char c)
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
void				zaapin(char *str, int *i, int **bs)
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
	return (token);
}

char				**quotyred(char *arg, int **bs, char **env, t_quotis nbr_quot, int **token)
{
	char			**args;

	nbr_quot.d = 0;
	*token = alloc_args(arg, &args, env, bs);
	return (args);
}
