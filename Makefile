# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 17:17:14 by minkim            #+#    #+#              #
#    Updated: 2022/06/16 03:20:33 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS =	ft_printf.c				\
		char_functions.c		\
		hexa_functions.c		\
		nbr_functions.c			\
		ft_itoa.c				\
		ft_split.c				\
		get_next_line_utils.c	\
		get_next_line.c			\
		so_long_map.c			\
		so_long_map2.c			\
		so_long_move.c			\
		so_long_render.c		\
		so_long_util.c			\
		so_long.c				\
		util1.c					\
		util2.c					\
		util3.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
