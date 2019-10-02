/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmanso <helmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:45:35 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/02 01:53:17 by helmanso         ###   ########.fr       */
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

char            *here_doc(char *end, int token, char **env, t_read insert)
{
    char        *buff;
    char        *new;

    new = ft_strdup("");
    ft_putstr(">>\n");
    buff = NULL;
	if (insert.is_quote == -1)
	{
		insert.is_quote = 0;
		return (0);
	}
	else 
		insert.is_quote = 1;
    while ((buff = ft_readline(buff, &insert)))
    {
		if (insert.is_quote == -1)
		{
			insert.is_quote = 0;
			return (0);
		}
		else 
			insert.is_quote = 1;
        if (ft_strequ(buff, end))
            break ;
        new = ft_jandf(new, buff, 1, 1);
	ft_putstr_fd("\n>>\n", 2);
    }
    ft_putchar('\n');
    free(buff);
    buff = new;
    if (token == 12)
        new = dolor2(new, env);
    free(buff);
    return (new);
}

char		**use_heredoc(int *ppvr, int **token, char ***arg, char **env, t_read insert)
{
	char	**strings;
	char	*stop_heredo;
	int		isdolar;
	int		nbr_heredoc;
	int		i;
	int		j;

	nbr_heredoc = how_many_heredoc(ppvr, token);
	if (nbr_heredoc)
	{
		strings = (char **)malloc(sizeof(char *) * (nbr_heredoc + 1));
		strings[nbr_heredoc] = NULL;
		i = 0;
		j = 0;
		while (i < nbr_heredoc)
		{
			while (ppvr[j] > -1)
				j++;
			isdolar = stop_heredoc(token[j], arg[j], &stop_heredo);
			strings[i] = here_doc(stop_heredo, isdolar, env, insert);
			j++;
			i++;
		}
		return (strings);
	}
	return (NULL);
}