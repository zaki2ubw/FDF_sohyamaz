/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:44:19 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 10:54:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
		exit (0);
	else if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
