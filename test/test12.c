/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:04:02 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/19 16:04:03 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

