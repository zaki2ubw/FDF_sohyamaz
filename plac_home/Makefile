# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 12:07:41 by sohyamaz          #+#    #+#              #
#    Updated: 2025/06/08 12:37:40 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= fdf
SRCS	= main.c\
		  color.c\
		  draw.c\
		  event.c\
		  get_next_line.c\
		  get_next_line_utils.c\
		  image.c\
		  init.c\
		  map.c\
		  mem_util.c\
		  projection.c
OBJS	= $(SRCS:%.c=%.o)

#External Libs
LIBDIR	= ../Libft
LIBNAME = $(LIBDIR)/libft.a

#Conpile
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(LIBDIR) - Imlx_linux

#Declaration of rules
all	: $(LIBNAME) $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -L$(LIBDIR) -lft \
		 -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz \
		 -Imlx_linux -o $(NAME)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -O0 -c $< -o $@

clean	: 
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean	: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re	: fclean all

#Phony target declaration
.PHONY	: all re clean fclean


