/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:36:17 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 11:42:13 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	error_exit(t_structs **val, int error)
{
	put_error(error);
	if (error == 1)
		exit(error);
	else
	{
		free_val(val);
		*val = NULL;
		exit(error);
	}
}

void	free_val(t_structs **val)
{
	free_mlx_elements(*val);
	free_elements(val, (*val)->map->height);
	free ((*val)->map);
	free ((*val)->scale);
	free ((*val)->var);
	free ((*val)->image);
	//free ((*val)->palette);
	free ((*val)->calc);
	free (*val);
	return ;
}

void	put_error(int error)
{
	ft_putstr_fd("Error is ", 2);
	if (error == 1)
		ft_putstr_fd("caused by val_in_init_structs\n", 2);
	else if (error == 2)
		ft_putstr_fd("caused by var_in_init_mlx\n", 2);
	else if (error == 3)
		ft_putstr_fd("caused by image_in_init_mlx\n", 2);
	else if (error == 4)
		ft_putstr_fd("caused by map_in_init_elements\n", 2);
	else if (error == 5)
		ft_putstr_fd("caused by coordinate_in_init_elements\n", 2);
	else if (error == 6)
		ft_putstr_fd("caused by isol_in_init_elements\n", 2);
	else if (error == 7)
		ft_putstr_fd("caused by scale_in_init_elements\n", 2);
	else if (error == 8)
		ft_putstr_fd("caused by mlx_in_init_var\n", 2);
	else
		ft_putstr_fd("unknown error occured\n", 2);
	return ;
}

void	free_elements(t_structs **val, int height)
{
	free_z_map((*val)->map->z_map, height);
	free_coord((*val)->coord, height);
	free_isom((*val)->isom, height);
	free((*val)->var->mlx);
	return ;
}

void	free_mlx_elements(t_structs *val)
{
	mlx_destroy_image(val->var->mlx, val->image->img);
	mlx_destroy_window(val->var->mlx, val->var->win);
	mlx_destroy_display(val->var->mlx);
	return ;
}
