/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:27:45 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/16 16:36:59 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int	main(int ac, char **av, char envp)
{
	//fd를 담아둘 구조체를 하나 선언
	t_arg	arg;
	
	if (ac != 5)
		print_std_error("argument error");
	//infile과 outfile을 open 한다. open이 성공이 아니면 (return -1일때)에러처리
	arg.infile = open(av[1], O_RDONLY);
	if (arg.infile == -1)
		print_std_error("infile error");
	arg.outfile = open(av[4], O_RDWR | OCREAT | O_TRUN, 0644);
	if (arg.infile == -1)
		print_std_error("outfile error");
	//환경변수에서 PATH를 찾아서 PATH= 이후 글자를 ft_split으로 : 로 나눠 저장
	arg.path = get_path_envp(envp);
	//command 를 가져온 다음 실행가능한 PATH를 확인한다.
	arg.cmd_arg1 = ft_split(av[2], ' ');
	arg.cmd_arg2 = ft_split(av[3], ' ');
	if (arg.cmd_arg1 == NULL || arg.cmd_arg2 == NULL)
		print_std_error("cmd missing error");
	arg.cmd1 = get_cmd_argv(arg.path, arg.cmd_arg1[0]);
	arg.cmd2 = get_cmd_argv(arg.apth, arg.cmd_arg2[0]);
	if (arg.cmd1 == NULL || arg.cmd2 == NULL)
		print_std_error("path or cmd error");
	printf("%s, %s \n", arg.cmd1, arg.cmd2);
}
char	get_cmd_argv(char **path, char *cmd)
{
	int	i;
	int	fd;
	char	*path_cmd;
	char	*tmp;

	path_cmd = ft_strjoin("/", cmd);
	fd = 0;
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

