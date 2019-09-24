/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdira.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:56:44 by hessabra          #+#    #+#             */
/*   Updated: 2019/04/28 23:41:21 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdi.h"

void			envch(char ***env)
{
	char		*var;
	char		**cha;

	var = (char *)malloc(sizeof(char) * 1000);
	cha = (char **)malloc(sizeof(char *) * 4);
	cha[0] = ft_strdup("setenv");
	cha[1] = ft_strdup("PWD");
	var = getcwd(var, 100);
	cha[2] = ft_strdup(var);
	cha[3] = NULL;
	stenv(cha, &(*env));
	dfre(cha);
	free(var);
}

void			envech(char ***env, char *tmp)
{
	char		**cha;

	cha = (char **)malloc(sizeof(char *) * 4);
	cha[0] = ft_strdup("setenv");
	cha[1] = ft_strdup("OLDPWD");
	cha[2] = ft_strdup(tmp);
	cha[3] = NULL;
	stenv(cha, &(*env));
	dfre(cha);
}

int				erro(char *arg)
{
	struct stat	td;

	lstat(arg, &td);
	if (S_ISDIR(td.st_mode) && access(arg, R_OK))
		ft_printf("cd: permission denied: ");
	else if (S_ISREG(td.st_mode))
		ft_printf("cd: Not a directory: ");
	else
		ft_printf("cd: no such file or directory: ");
	ft_printf("%s\n", arg);
	return (0);
}
