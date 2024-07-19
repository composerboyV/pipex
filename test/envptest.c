/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:59:45 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/15 19:03:08 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	while (*envp)
		printf("%s\n", *envp++);
	return (0);
}
