/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/15 21:28:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	close_window_cross(t_structs *val)
{
	if (val == NULL)
		exit (ERR_NULL_VALUE_DETECTED);
	mlx_loop_end(val->var->mlx);
	return (0);
}

void	apply_offset(int keycode, t_structs *val)
{
	if (keycode == 97)
		val->scale->offset_x = val->scale->offset_x - 10;
	else if (keycode == 100)
		val->scale->offset_x = val->scale->offset_x + 10;
	else if (keycode == 119)
		val->scale->offset_y = val->scale->offset_y - 10;
	else if (keycode == 115)
		val->scale->offset_y = val->scale->offset_y + 10;
	return ;
}

int	key_event(int keycode, t_structs *val)
{
	if (val == NULL)
		exit (ERR_NULL_VALUE_DETECTED);
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(val->var->mlx);
		return (0);
	}
	else if (keycode == 105 || keycode == 61)
		val->scale->zoom = val->scale->zoom + 1;
	else if (keycode == 111 || keycode == 45)
	{
		val->scale->zoom = val->scale->zoom - 1;
		if (val->scale->zoom < 1)
			val->scale->zoom = 1;
	}
	else if (keycode == 97 || keycode == 100 \
|| keycode == 115 || keycode == 119)
		apply_offset(keycode, val);
	else
		return (0);
	free_coord(val->coord, val->map->height);
	free_isom(val->isom, val->map->height);
	projection(val);
	draw_line(val);
	return (0);
}
