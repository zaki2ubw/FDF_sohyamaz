/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/25 17:29:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_plac.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
		exit (0);
	else if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		exit (0);
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

int	main(void)
{
	t_vars	var = {0};
	int		fd;
	char	*line;
//	t_calc	start;
//	t_calc	goal;
	int		count;
	char	***map;
	int		**coordinate;
	int		row;
	int		rep;
	int		column;
	int		val;
	int		x;
	int		y;
	int		x_step;
	int		y_step;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		px;
	int		py;
	int		e;
	int		m;
	int		i;
	int		zoom;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Hello_World!!");
	var.image = malloc(sizeof(t_data));
	if (var.image == NULL)
		return (0);
	var.image->img = mlx_new_image(var.mlx, 1920, 1080);
	var.image->addr = mlx_get_data_addr(var.image->img, &var.image->bits_per_pixel,\
	&var.image->line_length, &var.image->endian);
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
	y = 1;
	x = 1;
	e = 0;
	m = 0;
	zoom = 500;
	sx = x * zoom;
	sy = y * zoom;
	px = (x + 1) * zoom;
	py = (y + 1) * zoom;
	dx = abs(px - sx);
	dy = -abs(py - sy);
	m = dy / dx;
	e = dx + dy;
	i = 0;
	if (sx < px)
		x_step = 1;
	else
		x_step = -1;
	if (sy < py)
		y_step = 1;
	else
		y_step = -1;	
	if (sx < 0 || sx >= 1920 || sy < 0 || sy >= 1080)
		exit (0);
	if (dx >= dy)
	{
		
//	while (1)
//	{
//		my_mlx_pixel_put(var.image, sx, sy, 0x0000FF00);
//		if ((x_step == 1 && sx > px) || (x_step == -1 && sx < px) ||\
//			(y_step == 1 && sy > py) || (y_step == -1 && sy < py))
//			break;
//		i = 2 * e;
//		if (i >= dy)
//		{
//			e = e - dy;
//			sx = sx + x_step;
//		}
//		if (i <= dx)
//		{
//			e = e + dx;
//			sy = sy + y_step;
//		}
//	}
//	while (1)
//	{
//		if (sx == px && sy == py)
//			break ;
//		else if (sx < 0 || sx >= 1920 || sy < 0 || sy >= 1080)
//			exit (0);
//		if (e < 0)
//			e = e + 2 * dy;
//		else
//		{
//			sy = sy + 1;
//			e = e + (2 * dy) - (2 * dx);
//		}
//		my_mlx_pixel_put(var.image, sx, sy, 0x000000FF);
//		sx++;
//	}
//	while (y < column)
//	{
//		while (x < row)
//		{
//			my_mlx_pixel_put(var.image, x * 50, y * 50, 0x0000FF00);
//			dx = x * 50 - x;
//			dy = y * 50 - y;
//			m = dy / dx;
//			e = 2 * dy - dx;
//			px = x;
//			py = y;
//			i = 0;
//			if (m < 0)
//			{
//				while (i < dx)
//				{
//					px = px + 1;
//					if (e < 0)
//						e = e + 2 * dy;
//					else
//					{
//						py = py + 1;
//						e = e + 2 * dy - 2 * dx;
//					}
//					my_mlx_pixel_put(var.image, px, py, 0x00FF0000);
//					i++;
//				}
//			} 
//			else
//			{
//				while (i < dx)
//				{
//					px = px + 1;
//					if (e < 0)
//						e = e + 2 * dy;
//					else
//					{
//						py = py + 1;
//						e = e + 2 * dy + 2 * dx;
//					}
//					my_mlx_pixel_put(var.image, px, py, 0x00FF0000);
//					i++;
//				}
//			} 
//			x++;
//		}
//		y++;
//		x = 1;
//	}
	mlx_put_image_to_window(var.mlx, var.win, var.image->img, 0, 0);
	free_map(map, column, row);
	free_coordinate(coordinate, column);
	mlx_key_hook(var.win, close_window, &var);
	mlx_loop(var.mlx);
	return (0);
}
