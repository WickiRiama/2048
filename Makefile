# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:39:02 by mriant            #+#    #+#              #
#    Updated: 2022/03/19 12:05:16 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048

SRCS = ${addprefix srcs/, \
	main.c}

OBJS = ${patsubst srcs/%.c, build/%.o, ${SRCS}}

DEPS = ${patsubst srcs/%.c, build/%.d, ${SRCS}}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -MMD
LFLAGS = -lncurses -lncurses_g

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

build/%.o: srcs/%.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS}
	rm -rf ${DEPS}
	rm -rf build

fclean: clean
	rm -rf ${NAME}
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}