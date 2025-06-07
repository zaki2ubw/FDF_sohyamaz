/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 16:25:08 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

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
