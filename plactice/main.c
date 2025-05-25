/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/25 21:30:08 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_plac.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
		exit (0);
	else if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color_init(t_color *scale)
{
	int	color;

	color = 0;
	color = (scale->clear << 24) | (scale->red << 16) | (scale->green << 8) | scale->blue;
	scale->clear = (scale->clear + 10) % 256;
	scale->red = (scale->red + 10) % 256;
	scale->green = (scale->green + 10) % 256;
	scale->blue = (scale->blue + 10) % 256;
	return (color);
}

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

int	count_column(fd)
{
	char	*line;
	int		column;

	column = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s\n", line);
		free(line);
		column++;
	}
	return (column);
}

void	free_map(char ***map, int column, int row)
{
	int	count;
	int	i;

	count = 0;
	while (count < column)
	{
		i = 0;
		while (i < row)
		{
			free(map[count][i]);
			i++;
		}
		free (map[count]);
		count++;
	}
	free (map);
	return ;
}

void	free_coordinate(int **coordinate, int column)
{
	int	count;

	count = 0;
	while (count < column)
	{
		free(coordinate[count]);
		count++;
	}
	free (coordinate);
	return ;
}

void	set_calc_for_slant(t_calc *calc)
{
	calc->start_x = calc->x * calc->zoom;
	calc->start_y = calc->y * calc->zoom;
	calc->goal_x = (calc->x + 1) * calc->zoom;
	calc->goal_y = (calc->y + 1) * calc->zoom;
	calc->delta_x = abs(calc->goal_x - calc->start_x);
	calc->delta_y = -abs(calc->goal_y - calc->start_y);
	if (calc->start_x < calc->goal_x)
		calc->sign_x = 1;
	else
		calc->sign_x = -1;
	if (calc->start_y < calc->goal_y)
		calc->sign_y = 1;
	else
		calc->sign_y = -1;	
	return ;
}

void	set_calc_for_horizontal(t_calc *calc)
{
	calc->start_x = calc->x * calc->zoom;
	calc->start_y = calc->y * calc->zoom;
	calc->goal_x = (calc->x + 1) * calc->zoom;
	calc->goal_y = calc->y * calc->zoom;
	calc->delta_x = abs(calc->goal_x - calc->start_x);
	calc->delta_y = -abs(calc->goal_y - calc->start_y);
	if (calc->start_x < calc->goal_x)
		calc->sign_x = 1;
	else
		calc->sign_x = -1;
	if (calc->start_y < calc->goal_y)
		calc->sign_y = 1;
	else
		calc->sign_y = -1;	
	return ;
}

void	set_calc_for_vertical(t_calc *calc)
{
	calc->start_x = calc->x * calc->zoom;
	calc->start_y = calc->y * calc->zoom;
	calc->goal_x = calc->x * calc->zoom;
	calc->goal_y = (calc->y + 1) * calc->zoom;
	calc->delta_x = abs(calc->goal_x - calc->start_x);
	calc->delta_y = -abs(calc->goal_y - calc->start_y);
	if (calc->start_x < calc->goal_x)
		calc->sign_x = 1;
	else
		calc->sign_x = -1;
	if (calc->start_y < calc->goal_y)
		calc->sign_y = 1;
	else
		calc->sign_y = -1;	
	return ;
}

void	draw_line(t_vars *var, t_calc *calc, int color)
{
	my_mlx_pixel_put(var->image, calc->start_x, calc->start_y, color);
	if (calc->delta_x == 0)
	{
		while (calc->start_y != calc->goal_y)
		{
			my_mlx_pixel_put(var->image, calc->start_x, calc->start_y, color);
			calc->start_y = calc->start_y + calc->sign_y;
		}
		return ;
	}
	else if (calc->delta_y == 0)
	{
		while (calc->start_x != calc->goal_x)
		{
			my_mlx_pixel_put(var->image, calc->start_x, calc->start_y, color);
			calc->start_x = calc->start_x + calc->sign_x;
		}
		return ;
	}
	else if (calc->delta_x >= abs(calc->delta_y))
	{
		calc->err = calc->delta_x / 2;
		while (calc->start_x != calc->goal_x)
		{
			my_mlx_pixel_put(var->image, calc->start_x, calc->start_y, color);
			calc->start_x = calc->start_x + calc->sign_x;
			calc->err = calc->err - abs(calc->delta_y);
			if (calc->err < 0)
			{
				calc->start_y = calc->start_y + calc->sign_y;
				calc->err = calc->err + calc->delta_x;
			}
		}
	}
	else
	{
		calc->err = abs(calc->delta_y) / 2;
		while (calc->start_y != calc->goal_y)
		{
			my_mlx_pixel_put(var->image, calc->start_x, calc->start_y, color);
			calc->start_y = calc->start_y + calc->sign_y;
			calc->err = calc->err - calc->delta_x;
			if (calc->err < 0)
			{
				calc->start_x = calc->start_x + calc->sign_x;
				calc->err = calc->err + abs(calc->delta_y);
			}
		}
	}
	my_mlx_pixel_put(var->image, calc->goal_x, calc->goal_y, color);
	return ;
}

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

int	main(void)
{
	t_vars	*var;
	int		fd;
	char	*line;
	int		count;
	char	***map;
	int		**coordinate;
	int		row;
	int		rep;
	int		column;
	int		val;
	t_calc	*calc;

	var = ft_calloc(sizeof(t_vars), 1);
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
		return (0);
	row = 0;
	val = 0;
	while (map[0][row] != NULL)
		row++;
	while (val < column)
	{
		coordinate[val] = ft_calloc(sizeof(int),row);
		if (coordinate[val] == NULL)
			return (0);
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
		return (0);
	calc->zoom = 200;
	calc->y = 0;
	while (calc->y != column)
	{
		set_calc_for_slant(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
	 		return (0);
		calc->x = 0;
		while (calc->x != row)
		{
			draw_line(var, calc, 0xff00ff00);
			calc->x++;
		}
		calc->y++;
	}
	calc->y = 0;
	while (calc->y != column)
	{
		set_calc_for_horizontal(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
	 		return (0);
		calc->x = 0;
		while (calc->x != row)
		{
			draw_line(var, calc, 0xff00ff00);
			calc->x++;
		}
		calc->y++;
	}
	calc->y = 0;
	while (calc->y < column)
	{
		set_calc_for_vertical(calc);
		if (calc->start_x < 0 || calc->start_x >= var->width ||\
			calc->start_y < 0 || calc->start_y >= var->height)
	 		return (0);
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
