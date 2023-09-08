/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:09:47 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/07 17:22:28 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_absol(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_line line)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	pixel_x = line.begin_x;
	pixel_y = line.begin_y;
	delta_y = line.end_y - line.begin_y;
	delta_x = line.end_x - line.begin_x;
	pixels = sqrt(ft_absol(delta_x * delta_x) + ft_absol(delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(&line.img, pixel_x, pixel_y, line.b_color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
