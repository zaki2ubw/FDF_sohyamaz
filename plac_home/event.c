/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/10 22:02:07 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	close_window_esc(int keycode, t_structs *val)
{
	if (val == NULL)
		exit (ERR_NULL_VALUE_DETECTED);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(val->var->mlx, val->image->img);
		mlx_destroy_window(val->var->mlx, val->var->win);
		mlx_destroy_display(val->var->mlx);
		free_val(&val);
		exit (0);
	}
	return (0);
}

int	close_window_cross(t_structs *val)
{
	if (val == NULL)
		exit (ERR_NULL_VALUE_DETECTED);
	free_val(&val);
	exit (0);
}
