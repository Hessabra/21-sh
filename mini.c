/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:12:49 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 19:27:31 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		racco1(char **arg, char ***env)
{
	int		i;

	i = 1;
	if (ft_strequ(arg[0], "bye") || ft_strequ("exit", arg[0]))
		i = exi(arg, env);
	else if (ft_strequ(arg[0], "setenv"))
	{
		stenv(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "unsetenv"))
	{
		*env = unstenv(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "echo"))
		i = ech(arg);
	return (i);
}

int		racco3(char **arg, char ***env)
{
	int			i;

	if (ft_strequ(arg[0], "cd"))
	{
		cdi(arg, env);
		return (0);
	}
	else if (ft_strequ(arg[0], "env"))
	{
		i = 0;
		while ((*env)[i])
		{
			ft_putstr((*env)[i]);
			ft_putchar('\n');
			i++;
		}
		return (0);
	}
	return (1);
}

int		execve2(char **arg, char **environ, char *path)
{
	int			x;
	char		*tmp;

	x = ft_know(environ, "PATH");
	if (!(path = checking(arg[0], (environ[x]) + 5, x)) && arg[0])
	{
		ft_putstr_fd(arg[0], 2);
		ft_putstr_fd("?! Sadly, I don't know this...\n", 2);
		return (0);
	}
	else if (ft_strequ(path, arg[0]) && (execve(arg[0], arg, environ) == -1))
	{
		ft_putstr_fd(arg[0], 2);
		ft_putstr_fd("?! Sadly, I don't know this...\n", 2);
		return (0);
	}
	else
	{
		tmp = ft_jandf(ft_strjoin(path, "/"), arg[0], 1, 0);
		if (execve(tmp, arg, environ) == -1)
		{
			ft_putstr_fd(arg[0], 2);
			ft_putstr_fd("?! Sadly, I don't know this...\n", 2);
			exit(0);
		}
		free(tmp);
	}
	return (1);
}

int				racc4(t_ppvr a, char ***env, t_dolor *t, char *path, int **token, t_read insert)
{
	int			i;
	char		**string_heredoc;

	string_heredoc = use_heredoc(a.ppvr, token, a.arg, *env, insert);
	if (g_herdoc_sig)
	{
		i = 0;
		while (a.arg[i])
		{
			g_is_pipe = 1;
			if (ft_entier(a.ppvr[i]) == 1 || a.ppvr[i] == -4)
			{
				g_is_pipe = 0;
				a.x = i;
				while (ft_entier(a.ppvr[a.x]) == 1 || a.ppvr[a.x] == -4)
					a.x++;
				g_pid_cmd = fork();
				if (g_pid_cmd == 0)
				{
					mainpipe(a, *env, i, token, &string_heredoc);
					wait(NULL);
					exit(0);
				}
				else
				{
					waitpid(g_pid_cmd, NULL, 0);
					string_heredoc += ft_makesure(a.ppvr, token, i, a.x + 1);
				}
				i = a.x;
			}
			else if (a.ppvr[i] == -3 || a.ppvr[i] == -2)
				usered(a.arg[i], token[i], env, &string_heredoc);
			else if (racco1(a.arg[i], env) && racco3(a.arg[i], env)
				&& a.arg[i][0])
			{
				g_pid_cmd = fork();
				if (g_pid_cmd == 0)
				{
					if (ft_strequ(a.arg[i][0], "cat") ||
							ft_strequ(a.arg[i][0], "wc"))
						ft_defult_term();
					if (!execve2(a.arg[i], *env, path))
						return (1);
				}
				else
					wait(&(t->x));
			}
			i++;
		}
	}
	return (0);
}
static t_quotis	nbr_quote(char *arg, int *bs)
{
	t_quotis	nbrs;
	int			mark;

	nbrs.s = 0;
	nbrs.d = 0;
	nbrs.n = 0;
	while (*arg)
	{
		mark = 1;
		if (*arg == 92)
		{
			(*bs > 0) ? mark = 0 : mark;
			arg += ft_entier(*bs);
			bs++;
		}
		if (*arg && *arg == 39 && ft_parite(nbrs.d))
			(nbrs.s)++;
		else if (mark && *arg && *arg == 34 && ft_parite(nbrs.s))
			(nbrs.d)++;
		else if (mark && *arg && ft_parite(nbrs.d) && ft_parite(nbrs.s))
			nbrs.n += 2;
		arg++;
	}
	return (nbrs);
}

int				main(void)
{ 
	t_ppvr		a;
	char		**arg;
	char		*path;
	t_dolor		t;
	extern char	**environ;
	int			*bs;
	int			j;
	int			**token;
	int			*tmpbs;
	t_read		insert;
	char		*try;

	environ = aloc(environ);
	ft_setterm();
	insert.indexfor_history = 0;
	t.i = 0;
	try = NULL;
	g_ctrl_dsig = 0;
	a.arg = NULL;
	insert.topast = ft_memalloc(LINE_MAX);
	while (1)
	{
		if (a.arg)
			tfree(a.arg);
		g_is_pipe = 1;
		g_pid_cmd = 0;
		g_herdoc_sig = 1;
		j = 1;
		path = NULL;
		prompt();
		try = ft_readline(try, &insert);
		if (try)
		{
			effectornot(&bs, try);
			a.nbr_quot = nbr_quote(try, bs);
			if (!ft_parite((a.nbr_quot).d) || !ft_parite((a.nbr_quot).s))
				j = quotiwhile(a.nbr_quot, &try, &bs, &insert);
			ft_add_history(try, &insert);
			if (j && synerr(try, bs))
			{
				arg = ft_ppvr(try, bs, &a.ppvr);
				tmpbs = bs;
				token = NULL;
				a.arg = triplp(arg, bs, environ, a, &token);
				ft_putstr("\n");
				if (a.arg)
				{
					t.i = 1;
					if (racc4(a, &environ, &t, path, token, insert))
						return (1);
				}
			}
		}
		free(try);
	}
	return (0);
}
