/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plac.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:35:59 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/18 18:45:41 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PLAC_H
# define MLX_PLAC_H

#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define KEY_ESC 65307
#define CLOSE_BOTTUN 17

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_color
{
	int	clear;
	int	red;
	int	green;
	int blue;
}	t_color;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*image;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		color_init(t_color *scale);
int		close_window(int keycode, t_vars *var);
int		close_window_by_bottun(int event, t_vars *var);
int		key_hook(int keycode, t_vars *var);
int		main(void);

#endif
