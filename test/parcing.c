/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:06:43 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/15 19:09:14 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**get_cmds(int argc, char **argv)
{
	char **cmds;
	int	i;
	int	j;

	i = -1;
	cmds = (char **)malloc(sizeof(char *) * (argc - 1));
	if (!cmds)
		return (0);
	while ( ++i + 2 < argc - 1)
	{
		j = 1;
		cmds[i] = (char *)malloc(sizeof(char) * (ft_strlen(argv[i + 2]) + 2));
		if (!cmds[i])
			return (0);
		cmds[i][0] = '/';
		while (*argv[i + 2])
			cmds[i][j++] = *argv[i + 2]++;
		cmds[i][j] = 0;
	}
	cmds[i] = 0;
	return (cmds);
}
