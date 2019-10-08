/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:12:49 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/08 03:01:25 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				execve2(char **arg, char **environ, char *path)
{
	int			x;
	char		*tmp;

	x = ft_know(environ, "PATH");
	if (!(path = checking(arg[0], (environ[x]) + 5, x)) && arg[0])
	{
		unknown_cmd(arg[0]);
		return (0);
	}
	else if (ft_strequ(path, arg[0]) && (execve(arg[0], arg, environ) == -1))
	{
		unknown_cmd(arg[0]);
		return (0);
	}
	else
	{
		tmp = ft_jandf(ft_strjoin(path, "/"), arg[0], 1, 0);
		if (execve(tmp, arg, environ) == -1)
		{
			unknown_cmd(arg[0]);
			exit(0);
		}
		free(tmp);
	}
	return (1);
}

static int		racc4(t_ppvr a, char ***env, t_triplp tp)
{
	t_racc4_p	rp;

	rp.string_heredoc = use_heredoc(a, tp.token, *env, tp.insert);
	if (g_herdoc_sig)
	{
		rp.i = 0;
		while (a.arg[rp.i])
		{
			open_fds();
			g_is_pipe = 1;
			if (ft_entier(a.ppvr[rp.i]) == 1 || a.ppvr[rp.i] == -4)
				pipe_main(&a, &rp, tp.token, *env);
			else if (a.ppvr[rp.i] == -3 || a.ppvr[rp.i] == -2)
				usered(a.arg[rp.i], (tp.token)[rp.i], env,
					&(rp.string_heredoc));
			else if (builtin_1(a.arg[rp.i], env) && builtin_2(a.arg[rp.i], env)
				&& a.arg[rp.i][0])
				nexec_main(*env, tp.path, a.arg[rp.i]);
			(rp.i)++;
		}
	}
	g_herdoc_sig = 1;
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
	t_triplp	tp;
	t_dolor		t;
	extern char	**environ;
	t_main		m;

	environ = aloc(environ);
	ft_setterm();
	tp.insert.indexfor_history = 0;
	t.i = 0;
	m.try = NULL;
	g_ctrl_dsig = 0;
	a.arg = NULL;
	tp.insert.topast = ft_memalloc(LINE_MAX);
	while (1)
	{
		// if (a.arg)
		// 	tfree(a.arg);
		g_is_pipe = 1;
		g_pid_cmd = 0;
		g_herdoc_sig = 1;
		m.j = 1;
		tp.path = NULL;
		prompt();
		m.try = ft_readline(m.try, &(tp.insert));
		if (m.try)
		{
			effectornot(&(tp.bs), m.try);
			a.nbr_quot = nbr_quote(m.try, tp.bs);
			if (!ft_parite((a.nbr_quot).d) || !ft_parite((a.nbr_quot).s))
				m.j = quotiwhile(a.nbr_quot, &(m.try), &(tp.bs), &(tp.insert));
			ft_add_history(m.try, &(tp.insert));
			if (m.j && synerr(m.try, tp.bs))
			{
				tp.arg = ft_ppvr(m.try, tp.bs, &a.ppvr);
				m.tmpbs = tp.bs;
				tp.token = NULL;
				a.arg = triplp(&tp, tp.bs, environ, a);
				free(tp.bs);
				ft_putstr("\n");
				if (a.arg)
				{
					t.i = 1;
					if (racc4(a, &environ, tp))
						return (1);
				}
			}
		}
		free(m.try);
	}
	return (0);
}
