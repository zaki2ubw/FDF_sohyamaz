/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 18:53:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	init_structs(t_structs **val)
{
	int	error;

	error = 0;
	*val = ft_calloc(sizeof(t_structs),1);
	if (*val == NULL)
	{
		error = ERR_STRUCTS_ALLOC_FAILURE;
		error_exit(val, error);
	}
	init_mlx(&(*val)->var, &(*val)->image);
	if (error != 0)
		error_exit(val, error);
	init_elements(&(*val)->map, &(*val)->coordinate, &(*val)->isol, &(*val)->scale);
	if (error != 0)
		error_exit(val, error);
	init_var(&(*val)->var, &(*val)->map);
	if (error != 0)
		error_exit(val, error);
	init_image((*val)->var, (*val)->map, (*val)->image);
	return (0);
}

int	init_mlx(t_var **var, t_image **image)
{
	*var = ft_calloc(sizeof(t_var),1);
	if (*var == NULL)
		return (ERR_VAR_ALLOC_FAILURE);
	*image = ft_calloc(sizeof(t_image),1);
	if (*image == NULL)
		return (ERR_IMAGE_ALLOC_FAILURE);
	return (0);
}
	
int	init_elements(t_map **map, t_3d **coordinate, t_isol **isol, t_scale **scale)
{
	*map = ft_calloc(sizeof(t_map),1);
	if (*map == NULL)
		return (ERR_MAP_ALLOC_FAILURE);
	*coordinate = NULL;
	*isol = NULL;
	*scale = NULL;
	return (0);
}

int	init_var(t_var **var, t_map **map)
{
	(*map)->width = 1920;
	(*map)->height = 1080;
	(*var)->mlx = mlx_init();
	if ((*var)->mlx == NULL)
		return (ERR_MLX_ALLOC_FAILURE);
	(*var)->win = mlx_new_window((*var)->mlx, (*map)->width,\
	 (*map)->height, "Hello_fdf!!");
	return (0);
}

void	init_image(t_var *var, t_map *map, t_image *image)
{
	image->img = mlx_new_image(var->mlx, map->width, map->height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,\
	&image->line_length, &image->endian);
	return ;
}
