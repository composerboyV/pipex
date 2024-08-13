# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junkwak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 18:28:01 by junkwak           #+#    #+#              #
#    Updated: 2024/08/11 00:57:54 by junkwak          ###   ########.fr        #
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
	${CC} ${CFLAGS} -c $^
	${AR} ${NAME} $@

.PHONY : all clean fclean re bonus

all:	${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME}.a $^
	${CC} ${CFLAGS} ${OBJS} ${NAME}.a -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} ${NAME}.a

re:	fclean all
