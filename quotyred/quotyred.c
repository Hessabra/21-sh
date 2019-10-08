/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotyred.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:27:09 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:20:00 by hessabra         ###   ########.fr       */
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
	t_alloc_args	aa;
	int				*token;

	alloc_args_2(&aa, &arg, &token, *bs);
	*args = (char **)ft_memalloc(sizeof(char *) * (aa.nbr_ar + 1));
	while (++(aa.i) < aa.nbr_ar && *arg)
	{
		alloc_args_3(&aa, &arg, &token, *bs);
		alloc_args_4(&aa, arg, args, &token);
		if (aa.len_ar < 0)
			(*args)[aa.i] = mixed((*args)[aa.i], bs, env);
		else
		{
			if (*arg == 34)
				line((*args)[aa.i], env, bs, 2);
			else if (*arg == 39)
				line(((*args))[aa.i], env, bs, 1);
			else
				line((*args)[aa.i], env, bs, 0);
		}
		arg += ft_entier(aa.len_ar);
	}
	(*args)[aa.i] = NULL;
	token[aa.i] = -1;
	return (token);
}

char				**quotyred(t_triplp *tp, t_triplp2 *tp2, char **env,
					t_quotis nbr_quot)
{
	char			**args;

	nbr_quot.d = 0;
	(tp->token)[tp2->i] = alloc_args((tp->arg)[tp2->i], &args, env, &(tp2->bs));
	return (args);
}
