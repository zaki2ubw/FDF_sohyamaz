/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 10:58:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	draw_line(t_vars *var, t_calc *calc, int color)
{
	pixel_put(var->image, calc->start_x, calc->start_y, color);
	if (calc->delta_x == 0)
	{
		while (1)
		{
			pixel_put(var->image, calc->start_x, calc->start_y, color);
			if (calc->start_y == calc->goal_y)
				break ;
			if (calc->sign_y > 0 && calc->start_y > calc->goal_y)
				break ;
			if (calc->sign_y < 0 && calc->start_y < calc->goal_y)
				break ;
			calc->start_y = calc->start_y + calc->sign_y;
		}
		return ;
	}
	else if (calc->delta_y == 0)
	{
		while (1)
		{
			pixel_put(var->image, calc->start_x, calc->start_y, color);
			if (calc->start_x == calc->goal_x)
				break ;
			if (calc->sign_x > 0 && calc->start_x > calc->goal_x)
				break ;
			if (calc->sign_x < 0 && calc->start_x < calc->goal_x)
				break ;
			calc->start_x = calc->start_x + calc->sign_x;
		}
		return ;
	}
	else if (calc->delta_x >= abs(calc->delta_y))//lower than one
	{
		p = 2 * abs(calc->delta_y) - abs(calc->delta_x);
		while (1)
		{
			//watch and break when pixel reached the goal
			if (calc->start_x == calc->goal_x && calc->start_y == calc->goal_y)
				break ;
			if (calc->start_x > calc->goal_x && calc->sign_x > 0)//x over the goal
				break ;
			if (calc->start_x < calc->goal_x && calc->sign_x < 0)//x under the goal
				break ;
			if (calc->start_y < calc->goal_y && calc->sign_y > 0)//y over the goal
				break ;
			if (calc->start_y > calc->goal_y && calc->sign_y < 0)//y under the goal
				break ;
			calc->start_x++;
			if (calc->err < 0)//if err over the 0, one up y
				calc->err = calc->err + 2 * calc->delta_y;
			else
			{
				calc_start->y++;
				calc_err = calc->err + calc->delta_y * 2 - calc_delta_x * 2;
			}
			pixel_put(var->image, calc->start_x, calc->start_y, color);
	}
	else
	{
		p = 2 * abs(calc->delta_x) - abs(calc->delta_y);
		while (1)
		{
			//watch and break when pixel reached the goal
			if (calc->start_x == calc->goal_x && calc->start_y == calc->goal_y)
				break ;
			if (calc->start_x > calc->goal_x && calc->sign_x > 0)//x over the goal
				break ;
			if (calc->start_x < calc->goal_x && calc->sign_x < 0)//x under the goal
				break ;
			if (calc->start_y < calc->goal_y && calc->sign_y > 0)//y over the goal
				break ;
			if (calc->start_y > calc->goal_y && calc->sign_y < 0)//y under the goal
				break ;
			calc->start_y++;
			if (calc->err < 0)//if err over the 0, one up x
				calc->err = calc->err + 2 * calc->delta_x;
			else
			{
				calc_start->x++;
				calc_err = calc->err + calc->delta_x * 2 - calc_delta_y * 2;
			}
			pixel_put(var->image, calc->start_x, calc->start_y, color);
	}
	else if (calc->delta_x >= abs(calc->delta_y))
	{
		calc->err = calc->delta_x / 2;
		while (1)
		{
			pixel_put(var->image, calc->start_x, calc->start_y, color);
			if ((calc->start_x == calc->goal_x) && (calc->start_y == calc->goal_y))
				break ;
			if (calc->sign_x > 0 && calc->start_x > calc->goal_x)
				break ;
			if (calc->sign_x < 0 && calc->start_x < calc->goal_x)
				break ;
			if (calc->sign_y > 0 && calc->start_y > calc->goal_y)
				break ;
			if (calc->sign_y < 0 && calc->start_y < calc->goal_y)
				break ;
			calc->start_x = calc->start_x + calc->sign_x;
			calc->err = calc->err - abs(calc->delta_y);
			if (calc->err < 0)
			{
				calc->start_y = calc->start_y + calc->sign_y;
				calc->err = calc->err + calc->delta_x;
			}
		}
	}
	else
	{
		calc->err = abs(calc->delta_y) / 2;
		while (calc->start_y != calc->goal_y)
		{
			pixel_put(var->image, calc->start_x, calc->start_y, color);
			if ((calc->start_x == calc->goal_x) && (calc->start_y == calc->goal_y))
				break ;
			if (calc->sign_x > 0 && calc->start_x > calc->goal_x)
				break ;
			if (calc->sign_x < 0 && calc->start_x < calc->goal_x)
				break ;
			if (calc->sign_y > 0 && calc->start_y > calc->goal_y)
				break ;
			if (calc->sign_y < 0 && calc->start_y < calc->goal_y)
				break ;
			calc->start_y = calc->start_y + calc->sign_y;
			calc->err = calc->err - calc->delta_x;
			if (calc->err < 0)
			{
				calc->start_x = calc->start_x + calc->sign_x;
				calc->err = calc->err + abs(calc->delta_y);
			}
		}
	}
	pixel_put(var->image, calc->goal_x, calc->goal_y, color);
	return ;
}
