#include "prot.h"

int	init_isom(t_structs *val)
{
	int	y;

	y = 0;
	if (val == NULL || val->map == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	val->isom = ft_calloc(sizeof(t_isom *), val->map->height);
	if (val->isom == NULL)
		return (ERR_ISOM_ALLOC_FAILED);
	while (y < val->map->height)
	{
		val->isom[y] = ft_calloc(sizeof(t_isom), val->map->width);
		if (val->isom[y] == NULL)
			break ;
		y++;
	}
	if (y < val->map->height)
	{
		free_isom(val->isom, val->map->height);
		return (ERR_INIT_ISOM_FAILED);
	}
	return (0);
}

int isom_x(t_3d coord, t_scale *scale)
{
    double  temp;
    int     isom_x;

    temp = (coord.x - coord.y) * 0.866;
    isom_x = (int)(temp * scale->zoom);
    return (isom_x);
}

int isom_y(t_3d coord, t_scale *scale)
{
    double  temp;
    int     isom_y;

    temp = (coord.x + coord.y) * 0.5 - (coord.z * scale->z_scale);
    isom_y = (int)(temp * scale->zoom);
    return (isom_y);
}

int	trans_isom(t_structs *val)
{
	int		vt;
	int		hr;

	vt = 0;
	if (val == NULL)
		return (ERR_NULL_VALUE_DETECTED);
	set_scale(val);
	while (vt < val->map->height)
	{
		hr = 0;
		while (hr < val->map->width)
		{
            val->isom[vt][hr].x = isom_x(val->coord[vt][hr], val->scale);
            val->isom[vt][hr].y = isom_y(val->coord[vt][hr], val->scale);
            hr++;
		}
		vt++;
	}
	return (0);
}

