/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:46:52 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 22:16:46 by sohyamaz         ###   ########.fr       */
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
		{
			error = bresenham(val, val->isol[vt][hr], \
					val->isol[vt][hr + 1], color);
			if (error != 0)
				return (error);
		}
		if (vt < val->map->height - 1)
		{
			error = bresenham(val, val->isol[vt][hr], \
					val->isol[vt + 1][hr], color);
			if (error != 0)
				return (error);
		}
		hr++;
	}
	return (0);
}

void	draw_line(t_structs *val)
{
	int	vt;
	int	color;
	int	error;

	color = 0xFFFFFFFF;
	vt = 0;
	error = 0;
	if (val == NULL || val->map == NULL)
		error_exit(val, ERR_NULL_VALUE_DETECTED);
	while (vt < val->map->height)
	{
		error = draw_loop(val, vt, color);
		if (error != 0)
			error_exit(val, error);
		vt++;
	}
	return ;
}
