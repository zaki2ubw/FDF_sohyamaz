/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:19 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/07 15:50:39 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

void	pixel_put(t_structs *val, int x, int y, int color)
{
	char	*dst;

	if (val == NULL)
		return ;
	else if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = val->image->addr
	+ y * val->image->line_length
	+ x * (val->image->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}
