/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:39:34 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/05 16:44:37 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	rc;

	printf("hello world (pid:%d)\n", (int) getpid());
	rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("hello, I am child (pid:%d)\n", (int) getpid());
	}
	else
	{
		printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
	}
	return (0);
}
