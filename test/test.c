/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:42:09 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 05:44:45 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	pid_t	pid;

	pid = fork();
	
	if (pid == -1)
	{
		printf("fork() error");
		exit(1);
	}
	if (pid == 0)
	{
		printf("\n****자식프로세스****\n");
		printf("변수pid값: %d\n", pid);
		printf("자식피드: %d\n", getpid());
	}
	else
	{
		printf("\n****부모프로세스****\n");
		printf("변수pid값: %d\n", pid);
		printf("부모피드: %d\n", getpid());
	}
	return(0);
}
