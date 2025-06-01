/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:59:38 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 18:06:00 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_structs	*val;
	int			error;
	int			y, x;

	if (argc != 2)
	{
		printf("Usage: ./fdf <map_file>\n");
		return (1);
	}

	error = init_structs(&val);
	if (error)
		error_exit(&val, error);

	read_map(argv[1], &val->map);

	if (!val || !val->map || !val->map->z_map)
	{
		printf("Error: NULL structure after map read\n");
		return (1);
	}

	for (y = 0; y < val->map->height; y++)
	{
		for (x = 0; x < val->map->width; x++)
			printf("%4d", val->map->z_map[y][x]);
		printf("\n");
	}
	free_z_map(val->map->z_map);
	free_val(&val, 0);
	return (0);
}

