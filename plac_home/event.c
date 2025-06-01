/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 10:55:45 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	close_window(int keycode, t_vars *var)
{
	if (var == NULL)
		exit (0);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(var->mlx, var->image->img);
		mlx_destroy_window(var->mlx, var->win);
		mlx_destroy_display(var->mlx);
		free(var->image);
		free(var->mlx);
		free(var);
		exit (0);
	}
	return (0);
}
