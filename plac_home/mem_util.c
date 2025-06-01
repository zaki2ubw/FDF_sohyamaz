/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:48:16 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 10:56:53 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

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
