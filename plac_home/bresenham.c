/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 21:48:33 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	set_sign(int start, int goal)
{
	int	sign;

	sign = 0;
	if (start < goal)
		sign = 1;
	else
		sign = -1;
	return (sign);
}

int	set_calc(t_structs *val, t_isom *st, t_isom *gl)
{
	if (val == NULL || st == NULL || gl == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	val->calc->delta_x = abs(gl->x - st->x);
	val->calc->delta_y = abs(gl->y - st->y);
	val->calc->err = val->calc->delta_x - val->calc->delta_y;
	val->calc->sign_x = set_sign(st->x, gl->x);
	val->calc->sign_y = set_sign(st->y, gl->y);
	return (0);
}

int	err_check(t_calc *calc, int *x, int *y, int err2)
{
	if (calc == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	if (err2 >= -calc->delta_y)
	{
		calc->err = calc->err + calc->delta_y;
		*x = *x + calc->sign_x;
	}
	if (err2 < calc->delta_x)
	{
		calc->err = calc->err + calc->delta_x;
		*y = *y + calc->sign_y;
	}
	return (0);
}

int	bresenham(t_structs *val, t_isom *st, t_isom *gl, int color)
{
	int	x;
	int	y;
	int	err2;
	int	error;

	x = st->x;
	y = st->y;
	error = 0;
	err2 = set_calc(val, st, gl);
	if (err2 != 0)
		return (err2);
	while (1)
	{
		pixel_put(val, x, y, color);
		if (x == gl->x && y == gl->y)
			break ;
		err2 = val->calc->err * 2;
		error = err_check(val->calc, &x, &y, err2);
		if (error == ERR_NULL_VALUE_DETECTED)
			return (error);
	}
	return (0);
}
