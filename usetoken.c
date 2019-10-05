/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usetoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:19:13 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/05 00:36:41 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usetoken.h"

int				cmdcl(char **args, int *token, int c)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (args[i])
	{
		if (token[i] == c)
			result++;
		i++;
	}
	return (result);
}

void			chack(char **args, int **token)
{
	int			i;

	i = 0;
	while (args[i])
	{
		if ((*token)[i] == 10 && !isint(args[i]))
			(*token)[i] = 11;
		if ((*token)[i] == 9 && !isint(args[i]))
			(*token)[i] = 0;
		i++;
	}
}

void			zappi(int *token, int *i)
{
	while (token[*i] == 0)
		(*i)++;
}

char			**usetoken(char **args, int **token)
{
	int			i;
	int			j;
	int			len;
	char		**cmd;

	chack(args, token);
	len = cmdcl(args, *token, 0);
	cmd = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	j = 0;
	while (args[i])
	{
		if ((*token)[i] == 0)
		{
			cmd[j] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 1));
			ft_strcpy(cmd[j], args[i]);
			j++;
		}
		i++;
	}
	cmd[j] = NULL;
	return (cmd);
}

int				checkfd(int fd, char *amb, int x)
{
	if (x == 0 && read(fd, NULL, 0) == -1)
	{
		ft_putendl_fd("21sh: fd: bad file descriptor", 2);
		return (0);
	}
	else if (x == 2 && write(fd, NULL, 0) == -1)
	{
		ft_putendl_fd("21sh: fd: bad file descriptor", 2);
		return (0);
	}
	else if (x == 1)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd(amb, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
		return (0);
	}
	return (1);
}
