/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:12:49 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/26 21:09:09 by hessabra         ###   ########.fr       */
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

int		racc4(t_ppvr a, char ***environ, t_dolor *t, char *path, int **token)
{
	int			i;

	i = 0;
	while (a.arg[i])
	{
		if (a.ppvr[i] == 1 || a.ppvr[i] == -4)
		{
			a.x = i;
			while (ft_entier(a.ppvr[a.x]) == 1 || a.ppvr[a.x] == -4)
				a.x++;
			pid = fork();
			if (pid == 0)
			{
				mainpipe(a, *environ, i, token);
				exit(0);
			}
			else
				waitpid(pid, NULL, 0);
			i = a.x;
			// if ((ft_strequ(a.arg[i][0], "exit") || ft_strequ(a.arg[i][0], "cd") ||
			// 	ft_strequ(a.arg[i][0], "setenv") || ft_strequ(a.arg[i][0], "unsetenv") ||
			// 	ft_strequ(a.arg[i][0], "echo")) && racco1(a.arg[i], environ))
			// 		racco3(a.arg[i], environ);
		}
		else if (a.ppvr[i] == -3)
			usered(a.arg[i], token[i], environ);
		else if (racco1(a.arg[i], environ) && racco3(a.arg[i], environ) && a.arg[i][0])
		{
			pid = fork();
			if (pid == 0)
			{
				if (!execve2(a.arg[i], *environ, path))
					return (1);
			}
			else
				wait(&(t->x));
		}
		i++;
	}
	return (0);
}
static t_quotis nbr_quote(char *arg, int *bs)
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
			(nbrs.n)+=2;
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
	int			**token;
	int			*tmpbs;
	t_read		insert;
	char		*try;

	environ = aloc(environ);
	ft_setterm();
	insert.indexfor_history = 0;
	t.i = 0;
//	try = ft_strnew(0);
	try = NULL;
//	try = ft_strnew(0);
	while (1)
	{
		signal(SIGINT, mansig);
		path = NULL;
		ft_putstr("\e[35;1mWhat can I do for you ;) >>\n\e[0m");
		if (t.i)
		{
			t.i = 0;
			dfre(arg);
		}
		try = ft_readline(try, &insert);
		ft_add_history(try, &insert);
		if (try)
		{
			effectornot(&bs, try);
			a.nbr_quot = nbr_quote(try, bs);
			if (!ft_parite((a.nbr_quot).d) || !ft_parite((a.nbr_quot).s))
				quotiwhile(a.nbr_quot, &try, &bs, &insert);
				if (ft_strcmp(try, ""))
			ft_add_history(try, &insert);
			if (synerr(try, bs))
			{
				arg = ft_ppvr(try, bs, &a.ppvr);
				tmpbs = bs;
				token = NULL;
				a.arg = triplp(arg, bs, environ, a, &token);
				ft_putstr("\n");
				if (a.arg)
				{
					t.i = 1;
					if (racc4(a, &environ, &t, path, token))
						return (1);
				}
			}
		}
		// free(try);
	}
	return (0);
}
