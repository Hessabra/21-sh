/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 02:17:49 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/20 18:57:53 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*line(char *arg, char **env, int **bs, int quot)
{
	char		*fin;

	if (quot != 1)
		fin = dolor1(arg, env, bs, quot);
	else
		fin = arg;
	return (fin);
}