# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 12:07:41 by sohyamaz          #+#    #+#              #
#    Updated: 2025/06/08 15:33:48 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= fdf
SRCS	= main.c\
		  bresenham.c\
		  color.c\
		  draw.c\
		  event.c\
		  image.c\
		  init.c\
		  map.c\
		  mem_util.c\
		  projection.c\
		  wrappers.c\
		  gnl/get_next_line.c\
		  gnl/get_next_line_utils.c
OBJS	= $(SRCS:%.c=%.o)

#External Libs
LIBDIR	= Libft
LIBNAME = $(LIBDIR)/libft.a
MLX_DIR = mlx_linux
MLX_REPO = git@github.com:42Paris/minilibx-linux.git
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a

#Conpile
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(LIBDIR) -Imlx_linux -Ignl

#Declaration of rules
all	: $(MLX_DIR) $(LIBNAME) $(NAME)

$(NAME)	: $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) -L$(LIBDIR) -lft \
		 -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz \
		 -o $(NAME)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)
	cd $(MLX_DIR) && ./configure && make

$(MLX_LIB):
	cd $(MLX_DIR) && ./configure && make

%.o: %.c
	$(CC) $(CFLAGS) -O0 -c $< -o $@

clean	:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) clean
	-$(MAKE) -C $(MLX_DIR) clean

fclean	: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re	: fclean all

#Phony target declaration
.PHONY	: all re clean fclean
