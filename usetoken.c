/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usetoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:19:13 by hessabra          #+#    #+#             */
/*   Updated: 2019/09/24 21:32:24 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# define PIPE_WRITE 1
# define PIPE_READ 0

int         cmdcl(char **args, int *token, int c)
{
    int     i;
    int     result;

    i = 0;
    result = 0;

    while (args[i])
    {
        if (token[i] == c)
            result++;
        i++;
    }
    return(result);
}

void        chack(char **args, int **token)
{
    int    i;

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

void        zappi(int *token, int *i)
{
    while (token[*i] == 0)
        (*i)++;
}

char        **usetoken(char **args, int **token)
{
    int     i;
    int     j;
    int     len;
    char    **cmd;

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

int         checkfd(int fd, char *amb, int x)
{
    if (x == 0 && read(fd, NULL, 0) == -1)
    {
        ft_putstr_fd("21sh: fd: bad file descriptor\n", 2);
        return (0);
    }
    else if (x == 2 && write(fd, NULL, 0) == -1)
    {
        ft_putstr_fd("21sh: fd: bad file descriptor\n", 2);
        return (0);
    }
    else if (x == 1)
    {
        ft_putstr_fd("21sh: ", 2);
        ft_putstr_fd(amb, 2);
        ft_putstr_fd(": ambiguous redirect\n", 2);
        return (0);
    }
    return(1);
}

char            *here_doc(char *end, int token, char **env)
{
    char        *buff;
    t_read      insert;
    char        *new;

    new = ft_strdup("");
    ft_putstr(">>\n");
    buff = NULL;
    while ((buff = ft_readline(buff, &insert)))
    {
        if (ft_strequ(buff, end))
            break ;
        new = ft_jandf(new, buff, 1, 1);
        ft_putstr("\n>>\n");
    }
    ft_putchar('\n');
    free(buff);
    buff = new;
    if (token == 12)
        new = dolor2(new, env);
    free(buff);
    return (new);
}

void            getnresetfd(int i)
{
    static int  fd[3];

    if (i == 0)
    {
        fd[0] = dup(0);
        fd[1] = dup(1);
        fd[2] = dup(2);
    }
    else if (i == 1)
    {
        dup2(fd[0], 0);
        dup2(fd[1], 1);
        dup2(fd[2], 2);
    }
}

void            usered(char **args, int *token, char ***env)
{
    int         fd;
    int         fdw;
    int         fdhd;
    int         i;
    int         fd_p[2];
    pid_t       pid_fork;
    char        *path;
    char        **cmd;
    char        *new;
    t_dolore    k;

    i = 0;
    k.i = 0;
    k.x = 0;
    cmd = usetoken(args, &token);
    new = NULL;

    getnresetfd(0);
    while (args[i])
    {
        fd = 1;
        zappi(token, &i);
        (token[i] >= 6 && token[i] <= 8) ? (fd = 0) : fd;
        if (token[i] == 9)
        {
            fd = ft_atoi(args[i]);
            i++;
        }
        if (token[i] == 8 && token[i + 1] == 11)
            checkfd(fd, args[i + 1], 1);
        else if (token[i] >= 1 && token[i] <= 5)
        {
            if (token[i + 1] == 11 && token[i] != 4
                && (fdw = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
                ft_putstr_fd("File error\n", 2);
            else if (token[i + 1] == 11 && token[i] == 4
                && (fdw = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
                ft_putstr_fd("File error\n", 2);
            else
            {
                (token[i + 1] == 10) ? fdw = ft_atoi(args[i + 1]) : fdw;
                if (token[i] == 1 || token[i] == 2 || token[i] == 4)
                    dup2(fdw, fd);
                if (token[i] == 3)
                {
                    dup2(fdw, 1);
                    dup2(fdw, 2);
                }
                if (token[i] == 5)
                    close(fd);
            }
        }
        else if (token[i] >= 6 && token[i] <= 8)
        {
            if (token[i] == 6 && (fdw = open(args[i + 1], O_RDONLY)) == -1)
                ft_putstr_fd("File error\n", 2);
            (token[i] == 8) ? fdw = ft_atoi(args[i + 1]) : fdw;
            if (token[i] != 7 && !checkfd(fdw, NULL, 0))
                dup2(fdw, fd);
            if (token[i] == 7)
            {
                if (new != NULL)
                    free(new);
                fdhd = fd;
                new = here_doc(args[i + 1], token[i + 1], *env);
            }
        }
        i++;
    }
    if (cmd != NULL)
    {
        if ((ft_strequ(cmd[0], "exit") || ft_strequ(cmd[0], "cd") ||
        ft_strequ(cmd[0], "setenv") || ft_strequ(cmd[0], "unsetenv") ||
        ft_strequ(cmd[0], "echo")) && racco1(cmd, env))
            racco3(cmd, env);
        else
        {
            if (new)
                if (pipe(fd_p) < 0)
                {
                    ft_putstr_fd("\nOoupsy pipe c \n", 2);
                    exit(1);
                }
            pid_fork = fork();
            if (pid_fork == 0)
            {
                if (new)
                {
                    close(fd_p[PIPE_WRITE]);
                    close(0);
                    dup2(fd_p[PIPE_READ], 0);
                }
                path = NULL;
                execve2(cmd, *env, path);
                exit(0);
            }
            else
            {
                close(fd_p[PIPE_READ]);
                ft_putstr_fd(new, fd_p[PIPE_WRITE]);
                close(fd_p[PIPE_WRITE]);
                waitpid(pid_fork, NULL, 0);
            }
        }
    }
    getnresetfd(1);
}