/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:42:40 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 18:43:59 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
if(pid == 0) 
    pid = getpid(); /* child's pid on child process*/
else if(pid > 0)
	; /* pid already indicates child's pid */
else /* fork() failed */
    ;
}
/***********************
* while(1) sleep(INFINITE);
***********************/

