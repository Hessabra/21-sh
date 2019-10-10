/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:31:10 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/10 20:51:26 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		lentab(char **tabe)
{
	int			i;

	i = 0;
	while (tabe[i])
		i++;
	return (i);
}

char			**ft_tabjoin(char ***tabe, char *el)
{
	int		inilen;
	char	**new;
	int		i;

	inilen = lentab(*tabe);
	new = (char **)ft_mema(sizeof(char *) * (inilen + 2));
	i = 0;
	while ((*tabe)[i])
	{
		new[i] = ft_strdup((*tabe)[i]);
		ft_strdel(&((*tabe)[i]));
		i++;
	}
	new[i] = ft_strdup(el);
	new[i + 1] = NULL;
	if (tabe && *tabe)
	{
		free(*tabe);
		*tabe = NULL;
	}
	return (new);
}
