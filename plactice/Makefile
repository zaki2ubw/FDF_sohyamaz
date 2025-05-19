# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 12:16:58 by sohyamaz          #+#    #+#              #
#    Updated: 2025/05/18 12:19:26 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= mlx_plactice
SRCS	= main.c get_next_line.c get_next_line_utils.c
LIBDIR	= libft
LIBNAME = libft.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
OBJS	= $(SRCS:%.c=%.o)

#Declaration of rules

all	: $(NAME)

clean	: 
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

#Phony target declaration
.PHONY	: all re clean fclean

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
