/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:48:16 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/15 22:15:52 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	free_args(char *line, char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free (line);
	free (args);
	return ;
}

void	free_z_map(int **z_map, int height)
{
	int	count;

	count = 0;
	while (count < height)
	{
		free(z_map[count]);
		count++;
	}
	free (z_map);
	return ;
}

void	free_coord(t_3d **coord, int height)
{
	int	count;

	count = 0;
	while (count < height)
	{
		free(coord[count]);
		count++;
	}
	free(coord);
	return ;
}

void	free_isom(t_isom **isom, int height)
{
	int	count;

	count = 0;
	while (count < height)
	{
		free(isom[count]);
		count++;
	}
	free(isom);
	return ;
}
