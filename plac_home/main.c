/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/10 22:26:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	main(int argc, char **argv)
{
	t_structs	*val;

	if (argc != 2)
	{
		ft_putstr_fd("how to use it : ./fdf ***.fdf\n", 1);
		return (0);
	}
	init_structs(&val);
	check_map_size(val, argv[1], &val->map);
	read_map(val, argv[1], &val->map);
	create_window(val);
	projection(val);
	draw_line(val);
    mlx_expose_hook(val->var->win, &draw_line_wrapper, val);
	mlx_key_hook(val->var->win, close_window_esc, val);
	mlx_hook(val->var->win, 17, 0, close_window_cross, val);
    mlx_loop(val->var->mlx);
	free_val(&val);
	return (0);
}
