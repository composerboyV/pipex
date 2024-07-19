/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:13:21 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/11 18:20:57 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
# ifndef BUFSIZE
# define BUFSIZE 1024
# endif
int	main(void)
{
	int	fd1[2];
	int	fd2[2];
	char	buffer[BUFSIZE];
	pid_t	pid;

	if (pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		printf("pipe error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		printf("fork() error");
		exit(1);
	}
	if (pid == 0)
	{
		write(fd1[1], "(자식에서 입력)\n", 25);
		read(fd2[0], buffer, 25);
		printf("\n자식출력: %s\n", buffer);
	}
	else
	{
		write(fd2[1], "(부모에서 입력)", 25);
		read(fd1[0], buffer, BUFSIZE);
		printf("\n부모출력: %s\n", buffer);
	}
	return (0);
}
