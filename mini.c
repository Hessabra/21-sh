/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 05:12:49 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/15 16:48:10 by hessabra         ###   ########.fr       */
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
		ft_strdel(&tmp);
	}
	return (1);
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

	init_main(&(tp.insert), &(t.i), &(m.try), &(a.arg));
	environ = aloc(environ);
	while (1)
	{
		init_main2(&(m.j), &(tp.path));
		m.try = ft_readline(m.try, &(tp.insert));
		if (m.try)
		{
			dprintf(2, "read == |%s|", m.try);
			effectornot(&(tp.bs), m.try);
			a.nbr_quot = nbr_quote(m.try, tp.bs);
			dprintf(2, "hello1\n");
			if (!ft_parite((a.nbr_quot).d) || !ft_parite((a.nbr_quot).s))
				m.j = quotiwhile(a.nbr_quot, &(m.try), &(tp.bs), &(tp.insert));
			dprintf(2, "hello2\n");
			ft_add_history(m.try, &(tp.insert));
			dprintf(2, "hello3\n");
			(exec_input(&m, &tp, &a, environ)) ?
				exec_input_2(&(t.i), a, &environ, tp) : ft_nbrdel(&(tp.bs));
			dprintf(2, "hello6\n");
		}
		ft_strdel(&(m.try));
	}
	return (0);
}
