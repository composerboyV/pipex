/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:54:33 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/15 16:43:43 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);

char    *find_path(char **envp)
{
    int        i;
    char    *ret_path;

    i = 0;
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH=", envp[i], 5) == 0)
        {
            ret_path = ft_strdup(envp[i] + 5);
            return (ret_path);
        }
        i++;
    }
    return (NULL);
}

char    *get_cmd_argv(char **path, char *cmd)
{
    int        i;
    int        fd;
    char    *path_cmd;
    char    *tmp;

    fd = access(cmd, X_OK);
    if (fd != -1)
        return (cmd);
    path_cmd = ft_strjoin("/", cmd);
    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], path_cmd);
        fd = access(tmp, X_OK);
        if (fd != -1)
        {
            free(path_cmd);
            return (tmp);
        }
        close(fd);
        free(tmp);
        i++;
    }
    free(path_cmd);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
        char    *new_src;
        int             i;

        i = ft_strlen(s);
        new_src = (char *)malloc(sizeof(char) * (i + 1));
        if (!(new_src))
                return (NULL);
        i = 0;
        while (s[i])
        {
                new_src[i] = s[i];
                i++;
        }
        new_src[i] = '\0';
        return (new_src);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *result;
        int             i;
        int             j;

        i = -1;
        result = (char *) malloc(sizeof(char *)
                        * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!(result))
                return (NULL);
        *result = 0;
        while (s1[++i] != '\0')
                result[i] = s1[i];
        j = i;
        i = 0;
        while (s2[i] != '\0')
                result[j++] = s2[i++];
        result[j] = '\0';
        return (result);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        unsigned int    i;

        i = 0;
        if (n == 0)
                return (0);
        while (*s1 == *s2 && i + 1 < n && *s1 != '\0')
        {
                i++;
                s1++;
                s2++;
        }
        return ((unsigned char)*s1 - (unsigned char)*s2);
}
size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}
static void    sub_dup2(int zero, int first)
{
    dup2(zero, 0);
    dup2(first, 1);
}

void    child(t_env p)
{
    p.pid = fork();
    if (!p.pid)
    {
        if (p.idx == 0)
            sub_dup2(p.i_fd, p.pipe_fd[1]);
        else if (p.idx == 1)
            sub_dup2(p.pipe_fd[0], p.o_fd);
        close_pipes(&p);
        if (execve(p.cmd[p.idx].path, p.cmd[p.idx].cmd, p.envp) < 0)
            exit_perror(ERR_CMD, p.result);
    }
}

int    main(int argc, char **argv, char **envp)
{
    t_env    info;

    if (argc != 5)
        usage();
    init_info(&info, argc, argv, envp);
    parse_cmd(&info, argc, argv);
    info.idx = -1;
    while (++(info.idx) < 2)
        child(info);
    close_pipes(&info);
    waitpid(-1, NULL, 0);
    parent_free(&info);
    return (info.result);
}
출처: https://woongtech.tistory.com/entry/42SEOUL-pipex [WOONGTECH:티스토리]
/*
int main(int argc, char **argv, char **envp)
{
    int    i;

    (void)argv;
    i = 0;
    while (envp[i])
    {
        printf("envp[%d] : %s\n", i, envp[i]);
        i++;
    }
}*/
