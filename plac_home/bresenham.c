/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/05 22:44:45 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	pixel_put(t_structs *val, int x, int y, int color)
{
	char	*dst;

	if (val = NULL)
		return ;
	else if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_structs *val, t_isol *st, t_isol *gl)
{
	int	delta_x;
	int	delta_y;

	delta_x = gl->x - st->x;
	delta_y = gl->y - st->y;
	if (abs(delta_x) > abs(delta_y))
		roop_x(delta_x, delta_y, st);
	else
		roop_y(delta_x, delta_y, st);
	return ;
}

void	roop_x(int	dx, int dy, t_isol *st)
{
	int	err;
	int	count;

	count = 0;
	err = 2 * dy - dx;
	pixel_put(val, st->x, st->y, color);
	while (count < dx)
	{
		st->x++;
		if (err < 0)
			err = err + 2 * dy;
		else
		{
			st->y++;
			err = err + (2 * dy) - (2 * dx);
		}
		pixel_put(val, st->x, st->y, color);
		count++;
	}
	return ;
}

void	roop_y(int	dx, int dy, t_isol *st)
{
	int	err;
	int	count;

	count = 0;
	err = 2 * dx - dy;
	pixel_put(val, st->x, st->y, color);
	while (count < dy)
	{
		st->y++;
		if (err < 0)
			err = err + 2 * dx;
		else
		{
			st->x++;
			err = err + (2 * dx) - (2 * dy);
		}
		pixel_put(val, st->x, st->y, color);
		count++;
	}
	return ;
}

void	draw_line(t_structs *val)
{
	int color;
	int	vt;
	int	hr;

	color = 0xFFFFFFFF;
	vt = 0;
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
			bresenham(val, isol[vt][hr], isol[vt][hr + 1]);
			bresenham(val, isol[vt][hr], isol[vt + 1][hr]);
			hr++;
		}
		vt++;
	}
	return ;
}
