#include "prot.h"

void	file_check(char **argv)
{
	char	*temp;
	size_t	len;

	if (argv == NULL)
		exit(ERR_NULL_VALUE_DETECTED);
	len = ft_strlen(argv[1]);
	temp = ft_strnstr(argv[1], ".fdf", len);
	if (temp == NULL)
		exit(ERR_INVALID_FILEEXT);
}

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
