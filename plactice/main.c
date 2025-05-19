/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:57:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/18 19:54:34 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_plac.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
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

int	close_window_by_bottun(int event, t_vars *var)
{
	if (var == NULL)
		exit (0);
	(void)event;
	mlx_destroy_image(var->mlx, var->image->img);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->image);
	free(var->mlx);
	exit (0);
}

int	key_hook(int keycode, t_vars *var)
{
	keycode = 0;
	(void)var;
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	var = {0};
	int		fd;
	char	*line;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Hello_World!!");
	var.image = malloc(sizeof(t_data));
	if (var.image == NULL)
		return (0);
	var.image->img = mlx_new_image(var.mlx, 1920, 1080);
	var.image->addr = mlx_get_data_addr(var.image->img, &var.image->bits_per_pixel,\
	&var.image->line_length, &var.image->endian);
	fd = open("./test_maps/42.fdf", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	mlx_put_image_to_window(var.mlx, var.win, var.image->img, 0, 0);
	mlx_key_hook(var.win, close_window, &var);
	mlx_hook(var.win, 33, 0L, close_window_by_bottun, &var);
	mlx_loop(var.mlx);
	return (0);
}
