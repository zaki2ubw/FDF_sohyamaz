# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 12:16:58 by sohyamaz          #+#    #+#              #
#    Updated: 2025/05/24 21:56:43 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= mlx_plactice
SRCS	= main.c get_next_line.c get_next_line_utils.c
LIBDIR	= Libft
LIBNAME = libft.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(LIBDIR) -g 
OBJS	= $(SRCS:%.c=%.o)

#Declaration of rules

all	: $(LIBNAME) $(NAME)

clean	: 
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) fclean

fclean	: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re	: fclean all

#Phony target declaration
.PHONY	: all re clean fclean

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -L$(LIBDIR) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O0 -c $< -o $@
