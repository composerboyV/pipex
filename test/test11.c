/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:01:54 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/05 17:05:11 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	rc;
	printf("hello world (pid:%d)\n", (int) getpid());
	rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork failded\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		char	*myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("p3.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		printf("this shouldn`t print out");
	}
	else
	{
		int wc = wait(NULL);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
	}
	return (0);
}

