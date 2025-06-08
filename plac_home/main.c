/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 19:17:27 by sohyamaz         ###   ########.fr       */
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
    mlx_loop(val->var->mlx);
    //free_all?
	//event_hook???
	return (0);
}
