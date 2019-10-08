/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:53:20 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 05:29:58 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dolo.h"

static int	ft_aln(char str)
{
	if (!(ft_isalnum(str)) && str != '_')
		return (0);
	return (1);
}

static void	racc1(char **fin, char **env, char *s, t_dolor *t)
{
	char	*var;
	int		k;
	int		j;

	(t->i)++;
	var = (char *)ft_mema(sizeof(char) * ft_strlen(s));
	k = 0;
	while (s[t->i] && ft_aln(s[t->i]))
	{
		var[k] = s[t->i];
		k++;
		(t->i)++;
	}
	var[k] = '\0';
	if ((j = ft_know(env, var)) > -1)
		*fin = ft_jandf(*fin, env[j] + k + 1, 1, 0);
	else
		*fin = ft_jandf(*fin, "", 1, 0);
	ft_memdel((void**)(&var));
}

static int	racc2(char **fin, char **env, char *s, t_dolor t)
{
	char	*var;
	int		j;

	if (!(s[t.i + 1]) || s[t.i + 1] == '/')
	{
		if ((j = ft_know(env, "HOME")) > -1)
			*fin = ft_jandf(*fin, env[j] + 5, 1, 0);
		else
		{
			if ((j = ft_know(env, "PWD")) > -1)
				*fin = ft_jandf(*fin, env[j] + 4, 1, 0);
			else if ((j = ft_know(env, "OLDPWD")) > -1)
				*fin = ft_jandf(*fin, env[j] + 7, 1, 0);
			else
			{
				var = (char *)ft_mema(sizeof(char) * 1000);
				getcwd(var, 1000);
				*fin = ft_jandf(*fin, var, 1, 1);
				free(var);
			}
		}
		return (0);
	}
	return (1);
}

static void	racc3(char **fin, char **env, char *s, t_dolor *t)
{
	if (t->i == 0)
	{
		if (racc2(&(*fin), env, s, *t))
		{
			*fin = ft_jandf(ft_strdup("/Users/"), s + 1, 1, 0);
			while (s[t->i + 1])
				(t->i)++;
		}
	}
	else
		*fin = ft_jandf(*fin, ft_strsub(s, t->i, 1), 1, 1);
	(t->i)++;
}

char		*dolor1(char *s, char **env, int **bs, int quot)
{
	t_dolor	t;
	char	*fin;
	int		backslash;
	int		markdown;

	initi_dolo(&fin, &(t.i), &backslash);
	while (s[t.i])
	{
		backslash = 1;
		if (s[t.i] == 92)
		{
			markdown = ft_entier(**bs) / 2;
			((condition_dolo(quot, **bs, s, t))) ? markdown++ : t.i;
			replace_dolo(&backslash, markdown, &fin);
			intent_dolo(&(t.i), bs, &backslash, s);
		}
		t.x = t.i;
		if (backslash && s[t.i] == '$')
			racc1(&fin, env, s, &t);
		else if (backslash && s[t.i] == '~' && !quot)
			racc3(&fin, env, s, &t);
		else
			lastelse_dolo(&fin, s, &t);
	}
	return (fin);
}
