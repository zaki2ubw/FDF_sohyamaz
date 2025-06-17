/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:19 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 11:26:06 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	create_window(t_structs *val)
{
	int	error;

	error = set_var(&val->var);
	if (error != 0)
		error_exit(&val, error);
	error = set_image(val->var, val->image);
	if (error != 0)
		error_exit(&val, error);
	return ;
}

int	set_var(t_var **var)
{
	(*var)->mlx = mlx_init();
	if ((*var)->mlx == NULL)
		return (ERR_MLX_FUNC_FAILED);
	(*var)->win = mlx_new_window((*var)->mlx, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "Hello_fdf!!");
	if ((*var)->win == NULL)
		return (ERR_MLX_FUNC_FAILED);
	return (0);
}

int	set_image(t_var *var, t_image *image)
{
	image->img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (image->img == NULL)
		return (ERR_MLX_FUNC_FAILED);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
	if (image->addr == NULL)
		return (ERR_MLX_FUNC_FAILED);
	return (0);
}

void	pixel_put(t_structs *val, int x, int y, int color)
{
	char	*dst;

	if (val == NULL)
		return ;
	else if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = val->image->addr \
	+ y * val->image->line_length \
	+ x * (val->image->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}
