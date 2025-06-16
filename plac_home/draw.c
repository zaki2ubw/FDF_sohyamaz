/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:46:52 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/15 20:55:49 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	draw_loop(t_structs *val, int vt, int color)
{
	int	hr;
	int	error;

	hr = 0;
	if (val == NULL || val->map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	while (hr < val->map->width)
	{
		if (hr < val->map->width - 1)
			error = bresenham(val, &val->isom[vt][hr], \
&val->isom[vt][hr + 1], color);
		if (vt < val->map->height - 1)
			error = bresenham(val, &val->isom[vt][hr], \
&val->isom[vt + 1][hr], color);
		if ((vt < val->map->height - 1) && (hr < val->map->width - 1))
			error = bresenham(val, &val->isom[vt][hr], \
&val->isom[vt + 1][hr + 1], color);
		if (error != 0)
			return (error);
		hr++;
	}
	return (0);
}

void	draw_line(t_structs *val)
{
	int	vt;
	int	color;
	int	error;

	color = 0xFFFF00FF;
	vt = 0;
	error = 0;
	if (val == NULL || val->map == NULL)
		error_exit(&val, ERR_NULL_VALUE_DETECTED);
	printf("drawing...\n");
	if (val->image->img != NULL)
		mlx_destroy_image(val->var->mlx, val->image->img);
	val->image->img = mlx_new_image(val->var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	val->image->addr = mlx_get_data_addr(val->image->img, \
&val->image->bits_per_pixel, &val->image->line_length, &val->image->endian);
	while (vt < val->map->height)
	{
		error = draw_loop(val, vt, color);
		if (error != 0)
			error_exit(&val, error);
		vt++;
	}
	mlx_clear_window(val->var->mlx, val->var->win);
	mlx_put_image_to_window(val->var->mlx, \
val->var->win, val->image->img, 0, 0);
	return ;
}
