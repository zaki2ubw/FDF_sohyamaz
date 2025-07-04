/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:39:53 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 11:41:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	rewrite_wrapper(t_structs *val)
{
	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	if (val->image->img != NULL)
		mlx_destroy_image(val->var->mlx, val->image->img);
	val->image->img = mlx_new_image(val->var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	val->image->addr = \
	mlx_get_data_addr(val->image->img, &val->image->bits_per_pixel, \
	&val->image->line_length, &val->image->endian);
	return (0);
}

int	draw_line_wrapper(void *ptr)
{
	t_structs	*val;

	if (ptr == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	val = (t_structs *)ptr;
	draw_line(val);
	return (0);
}

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
//	error = init_color(*val);
//	if (error != 0)
//		error_exit(val, error);
	error = init_mlx(*val);
	if (error != 0)
		error_exit(val, error);
	return ;
}
