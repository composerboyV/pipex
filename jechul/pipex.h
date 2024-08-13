/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:48:16 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/13 17:16:24 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct s_arg
{
	int		f_content;
	int		s_content;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*order1;
	char	*order2;
}	t_arg;

char	**ft_ppsplit(char *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_parsing(char **envp);
char	*ft_check(char **ft_path, char *cmd);
void	ft_error(char *s, t_arg *pipex);
void	fc_ps(t_arg *pipex, int *fd);
void	sc_ps(t_arg *pipex, int *fd);
void	ft_make_pipex(t_arg *pipex);
void	*ft_calloc(size_t ec, size_t es);
void	ft_bzero(void *s, size_t n);
void	ft_free(char ***result);

#endif
