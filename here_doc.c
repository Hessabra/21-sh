/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:45:35 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/04 00:19:17 by helmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int			stop_heredoc(int *token, char **arg, char **stop_heredo)
{
	int		i;

	i = 0;
	while (ft_entier(token[i]) != 12)
		i++;
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
	while ((g_ctrl_dsig && g_herdoc_sig) && (buff = ft_readline(buff, &insert)))
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

char		**use_heredoc(int *ppvr, int **token, char ***arg, char **env, t_read insert)
{
	char	**strings;
	char	*stop_heredo;
	int		nbr;
	int		i;
	int		j;

	nbr = how_many_heredoc(ppvr, token);
	if (nbr)
	{
		strings = (char **)malloc(sizeof(char *) * (nbr + 1));
		strings[nbr] = NULL;
		i = 0;
		j = 0;
		while (g_herdoc_sig && i < nbr)
		{
			while (ppvr[j] > -1)
				j++;
			strings[i] = here_doc(stop_heredoc(token[j], arg[j], &stop_heredo),
					stop_heredo, env, insert);
			j++;
			i++;
		}
		return (strings);
	}
	return (NULL);
}
