# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junkwak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 18:28:01 by junkwak           #+#    #+#              #
#    Updated: 2024/07/25 18:30:24 by junkwak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./main.c ./maincheck.c ./pipe_split.c

OBJS = ${SRC:.c=.o}

NAME = pipex.a

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	${CC} ${CFLAGS} -c $^
	${AR} ${NAME} $@

.PHONY : all clean fclean re bonus

all:	${NAME}

${NAME}: ${OBJS}

clean :
	${RM} ${OBJS} ${OBJS_BNS}

fclean : clean
