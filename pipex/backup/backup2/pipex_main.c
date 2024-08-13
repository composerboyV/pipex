/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:17:06 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/13 17:17:07 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_make_pipex(t_arg *pipex, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("PID error", pipex);
	else if (pid1 == 0)
		fc_ps(pipex, fd, argv);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			ft_error("PID error", pipex);
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






int	main(int argc, char **argv, char **envp)
{
	t_arg	pipex;

	if (argc != 5)
		ft_error("input error :(", &pipex);
	pipex.cmd1 = ft_ppsplit(argv[2], ' ');
	pipex.cmd2 = ft_ppsplit(argv[3], ' ');
	pipex.path = ft_parsing(envp);
	ft_make_pipex(&pipex, argv);
	ft_free(&pipex.cmd1);
	ft_free(&pipex.cmd2);
	ft_free(&pipex.path);
	return (0);
}
