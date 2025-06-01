/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 10:59:04 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	init_var(t_vars *var)
{
	var->width = 1920;
	var->height = 1080;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->width, var->height, "Hello_World!!");
	var->image = ft_calloc(sizeof(t_data),1);
	if (var->image == NULL)
		return ;
	var->image->img = mlx_new_image(var->mlx, var->width, var->height);
	var->image->addr = mlx_get_data_addr(var->image->img, &var->image->bits_per_pixel,\
	&var->image->line_length, &var->image->endian);
	return ;
}
