/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:47:55 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/08 19:14:49 by junkwak          ###   ########.fr       */
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
			//printf("now envp: %s\n", envp[i]);
			return (ft_ppsplit(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

char	*ft_check(char **path, char *cmd)
{
	int	i;
	char	*find;
	char	*full_cmd;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], "/");
		full_cmd = ft_strjoin(find, cmd);
		if (access(full_cmd, F_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (0);
}
void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

void	fc_ps(t_arg *pipex, int *fd, char **argv)
{
	char	*f = NULL;
	pipex -> f_content = open(argv[1], O_RDONLY, 0644);
	// printf("path : %d\n", pipex -> f_content);
	if (pipex -> f_content == -1)
		ft_error("child error f.c_ps1");
	// printf("path : %s\n", pipex -> path[0]);
	pipex -> order1 = ft_check(pipex -> path, pipex -> cmd1[0]);
	if (!(pipex -> order1))
		ft_error("command not found fc_ps1-1");
	//printf("order1 : %s\ncmd1 : %s\n", pipex -> order1, pipex-> cmd1[0]);
	//printf("order1 : %s\ncmd1 : %s\n", pipex -> path[0], pipex-> cmd1[0]);
	close(fd[0]);
	if (dup2(pipex -> f_content, 0) == -1)   //dup2(pipex -> s_content, 0) (fd[1], 0)
		ft_error("dup2 error fc 2");
	if (dup2(fd[1],1) == -1) // (pipex -> s_content, 1)
		ft_error("dup2 error fc3");
	// if (dup2(pipex -> f_content, 0) == -1)
	// 	ft_error("dup2 error f.c_ps 2");
	// if (dup2(fd[1], 1) == -1)
	// 	ft_error("dup2 error f.c_ps 3");
	close(fd[1]);
	close(pipex -> f_content);
	if (execve(pipex -> order1, pipex -> cmd1, &f) == -1)
	//char	*prog = "/bin/ls";
	//char	*pass[] = {"ls", NULL};
	       ft_error("exec error f.c 4");
}	
		
void	sc_ps(t_arg *pipex, int *fd, char **argv)
{
	//char	*f = NULL;
	pipex -> s_content = open (argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex -> s_content == -1)
		ft_error("child error sc 1");
	pipex -> order2 = ft_check(pipex -> path, pipex -> cmd2[0]);
	if (!pipex -> order2)
		ft_error("command not found sc1-1");
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)   //dup2(pipex -> s_content, 0) 
		ft_error("dup2 error sc 2");
	if (dup2(pipex -> s_content, 1) == -1) // fd[0]
		ft_error("dup2 error sc3");
	close(fd[0]);
	close(pipex -> s_content);
	if (execve(pipex -> order2, pipex -> cmd2, NULL) == -1)
		ft_error("exec error sc4");
}

void	ft_make_pipex(t_arg *pipex, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int	fd[2];
	
	if (!envp[0][0])
		return ;
	pipe(fd);
	pid1  = fork();
	if (pid1 == -1)
		ft_error("PID error");
	else if (pid1 == 0)
		fc_ps(pipex, fd, argv);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			ft_error("PID error");
		else if (pid2 == 0)
			sc_ps(pipex, fd, argv);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid (pid1, NULL, 0);
			waitpid (pid2, NULL, 0);
		}
	}
}

void	ft_free(char **all)
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

int	main(int argc, char **argv,char **envp)
{
	t_arg	pipex;
	
	if (argc != 5)
		ft_error("input error :(");
	pipex.cmd1 = ft_ppsplit(argv[2], ' '); // 스플릿체크
	pipex.cmd2 = ft_ppsplit(argv[3], ' '); // 스플릿체크
	pipex.path = ft_parsing(envp);
	ft_make_pipex(&pipex, argv, envp);
	ft_free(pipex.cmd1);
	ft_free(pipex.cmd2);
	ft_free(pipex.path);
	return (0);
}
