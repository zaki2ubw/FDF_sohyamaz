/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 19:16:35 by sohyamaz         ###   ########.fr       */
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
	val->coord = NULL;
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
