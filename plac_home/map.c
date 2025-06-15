/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/15 22:05:40 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	count_column(char *line, char cut)
{
	int	count;
	int	column;

	column = 1;
	count = 0;
	if (line == NULL)
		return (0);
	while (line[count] != '\0' && line[count] != '\n')
	{
		if (line[count] == cut)
			column++;
		count++;
	}
	return (column);
}

int	set_height(t_map **map, int fd)
{
	char	*line;
	int		row;
	int		column;

	row = 0;
	(*map)->width = 0;
	if (*map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL && row == 0)
			return (ERR_EMPTY_MAP);
		else if (line == NULL)
			break ;
		column = count_column(line, ' ');
		if ((*map)->width < column)
			(*map)->width = column;
		free(line);
		row++;
	}
	(*map)->height = row;
	return (0);
}

void	check_map_size(t_structs *val, char *file, t_map **map)
{
	int		fd;
	int		error;

	fd = 0;
	error = 0;
	if (val == NULL || file == NULL || *map == NULL)
		error_exit(&val, ERR_NULL_VALUE_DETECTED);
	fd = open(file, O_RDONLY);
	error = set_height(map, fd);
	close(fd);
	if (error != 0)
		error_exit(&val, error);
	return ;
}

int	convert_map(t_map **map, char **args, int count)
{
	int	i;

	i = 0;
	if (*map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	while (args[i] != NULL && i < (*map)->width)
	{
		(*map)->z_map[count][i] = ft_atoi(args[i]);
		i++;
	}
	return (0);
}

int	set_map(t_map **map, int fd)
{
	int		error;
	char	**args;
	char	*line;
	int		count;

	count = 0;
	if (*map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	while (count < (*map)->height)
	{
		line = get_next_line(fd);
		args = ft_split(line, ' ');
		if (args == NULL)
			return (ERR_SPLIT_FAILED);
		error = convert_map(map, args, count);
		if (error != 0)
			return (error);
		free_args(line, args);
		count++;
	}
	return (0);
}

int	init_z_map(t_map **map)
{
	int	count;

	count = 0;
	(*map)->z_map = ft_calloc(sizeof(int *), (*map)->height);
	if ((*map)->z_map == NULL)
		return (ERR_ALLOC_FAILED);
	while (count < (*map)->height)
	{
		(*map)->z_map[count] = ft_calloc(sizeof(int), (*map)->width);
		if ((*map)->z_map[count] == NULL)
		{
			free_z_map((*map)->z_map, count);
			return (ERR_ALLOC_FAILED);
		}
		count++;
	}
	return (0);
}

void	read_map(t_structs *val, char *file, t_map **map)
{
	int		error;
	int		fd;

	if (val == NULL || file == NULL || *map == NULL)
		error_exit(&val, ERR_NULL_VALUE_DETECTED);
	error = init_z_map(map);
	if (error != 0)
		error_exit(&val, error);
	fd = open(file, O_RDONLY);
	error = set_map(map, fd);
	if (error != 0)
	{
		close (fd);
		error_exit(&val, error);
	}
	close(fd);
	return ;
}
