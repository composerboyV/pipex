/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:00:25 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/11 17:23:59 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//int	access(const char *path, int mode)

int	main(void)
{
	char	*file_name = "./test.c";
	
	if (0 == access ( file_name, F_OK)) {
		printf("%s 파일이 있습니다.\n", file_name);

	if (0 == access ( file_name, R_OK | W_OK)) {
		printf("읽거나 쓰기가 가능합니다.\n");
	} else {
		printf("읽지 못하거나 내용을 변경할 수 없습니다.\n");
	}
	}
}
	
