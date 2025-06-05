/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:48:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/05 22:00:06 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int	color_init(t_color *palette)
{
	int	color;

	color = 0;
	color = (palette->clear << 24) | (palette->red << 16)\
	| (palette->green << 8) | palette->blue;
	palette->clear = (palette->clear) % 256;
	palette->red = (palette->red) % 256;
	palette->green = (palette->green) % 256;
	palette->blue = (palette->blue) % 256;
	return (color);
}

