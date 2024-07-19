/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:21:31 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 18:22:36 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	int	x = 1;

	pid = fork();
	if (pid == 0)
	{
		printf("child: x = %d\n", ++x);
		exit(0);
	}
	printf("parent: x = %d\n", --x);
	exit(0);
}
