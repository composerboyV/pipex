/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:21:30 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/01 16:22:23 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	mode;

	mode = F_OK;
	if (!access("test.txt", mode))
		printf("File is existing\n");
	else
		printf("File is not existing\n");
	return (0);
}
