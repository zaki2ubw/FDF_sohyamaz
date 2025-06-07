/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:46:52 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 15:50:05 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

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
