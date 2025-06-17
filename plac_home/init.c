/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:58:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 11:40:47 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	init_val(t_structs **val)
{
	*val = ft_calloc(sizeof(t_structs), 1);
	if (*val == NULL)
		return (ERR_ALLOC_FAILED);
	return (0);
}

int	init_maps(t_structs *val)
{
	val->map = ft_calloc(sizeof(t_map), 1);
	if (val->map == NULL)
		return (ERR_ALLOC_FAILED);
	val->coord = NULL;
	val->isom = NULL;
	return (0);
}

int	init_mlx(t_structs *val)
{
	val->var = ft_calloc(sizeof(t_var), 1);
	if (val->var == NULL)
		return (ERR_ALLOC_FAILED);
	val->image = ft_calloc(sizeof(t_image), 1);
	if (val->image == NULL)
		return (ERR_ALLOC_FAILED);
	return (0);
}

int	init_modules(t_structs *val)
{
	val->scale = ft_calloc(sizeof(t_scale), 1);
	if (val->scale == NULL)
		return (ERR_ALLOC_FAILED);
	val->calc = ft_calloc(sizeof(t_calc), 1);
	if (val->calc == NULL)
		return (ERR_ALLOC_FAILED);
	return (0);
}

//int	init_color(t_structs *val)
//{
//	val->palette = ft_calloc(sizeof(t_color), 1);
//	if (val->palette == NULL)
//		return (ERR_ALLOC_FAILED);
//	return (0);
//}
