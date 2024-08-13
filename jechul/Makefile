# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junkwak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 18:28:01 by junkwak           #+#    #+#              #
#    Updated: 2024/08/13 20:27:55 by junkwak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./main.c ./main2.c ./pipex_check.c ./pipe_split.c

OBJS = ${SRC:.c=.o}

NAME = pipex

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

.PHONY : all clean fclean re bonus

all:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re:	fclean all
