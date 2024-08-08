/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:48:16 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/25 18:27:31 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct	s_arg;
{
	int	f_content;
	int	c_content;
	char	cmd1;
	char	cmd2;
	char	path;
	char	order1;
	char	order2;
}	t_arg;

char	**ft_ppsplit(char *s, char c);
void	check_error(char *s);
char	**ft_ppsplit(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_ppsplit(char const *s, char c);

# endif

