/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:37:32 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 11:06:02 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	set_scale(t_structs *val)
{
	if (val == NULL)
		exit(ERR_NULL_VALUE_DETECTED);
	if (val->scale->zoom <= 0)
		val->scale->zoom = DEFAULT_ZOOM;
	val->scale->z_scale = DEFAULT_Z_SCALE;
	return ;
}

void	check_limit(int target, int *min, int *max)
{
	if (target < *min)
		*min = target;
	if (target > *max)
		*max = target;
	return ;
}

int	get_center_offset_x(t_structs *val)
{
	int	vt;
	int	hr;
	int	min;
	int	max;

	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	vt = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
			check_limit(val->isom[vt][hr].x, &min, &max);
			hr++;
		}
		vt++;
	}
	val->scale->offset_x = (WINDOW_WIDTH / 2) - ((max + min) / 2);
	return (0);
}

int	get_center_offset_y(t_structs *val)
{
	int	vt;
	int	hr;
	int	min;
	int	max;

	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	vt = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
			check_limit(val->isom[vt][hr].y, &min, &max);
			hr++;
		}
		vt++;
	}
	val->scale->offset_y = (WINDOW_HEIGHT / 2) - ((max + min) / 2);
	return (0);
}

int	offset_image(t_structs *val)
{
	int	vt;
	int	hr;
	int	error;

	vt = 0;
	if (val->scale->offset_x == 0 && val->scale->offset_y == 0)
	{
		error = get_center_offset_x(val);
		error = get_center_offset_y(val);
		if (error != 0)
			return (error);
	}
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
			val->isom[vt][hr].x = val->isom[vt][hr].x + val->scale->offset_x;
			val->isom[vt][hr].y = val->isom[vt][hr].y + val->scale->offset_y;
			hr++;
		}
		vt++;
	}
	return (0);
}
