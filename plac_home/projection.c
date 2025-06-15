/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:46:36 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/15 21:36:15 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	init_coord(t_structs *val)
{
	int	y;

	y = 0;
	if (val == NULL || val->map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	val->coord = ft_calloc(sizeof(t_3d *), val->map->height);
	if (val->coord == NULL)
		return (ERR_COORD_ALLOC_FAILED);
	while (y < val->map->height)
	{
		val->coord[y] = ft_calloc(sizeof(t_3d), val->map->width);
		if (val->coord[y] == NULL)
			break ;
		y++;
	}
	if (y < val->map->height)
	{
		free_coord(val->coord, val->map->height);
		return (ERR_INIT_COORD_FAILED);
	}
	return (0);
}

int	init_isom(t_structs *val)
{
	int	y;

	y = 0;
	if (val == NULL || val->map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	val->isom = ft_calloc(sizeof(t_isom *), val->map->height);
	if (val->isom == NULL)
		return (ERR_ISOM_ALLOC_FAILED);
	while (y < val->map->height)
	{
		val->isom[y] = ft_calloc(sizeof(t_isom), val->map->width);
		if (val->isom[y] == NULL)
			break ;
		y++;
	}
	if (y < val->map->height)
	{
		free_isom(val->isom, val->map->height);
		return (ERR_INIT_ISOM_FAILED);
	}
	return (0);
}

void	set_scale(t_structs *val)
{
	if (val == NULL)
		exit(ERR_NULL_VALUE_DETECTED);
	if (val->scale->zoom <= 0)
		val->scale->zoom = DEFAULT_ZOOM;
	val->scale->z_scale = DEFAULT_Z_SCALE;
	return ;
}

int	set_coord(t_structs *val)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	while (y < val->map->height)
	{
		x = 0;
		while (x < val->map->width)
		{
			val->coord[y][x].z = val->map->z_map[y][x];
			val->coord[y][x].y = y;
			val->coord[y][x].x = x;
			x++;
		}
		y++;
	}
	return (0);
}

int isom_x(t_3d coord, t_scale *scale)
{
    double  temp;
    int     isom_x;

    temp = (coord.x - coord.y) * 0.866;
    isom_x = (int)(temp * scale->zoom);
    return (isom_x);
}

int isom_y(t_3d coord, t_scale *scale)
{
    double  temp;
    int     isom_y;

    temp = (coord.x + coord.y) * 0.5 - (coord.z * scale->z_scale);
    isom_y = (int)(temp * scale->zoom);
    return (isom_y);
}

int	trans_isom(t_structs *val)
{
	int		vt;
	int		hr;

	vt = 0;
	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	set_scale(val);
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
            val->isom[vt][hr].x = isom_x(val->coord[vt][hr], val->scale);
            val->isom[vt][hr].y = isom_y(val->coord[vt][hr], val->scale);
            hr++;
		}
		vt++;
	}
	return (0);
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
	int error;

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

void	projection(t_structs *val)
{
	int	error;

	error = 0;
	error = init_coord(val);
	if (error != 0)
		error_exit(&val, error);
	error = init_isom(val);
	if (error != 0)
		error_exit(&val, error);
	error = set_coord(val);
	if (error != 0)
		error_exit(&val, error);
	error = trans_isom(val);
	if (error != 0)
		error_exit(&val, error);
	error = offset_image(val);
	if (error != 0)
		error_exit(&val, error);
	return ;
}
