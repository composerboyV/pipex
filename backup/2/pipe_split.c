/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:11:47 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/25 19:50:04 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	a;
	size_t		i;
	
	i = ft_strlen(src);
	a = 0;
	if (size == 0)
		if (size == 0)
			return (i);
	while (src[a] != '\0' && (a + 1) < size)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

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

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
        size_t  i;
        size_t  j;
        char    *c_big;
        char    *c_little;

        c_big = (char *)big;
        c_little = (char *)little;
        if (*c_little == '\0' || c_big == c_little)
                return ((char *)c_big);
        i = 0;
        while (big[i] && i < len)
        {
                j = 0;
                while (c_big[i + j] == c_little[j] && i + j < len)
                {
                        j++;
                        if ((c_little[j]) == '\0')
                                return ((char *)&c_big[i]);
                }
                i++;
        }
        return (NULL);
}

