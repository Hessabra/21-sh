/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:45:35 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/06 05:22:29 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

int			how_many_heredoc(int *ppvr, int **token)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (ppvr[i] != 9)
	{
		if (ppvr[i] < -1 && ppvr[i] > -5)
		{
			j = 0;
			while (token[i][j] > -1)
			{
				(token[i][j] == 7) ? count++ : count;
				j++;
			}
		}
		i++;
	}
	return (count);
}

int			nbr_heredocppvr(int *token)
{
	int		result;

	result = 0;
	while (*token != -1)
	{
		if (*token == 7)
			result++;
		token++;
	}
	return (result);
}

int			stop_heredoc(int *token, char **arg, char **stop_heredo, int nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_entier(token[i]) != 12)
	{
		i++;
		if (ft_entier(token[i]) == 12)
		{
			j++;
			if (j < nbr)
				i++;
		}
	}
	*stop_heredo = arg[i];
	return (token[i]);
}

char		*here_doc(int token, char *end, char **env, t_read insert)
{
	char	*buff;
	char	*new;

	new = ft_strdup("");
	ft_putstr(">>\n");
	buff = NULL;
	g_ctrl_dsig = 1;
	while ((buff = ft_readline(buff, &insert)) && g_ctrl_dsig && g_herdoc_sig)
	{
		if (ft_strequ(buff, end))
			break ;
		new = ft_jandf(new, buff, 1, 1);
		new = ft_jandf(new, "\n", 1, 0);
		if (g_herdoc_sig)
			ft_putstr_fd("\n>>\n", 2);
	}
	ft_putchar('\n');
	//free(buff);
	buff = new;
	if (token == 12)
		new = dolor2(new, env);
	//free(buff);
	return (new);
}

char		**use_heredoc(t_ppvr a, int **token, char **env, t_read insert)
{
	t_heredoc	h;
	char		**strings;
	char		*stop_heredo;
	int			i;
	int			j;

	h.nbr = how_many_heredoc(a.ppvr, token);
	if (h.nbr)
	{
		strings = (char **)malloc(sizeof(char *) * (h.nbr + 1));
		strings[h.nbr] = NULL;
		init_here_doc(&i, &j, &(h.fct));
		while (g_herdoc_sig && i < h.nbr)
		{
			while ((a.ppvr)[j] > -1)
				j++;
			h.fct++;
			h.token = stop_heredoc(token[j], (a.arg)[j], &stop_heredo, h.fct);
			strings[i] = here_doc(h.token, stop_heredo, env, insert);
			lastif_here_doc(&(h.fct), &i, &j, token[j]);
		}
		return (strings);
	}
	return (NULL);
}
