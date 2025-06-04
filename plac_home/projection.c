/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:46:36 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 20:20:04 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	init_3d(t_structs *val)
{
	int y;

	y = 0;
	val->coordinate = ft_calloc(sizeof(t_3d *), val->map->height);
	if (val->coordinate == NULL)
		return ;
	val->isol = ft_calloc(sizeof(t_isol *), val->map->height);
	if (val->isol == NULL)
		return ;
	val->scale = ft_calloc(sizeof(t_scale), 1);
	if (val->scale == NULL)
		return ;
	while (y < val->map->height)
	{
		val->coordinate[y] = ft_calloc(sizeof(t_3d), val->map->width);
		if (val->coordinate[y] == NULL)
			break ;
		val->isol[y] = ft_calloc(sizeof(t_isol), val->map->width);
		if (val->isol[y] == NULL)
			break ;
		y++;
	}
	if (y < val->map->height)
		free_3d(val->coordinate, val->isol, val->scale);
	return ;
}

void	free_3d(t_3d **coordinate, t_isol **isol, t_scale *scale)
{
	int	count;

	count = 0;
	if (coordinate != NULL)
	{
		while (coordinate[count] != NULL)
		{
			free(coordinate[count];
			count++;
		}
		free(coordinate);
	}
	count = 0;
	if (isol != NULL)
	{
		while (isol[count] != NULL)
		{
			free(isol[count];
			count++;
		}
		free(isol);
	}
	free (scale);
	return ;
}

void	set_coordinate(t_structs *val)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < val->map->height)
	{
		x = 0;
		while (x < val->map->width)
		{
			val->coordinate[y][x].z = val->map->z_map[y][x];
			val->coordinate[y][x].y = y;
			val->coordinate[y][x].x = x;
			x++;
		}
		y++;
	}
	return ;
}

void	trans_isol(t_structs *val)
{
	int vt;
	int hr;
    double  rad;

    vt = 0;
    rad = M_PI / 6;
    while (vt < val->map->height)
    {
        hr = 0;
        while (hr < val->map->width)
        {
            val->isol[vt][hr].x =\
            (val->coordinate[vt][hr].x - val->coordinate[vt][hr].y) * cos(rad);
            val->isol[vt][hr].y =\
            (val->coordinate[vt][hr].x + val->coordinate[vt][hr].y) * sin(rad)\
            - val->corrdinate[vt][hr].z;
            hr++;
        }
        vt++;
    }
    return ;
}








