/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 00:22:03 by hessabra          #+#    #+#             */
/*   Updated: 2019/10/07 00:32:36 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void        open_fds(void)
{
    DIR             *stream;
    struct dirent   *entry;
    int             fd;

    stream = opendir("/dev/fd");
    while ((entry = readdir(stream)))
    {
        if ((fd = ft_atoi(entry->d_name)) > 2)
            close(fd);
    }
    closedir(stream);
}