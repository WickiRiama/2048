# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:39:02 by mriant            #+#    #+#              #
#    Updated: 2022/03/20 15:41:47 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048

RAW_SRCS = main.c \
		   menu.c \
		   add_number.c \
		   move/left2.c \
		   move/right2.c \
		   move/down2.c \
		   move/up2.c \
		   graphics/draw_numbers.c \
		   graphics/init_grid.c 

SRCS = ${addprefix srcs/, ${RAW_SRCS}}

OBJS = ${patsubst srcs/%.c, build/%.o, ${SRCS}}

DEPS = ${patsubst srcs/%.c, build/%.d, ${SRCS}}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -I./libft -MMD
LFLAGS = -lncurses -L./libft -lft

LIBFT = libft/libft.a

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${LIBFT}:
	make -s -C libft

build/%.o: srcs/%.c
	@mkdir -p build/move
	@mkdir -p build/graphics
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS}
	rm -rf ${DEPS}
	rm -rf build
	make -s -C libft clean

fclean: clean
	rm -rf ${NAME}
	make -s -C libft fclean

re: fclean all
test:	all
		./2048
.PHONY: all clean fclean re

-include ${DEPS}
