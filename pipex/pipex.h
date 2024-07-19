/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:48:16 by junkwak           #+#    #+#             */
/*   Updated: 2024/07/19 20:28:22 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct	s_arg;
{
	int	f_content;
	int	c_content;
	char	cmd1;
	char	cmd2;
	char	path;
	char	order1;
	char	order2;
}	t_arg;

char	**ft_ppsplit(char *s, char c);
void	check_error(char *s);

