/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 14:19:26 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	init_structs(t_structs **val)
{
	int	error;

	error = 0;
	error = init_val(&(*val));
	if (error != 0)
		error_exit(val, error);
	error = init_maps(*val);
	if (error != 0)
		error_exit(val, error);
	error = init_modules(*val);
	if (error != 0)
		error_exit(val, error);
	error = init_color(*val);
	if (error != 0)
		error_exit(val, error);
	error = init_mlx(*val);
	if (error != 0)
		error_exit(val, error);
	return ;
}

int	init_val(t_structs **val)
{
	*val = ft_calloc(sizeof(t_structs), 1);
	if (*val == NULL)
		return (ERR_VAL_ALLOC_FAILED);
	return (0);
}

int	init_maps(t_structs *val)
{
	val->map = ft_calloc(sizeof(t_map), 1);
	if (val->map == NULL)
		return (ERR_MAP_ALLOC_FAILED);
	val->corrd = NULL;
	val->isom = NULL;
	return (0);
}

int	init_mlx(t_structs *val)
{
	int	error;

	error = 0;
	val->var = ft_calloc(sizeof(t_var), 1);
	if (val->var == NULL)
		return (ERR_VAR_ALLOC_FAILED);
	val->image = ft_calloc(sizeof(t_image), 1);
	if (val->image == NULL)
		return (ERR_IMAGE_ALLOC_FAILED);
	error = set_var(&val->var, &val->map);
	if (error != 0)
		return (error);
	error = set_image(val->var, val->map, val->image);
	if (error != 0)
		return (error);
	return (0);
}

int	init_modules(t_structs *val)
{
	val->scale = ft_calloc(sizeof(t_scale), 1);
	if (val->scale == NULL)
		return (ERR_SCALE_ALLOC_FAILED);
	val->calc = ft_calloc(sizeof(t_calc), 1);
	if (val->calc == NULL)
		return (ERR_CALC_ALLOC_FAILED);
	return (0);
}

int	init_color(t_structs *val)
{
	val->palette = ft_calloc(sizeof(t_color), 1);
	if (val->palette == NULL)
		return (ERR_COLOR_ALLOC_FAILED);
	return (0);
}

int	set_var(t_var **var, t_map **map)
{
	(*map)->width = WINDOW_WIDTH;
	(*map)->height = WINDOW_HEIGHT;
	(*var)->mlx = mlx_init();
	if ((*var)->mlx == NULL)
		return (ERR_MLX_INIT_FAILED);
	(*var)->win = mlx_new_window((*var)->mlx, (*map)->width, \
	(*map)->height, "Hello_fdf!!");
	if ((*var)->win == NULL)
		return (ERR_MLX_NEW_WINDOW_FAILED);
	return (0);
}

int	set_image(t_var *var, t_map *map, t_image *image)
{
	image->img = mlx_new_image(var->mlx, map->width, map->height);
	if (image->img == NULL)
		return (ERR_MLX_NEW_IMAGE_FAILED);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
	if (image->addr == NULL)
		return (ERR_GET_DATA_ADDR_FAILED);
	return (0);
}
