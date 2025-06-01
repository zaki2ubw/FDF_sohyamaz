/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 18:01:17 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	read_map(char *file, t_map **map)
{
	int	error;
	char	**args;
	char	*line;
	int	fd;
	int count;

	error = 0;
	fd = 0;
	count = 0;
	error = count_grid(file, map);
	if (error != 0)
		return ;
	fd = open(file, O_RDONLY);
	error = init_z_map(map);
	if (error != 0)
		return ;
	while (count < (*map)->height)
	{
		line = get_next_line(fd);
		args = ft_split(line, ' ');
		if (args == NULL)
			return ;
		convert_map(map, args, count);
		free(line);
		free_args(args);
		count++;
	}
	close(fd);
	return ;
}

int	count_x(char *line, char cut)
{
	int	count;
	int	x;

	x = 1;
	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] == cut)
			x++;
		count++;
	}
	return (x);
}

int	count_grid(char *file, t_map **map)
{
	char	*line;
	int		row;
	int		column;
	int		fd;

	column = 0;
	row = 0;
	fd = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (column == 0)
			(*map)->width = count_x(line, ' ');
		free(line);
		column++;
	}
	(*map)->height = column;
	close(fd);
	return (0);
}

int	init_z_map(t_map **map)
{
	int	count;

	count = 0;
	(*map)->z_map = ft_calloc(sizeof(int *), (*map)->height);
	if ((*map)->z_map == NULL)
		return (1);
	while (count < (*map)->height)
	{
		(*map)->z_map[count] = ft_calloc(sizeof(int), (*map)->width);
		if((*map)->z_map[count] == NULL)
		{
			free_z_map((*map)->z_map);
			return (1);
		}
		count++;
	}
	return (0);
}

void	convert_map(t_map **map, char **args, int count)
{
	int	i;

	i = 0;
	while (i < (*map)->width)
	{
		if (args[i] == NULL)
			return ;
		(*map)->z_map[count][i] = ft_atoi(args[i]);
		i++;
	}
	return ;
}
