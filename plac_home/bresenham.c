/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 20:29:28 by sohyamaz         ###   ########.fr       */
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
	val->calc->x = st->x;
	val->calc->y = st->y;
	val->calc->delta_x = abs(gl->x - st->x);
	val->calc->delta_y = abs(gl->y - st->y);
	val->calc->sign_x = set_sign(st->x, gl->x);
	val->calc->sign_y = set_sign(st->y, gl->y);
	return (0);
}

int	err_check_x(t_structs *val, t_calc *calc, t_isom *gl, int color)
{
	if (calc == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	calc->err = calc->delta_x / 2;
	while (calc->x != gl->x)
	{
		pixel_put(val, calc->x, calc->y, color);
		calc->x = calc->x + calc->sign_x;
		calc->err = calc->err - calc->delta_y;
		if (calc->err < 0)
		{
			calc->y = calc->y + calc->sign_y;
			calc->err = calc->err + calc->delta_x;
		}
	}
	return (0);
}

int	err_check_y(t_structs *val, t_calc *calc, t_isom *gl, int color)
{
	if (calc == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	calc->err = calc->delta_y / 2;
	while (calc->y != gl->y)
	{
		pixel_put(val, calc->x, calc->y, color);
		calc->y = calc->y + calc->sign_y;
		calc->err = calc->err - calc->delta_x;
		if (calc->err < 0)
		{
			calc->x = calc->x + calc->sign_x;
			calc->err = calc->err + calc->delta_y;
		}
	}
	return (0);
}

int	bresenham(t_structs *val, t_isom *st, t_isom *gl, int color)
{
	//int	x;
	//int	y;
	int	error;

	//x = st->x;
	//y = st->y;
	error = set_calc(val, st, gl);
	if (error != 0)
		return (error);
	if (val->calc->delta_x >= val->calc->delta_y)
	{
		error = err_check_x(val, val->calc, gl, color);
		if (error == ERR_NULL_VALUE_DETECTED)
			return (error);
	}
	else
	{
		error = err_check_y(val, val->calc, gl, color);
		if (error == ERR_NULL_VALUE_DETECTED)
			return (error);
	}
	pixel_put(val, gl->x, gl->y, color);
	return (0);
}
