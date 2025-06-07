/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 14:22:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	pixel_put(t_structs *val, int x, int y, int color)
{
	char	*dst;

	if (val == NULL)
		return ;
	else if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = val->image->addr
	+ y * val->image->line_length
	+ x * (val->image->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	set_sign(int start, int goal)
{
	int	sign;

	sign = 0;
	if (start < goal)
		sign= 1;
	else
		sign = -1;
	return (sign);
}

void	bresenham(t_structs *val, t_isol *st, t_isol *gl, int color)
{
	int	x;
	int	y;
	int err2;

	val->calc->delta_x = abs(gl->x - st->x);
	val->calc->delta_y = -abs(gl->y - st->y);
	val->calc->err = delta_x + delta_y;
	val->calc->sign_x = set_sign(st->x, gl->x);
	val->calc->sign_y = set_sign(st->y, gl->y);
	x = st->x;
	y = st->y;
	pixel_put(val, st->x, st->y, color);
	while (1)
	{
		pixel_put(val, x, y, color);
		if (x == gl->x && y == gl->y)
			break ;
		err2 = err * 2;
		if (val->calc->delta_y <= err2)
		{	
			val->calc->err = val->calc->err + val->calc->delta_y;
			x = x + val->calc->sign_x;
		}
		if (err2 <= val->calc->delta_x)
		{
			val->calc->err = val->calc->err + val->calc->delta_x;
			y = y + val->calc->sign_y;
		}
	}
	pixel_put(val, gl->x, gl->y, color);
	return ;
}

void	draw_line(t_structs *val)
{
	int	vt;
	int	hr;
	int color;

	color = 0xFFFFFFFF;
	vt = 0;
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
			if (hr < val->map->width - 1)
				bresenham(val, val->isol[vt][hr], val->isol[vt][hr + 1], color);
			if (vt < val->map->height - 1)
				bresenham(val, val->isol[vt][hr], val->isol[vt + 1][hr], color);
			hr++;
		}
		vt++;
	}
	return ;
}
