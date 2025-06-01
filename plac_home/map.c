/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 13:26:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	read_map(char *file, t_map **map)
{
	int	error;

	error = 0;
	error = count_column(file, map);
	if (error != 0)
		error_exit(error);
	fd = open(file, O_RDONLY);
	
	close(fd);
}
int	count_column(char *file, t_map **map)
{
	char	*line;
	int		row;
	int		column;
	int		fd;

	column = 0;
	row = 0;
	fd = 0;
	fd = open(file, O_RDONLY);
	line = ft_calloc(sizeof(char *), 1);
	if (line == NULL)
		return (ERR_LINE_ALLOC_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		row = ft_strlen(line);
		if (column != 0 && row != (*map)->width)
		{
			free(line);
			return (ERR_INVALID_MAP);
		}
		else
			(*map)->width = row;
		free(line);
		column++;
	}
	(*map)->height = column;
	close(fd);
	return (0);
}
