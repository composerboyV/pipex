/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:47:55 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/19 21:31:39 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	ft_check(char **path, char *cmd)
{
	int	i;
	char	*find;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], cmd);
		if (access(find, X_OK) == 0)
			return (find);
		free(find);
		i++;
	}
	return (0);
}
void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

void	f.c_ps(t_arg *pipex, int fd, char **argv, char **envp)
{
	pipex -> f_content = open(argv[1], O_RDONLY, 0644);
	if (pipex -> f_content == -1)
		ft_error("child error");
	pipex -> order1 = ft_check(pipex -> path, pipex -> cmd1[0]);
	close(fd[0]);
	if (dup2(pipex -> f_content, 0) == -1)
		ft_error("dup2 error");
	if (dup2(fd[1], 1) == -1)
		ft_error("dup2 error");
	close(fd[1]);
	close(pipex -> f_content);
	if (execve(pipex -> order1, pipex -> cmd1, envp) == -1)
	       ft_error("exec error");
}	
		
void	s.c_ps(t_arg *pipex, int fd, char **argv, char **envp)
{
	pipex -> s_content = open (argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex -> s_content == -1)
		ft_error("child error");
	pipex -> order2 = ft_check(pipex -> path, pipex -> cmd2[0])
	close(fd[1]);
	if (dup2(all -> s_content, 0) == -1)
		ft_error("dup2 error");
	if (dup(fd[1], 1) == -1)
		ft_error("dup2 error");
	close(fd[0]);
	close(pipex -> s_content);
	if (execve(pipex -> order1, pipex -> cmd1, envp) == -1)
		ft_error("exec error");
}

void	make_pipex(t_arg pipex, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int	fd[2];
	
	pipe(fd);
	pid1  = fork();
	if (pid1 == -1)
		ft_error("PID error");
	else if (pid1 == 0)
		f.c_ps(&all, fd, argv, envp);
	else
	{
		pid1 = fork();
		if (pid1 == -1)
			ft_error("PID error");
		else if (pid1 == 0)
			s.c_p.s(&all, fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

void	ft_free(char all)
{
	int	i;
	
	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

int	main(int argc, char **argv, **envp)
{
	t_arg	pipex;
	int	i;

	i = 0;
	if (argc != 5)
		ft_error("input error :(");
	pipex.cmd1 = ft_ppsplit(char[2], ' '); // 스플릿체크
	pipex.cmd2 = ft_ppsplit(char[3], ' '); // 스플릿체크
	pipex.path = ft_parsing(envp);
	make_pipex(&pipex, *argv, *envp);
	ft_free(all.cmd1);
	ft_free(all.cmd2);
	ft_free(all.path);
	return (0);
}
