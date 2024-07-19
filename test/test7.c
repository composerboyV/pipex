/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:19:23 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/01 16:20:16 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	
	printf("error : %s\n", strerror(errno));
	close(fd);
	printf("error : %s", strerror(errno));
	return (0);
}
