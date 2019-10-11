/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 03:45:52 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/11 03:50:54 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		racc4(t_ppvr a, char ***env, t_triplp tp)
{
	t_racc4_p	rp;
	char		**tmp;

	rp.string_heredoc = use_heredoc(a, tp.token, *env, tp.insert);
	tmp = rp.string_heredoc;
	if (g_herdoc_sig)
	{
		rp.i = -1;
		while (a.arg[++(rp.i)])
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
		}
	}
	dfre(tmp);
	ft_nbrdel(&(a.ppvr));
	g_herdoc_sig = 1;
}

int				exec_input(t_main *m, t_triplp *tp, t_ppvr *a, char **environ)
{
	if (m->j && synerr(m->try, tp->bs))
	{
		tp->arg = ft_ppvr(m->try, tp->bs, &(a->ppvr));
		m->tmpbs = tp->bs;
		tp->token = NULL;
		a->arg = triplp(tp, tp->bs, environ, *a);
		ft_nbrdel(&(tp->bs));
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

void			exec_input_2(int *i, t_ppvr a, char ***env, t_triplp tp)
{
	if (a.arg)
	{
		*i = 1;
		racc4(a, env, tp);
		tfree(a.arg);
		dfree_int(tp.token);
	}
}
