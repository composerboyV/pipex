/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:47:55 by junkwak           #+#    #+#             */
/*   Updated: 2024/08/13 17:15:38 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t ec, size_t es)
{
	char	*res;

	res = malloc(es * ec);
	if (!res)
		return (NULL);
	ft_bzero(res, es * ec);
	return (res);
}

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
 
void	ft_free(char ***all)
{
	int	i;

	if (*all == NULL)
		return ;
	i = 0;
	while ((*all)[i])
	{
		free((*all)[i]);
		i++;
	}
	free((*all));
	*all = NULL;
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
