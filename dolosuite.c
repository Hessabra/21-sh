/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolosuite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:19:00 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 03:57:53 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	var = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
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
	free(var);
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
				var = (char *)malloc(sizeof(char) * 1000);
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

char		*dolor2(char *s, char **env)
{
	t_dolor	t;
	char	*fin;

	fin = ft_strdup("");
	t.i = 0;
	while (s[t.i])
	{
		t.x = t.i;
		if (s[t.i] == '$')
			racc1(&fin, env, s, &t);
		else if (s[t.i] == '~')
			racc3(&fin, env, s, &t);
		else
		{
			fin = ft_jandf(fin, ft_strsub(s, t.i, 1), 1, 1);
			(t.i)++;
		}
	}
	return (fin);
}
