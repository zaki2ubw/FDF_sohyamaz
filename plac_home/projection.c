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
