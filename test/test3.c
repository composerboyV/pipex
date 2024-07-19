/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:24:41 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 18:40:25 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	pid_t	pid;
	int	x;
	x = 0;
	pid = fork();
	printf("PID :%d\n", pid);
	if (pid > 0) //부모코드
	{
		x = 1;
		printf("부모 PID : %ld, x : %d,  pid : %d\n",(long)getpid(), x, pid);
		printf("부모 pid%d \n", pid);
	}
	else if(pid == 0) //자식코드
	{
		x = 2;
		printf("자식 PID : %ld, x : %d\n", (long)getpid(), x);
		printf("자식 PID : %d \n", pid);
	}
	else // for실패
	{
		printf("fork Fail! \n");
		return -1;
	}
	printf("pid %d \n", pid);
	return (0);
}
