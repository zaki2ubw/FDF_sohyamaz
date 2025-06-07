/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 18:04:49 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	init_structs(t_structs **val)
{
	int	error;

	error = 0;
	error = init_val(&(*val));
	if (error != 0)
		error_exit(val, error);
	error = init_maps(&(*val)->map, &(*val)->corrd, &(*val)->isom);
	if (error != 0)
		error_exit(val, error);
	error = init_modules(&(*val)->scale, &(*val)->calc);
	if (error != 0)
		error_exit(val, error);
	error = init_color(&(*val)->palette);
	if (error != 0)
		error_exit(val, error);
	error = init_mlx(&(*val)->var, &(*val)->image);
	if (error != 0)
		error_exit(val, error);
	return (0);
}

int	init_val(t_structs **val)
{
	*val = ft_calloc(sizeof(t_structs), 1);
	if (*val == NULL)
		return (ERR_VAL_ALLOC_FAILED);
	return (0);
}

int	init_maps(t_map **map, t_3d **corrd, t_isom **isom)
{
	*map = ft_calloc(sizeof(t_map), 1);
	if (*map == NULL)
		return (ERR_MAP_ALLOC_FAILED);
	*corrd = NULL;
	*isom = NULL;
	return (0);
}

int	init_mlx(t_var **var, t_image **image, t_map **map)
{
	int	error;

	error = 0;
	*var = ft_calloc(sizeof(t_var), 1);
	if (*var == NULL)
		return (ERR_VAR_ALLOC_FAILED);
	*image = ft_calloc(sizeof(t_image), 1);
	if (*image == NULL)
		return (ERR_IMAGE_ALLOC_FAILED);
	error = set_var(var, map);
	if (error != 0)
		return (error);
	error = set_image(var, map, image);
	if (error != 0)
		return (error);
	return (0);
}

int	init_modules(t_scale **scale, t_calc **calc)
{
	*scale = ft_calloc(sizeof(t_scale), 1);
	if (*scale == NULL)
		return (ERR_SCALE_ALLOC_FAILED);
	*calc = ft_calloc(sizeof(t_calc), 1);
	if (*calc == NULL)
		return (ERR_CALC_ALLOC_FAILED);
	return (0);
}

int	init_color(t_color **palette)
{
	*palette = ft_calloc(sizeof(t_color), 1);
	if (*palette == NULL)
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
