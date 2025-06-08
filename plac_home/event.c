/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:47:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 13:45:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	close_window(int keycode, t_structs *val)
{
	if (val == NULL)
		exit (0);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(val->var->mlx, val->image->img);
		mlx_destroy_window(val->var->mlx, val->var->win);
		mlx_destroy_display(val->var->mlx);
		free(val->image);
		free(val->var->mlx);
		free(val->var);
		exit (0);
	}
	return (0);
}
