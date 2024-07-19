/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:03:29 by junkwak           #+#    #+#             */
/*   Updated: 2024/06/29 06:04:43 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*pathname = "./hello.txt";
	int	mode = R_OK | W_OK;
	if (access (pathname, mode) == 0) {
		printf("읽고 쓸 수 있습니다.");
	}
	else	{
		printf("권한이 없거나 존재하지 않습니다.");
	}
}
