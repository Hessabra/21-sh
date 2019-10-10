/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   know.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:02:28 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/10 20:37:02 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_know(char **env, char *name)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		tmp = ft_sub2char(env[i], '=');
		if (ft_strequ(tmp, name))
			return (i);
		ft_strdel(&tmp);
		i++;
	}
	return (-1);
}
