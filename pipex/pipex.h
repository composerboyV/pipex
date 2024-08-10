/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:48:16 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/08 19:10:26 by junkwak          ###   ########.fr       */
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

typedef struct	s_arg
{
	int	f_content;
	int	s_content;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*order1;
	char	*order2;
}	t_arg;

char	**ft_ppsplit(char *s, char c);
void	check_error(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_parsing(char **envp);
char	*ft_check(char **ft_path, char *cmd);
void	ft_error(char *s);
void	fc_ps(t_arg *pipex, int *fd, char **argv);
void	sc_ps(t_arg *pipex, int *fd, char **argv);
void	ft_make_pipex(t_arg *pipex, char **argv, char **envp);
void	*ft_calloc(size_t ec, size_t es);
void	ft_bzero(void *s, size_t n);

#endif

