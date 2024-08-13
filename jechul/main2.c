/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:53:22 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/13 20:51:52 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parsing(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_ppsplit(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

char	*ft_check(char **path, char *cmd)
{
	int		i;
	char	*find;
	char	*full_cmd;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], "/");
		full_cmd = ft_strjoin(find, cmd);
		free(find);
		if (access(full_cmd, F_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (0);
}

void	ft_error(char *s, t_arg *pipex)
{
	ft_free(&pipex -> cmd1);
	ft_free(&pipex -> cmd2);
	ft_free(&pipex -> path);
	perror(s);
	exit(1);
}

void	fc_ps(t_arg *pipex, int *fd)
{
	pipex -> order1 = ft_check(pipex -> path, pipex -> cmd1[0]);
	if (!(pipex -> order1))
		ft_error("command not found fc_ps1-1", pipex);
	close(fd[0]);
	if (dup2(pipex -> f_content, 0) == -1)
		ft_error("dup2 error fc 2", pipex);
	if (dup2(fd[1], 1) == -1)
		ft_error("dup2 error fc3", pipex);
	close(fd[1]);
	close(pipex -> f_content);
	if (execve(pipex -> order1, pipex -> cmd1, NULL) == -1)
		ft_error("exec error f.c 4", pipex);
}	

void	sc_ps(t_arg *pipex, int *fd)
{
	pipex -> order2 = ft_check(pipex -> path, pipex -> cmd2[0]);
	if (!pipex -> order2)
		ft_error("command not found sc1-1", pipex);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		ft_error("dup2 error sc 2", pipex);
	if (dup2(pipex -> s_content, 1) == -1)
		ft_error("dup2 error sc3", pipex);
	close(fd[0]);
	close(pipex -> s_content);
	if (execve(pipex -> order2, pipex -> cmd2, NULL) == -1)
		ft_error("exec error sc4", pipex);
}
