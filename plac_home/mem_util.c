/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:48:16 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 12:45:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	error_exit(t_structs **val, int error)
{
	put_error(error);
	if (error == 1)
		exit(error);
	else
	{
		free_val(val, error);
		*val = NULL;
		exit(error);
	}
}

void	free_val(t_struct **val, int error)
{
	if ((*val)->image != NULL)
		free ((*val)->image);
	if ((*val)->var != NULL)
		free ((*val)->var);
	if ((*val)->scale != NULL)
		free ((*val)->scale);
	if ((*val)->isol != NULL)
		free ((*val)->isol);
	if ((*val)->coordinate != NULL)
		free ((*val)->coordinate);
	if ((*val)->map != NULL)
		free ((*val)->map);
	free (*val);
	return ;
}

void	put_error(int error)
{
	ft_putstr_fd("Error is ", 2);
	if (error == 1)
		ft_putstr_fd("caused by val_in_init_structs\n", 2);
	else if (error == 2)
		ft_putstr_fd("caused by var_in_init_mlx\n", 2);
	else if (error == 3)
		ft_putstr_fd("caused by image_in_init_mlx\n", 2);
	else if (error == 4)
		ft_putstr_fd("caused by map_in_init_elements\n", 2);
	else if (error == 5)
		ft_putstr_fd("caused by coordinate_in_init_elements\n", 2);
	else if (error == 6)
		ft_putstr_fd("caused by isol_in_init_elements\n", 2);
	else if (error == 7)
		ft_putstr_fd("caused by scale_in_init_elements\n", 2);
	else if (error == 8)
		ft_putstr_fd("caused by mlx_in_init_var\n", 2);
	return ;
}

//void	free_map(char ***map, int column, int row)
//{
//	int	count;
//	int	i;
//
//	count = 0;
//	while (count < column)
//	{
//		i = 0;
//		while (i < row)
//		{
//			free(map[count][i]);
//			i++;
//		}
//		free (map[count]);
//		count++;
//	}
//	free (map);
//	return ;
//}
//
//void	free_coordinate(int **coordinate, int column)
//{
//	int	count;
//
//	count = 0;
//	while (count < column)
//	{
//		free(coordinate[count]);
//		count++;
//	}
//	free (coordinate);
//	return ;
//}
