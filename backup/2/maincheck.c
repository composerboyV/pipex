/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:21:00 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/25 19:48:36 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(char **result)
{
	int 	i;
	
	i = 0;
	while (result[i] != 0)
		free(result[i++]);
	free(result);
}

static size_t	ft_count(char const *len , char a)
{
	size_t	ct;
	
	ct = 0;
	while (*len)
	{
		if (*len == a)
			len++;
		else
		{
			ct++;
			while (*len != a && *len)
				len++;
		}
	}
	return (ct);
}


static int	ft_find(char const *str, char c, char **result, int i)
{
	size_t	len;

	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len = 0;
			while ((str[len] != 0) && (str[len] != c))
				len++;
			result[i] = (char *)malloc(sizeof(char *) * (len + 1));
			if (!(result[i]))
			{
				ft_free(result);
				return (-1);
			}
			ft_strlcpy (result[i++], str, len + 1);
			while ((*str != 0) && *str != c)
				str++;
		}
	}
	return (1);
}



char	**ft_ppsplit(char *s, char c)
{
	char	**result;
	size_t	len;

	len = ft_count(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!(result))
		return (NULL);
	if ((ft_find(s, c, result , 0)) == -1)
		return (NULL);
	return (result);
}

