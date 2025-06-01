/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 11:00:20 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	main(void)
{
	var = ft_calloc(sizeof(t_var), 1);
	if (var == NULL)
		return (0);
	init_var(var);
	fd = open("./test_maps/42.fdf", O_RDONLY);
	column = 0;
	column = count_column(fd);
	close(fd);
	map = ft_calloc(sizeof(char **), column);
	if (map == NULL)
		return (0);
	fd = open("./test_maps/42.fdf", O_RDONLY);
	count = 0;
	while (count < column)
	{
		line = get_next_line(fd);
		map[count] = ft_split(line, ' ');
		free(line);
		count++;
	}
	coordinate = ft_calloc(sizeof(int *), column);
	if (coordinate == NULL)
	{
		free_map(map, column, count);
		return (0);
	}
	row = 0;
	val = 0;
	while (map[0][row] != NULL)
		row++;
	while (val < column)
	{
		coordinate[val] = ft_calloc(sizeof(int),row);
		if (coordinate[val] == NULL)
		{
			free_map(map, column, row);
			free_coordinate(coordinate, column);
			return (0);
		}
		val++;
	}
	count = 0;
	while (count < column)
	{
		rep = 0;
		while (rep < row)
		{
			val = ft_atoi(map[count][rep]);
			coordinate[count][rep] = val;
			rep++;
		}
		count++;
	}
	calc = (t_calc *)ft_calloc(sizeof(t_calc), 1);
	if (calc == NULL)
	{
		free_map(map, column, row);
		free_coordinate(coordinate, column);
		return (0);
	}
	calc->zoom = 200;
	calc->y = 0;
	calc->x = 0;
	while (1)
	{
		if (calc_y == column)
			break ;
		calc->start_x = var->width / 4;
		calc->goal_x = var->width - calc->start_x;
		calc->goal_y = var->height / 4;
		calc->start_y = var->height - calc->goal_y;
		set_calc(calc);
		//review the roop rule!!!!!!!!
	while (calc->y != column)
	{
		set_calc_for_slant(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
		{
			free_map(map, column, row);
			free_coordinate(coordinate, column);
			free (calc);
			printf("slant\n");
			return (0);
		}
		calc->x = 0;
		while (calc->x != row)
		{
			draw_line(var, calc, 0xff00ff00);
			calc->x++;
		}
		calc->y++;
	}
	calc->y = 0;
	calc->x = 0;
	while (calc->y != column)
	{
		set_calc_for_horizontal(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
		{
			free_map(map, column, row);
			free_coordinate(coordinate, column);
			free (calc);
			printf("horizontal\n");
			return (0);
		}
		calc->x = 0;
		while (calc->x != row)
		{
			draw_line(var, calc, 0xff00ff00);
			calc->x++;
		}
		calc->y++;
	}
	calc->y = 0;
	calc->x = 0;
	while (calc->y < column)
	{
		set_calc_for_vertical(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
		{
			free_map(map, column, row);
			free_coordinate(coordinate, column);
			free (calc);
			printf("vertical\n");
			return (0);
		}
		calc->x = 0;
		while (calc->x < row)
		{
			draw_line(var, calc, 0xff00ff00);
			calc->x++;
		}
		calc->y++;
	}
	free (calc);
	mlx_put_image_to_window(var->mlx, var->win, var->image->img, 0, 0);
	free_map(map, column, row);
	free_coordinate(coordinate, column);
	mlx_key_hook(var->win, close_window, var);
	mlx_loop(var->mlx);
	return (0);
}
