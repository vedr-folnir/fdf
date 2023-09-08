/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_pts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:11:31 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/08 17:23:41 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	val_x(t_all all, int i, int j)
{
	return (cos(all.map.angle) * ((j * all.map.decal_x + all.map.start_x)
			- (i * all.map.decal_y + all.map.start_y)));
}

int	val_y(t_all all, int i, int j)
{
	return (((j * all.map.decal_x + all.map.start_x)
			+ (i * all.map.decal_y + all.map.start_y)) * sin(all.map.angle)
		- all.map.tab[i][j] * all.map.profondeur);
}

void	dl(t_all all, int i, int j)
{
	t_line	line;

	line.img = all.img;
	line.begin_x = val_x(all, i, j);
	line.begin_y = val_y(all, i, j);
	line.end_x = val_x(all, i, j + 1);
	line.end_y = val_y(all, i, j + 1);
	line.b_color = color(all, i, j);
	line.e_color = color(all, i, j + 1);
	draw_line(line);
}

int	color(t_all all, int i, int j)
{
	if (all.map.tab[i][j] > 0)
		return (all.map.col_plus * all.map.tab[i][j] * 255 * 255);
	else if (all.map.tab[i][j] < 0)
		return (all.map.col_plus * all.map.tab[i][j]);
	else
		return (0xFFFFFF);
}

void	dl_hauteur(t_all all, int i, int j)
{
	t_line	line;

	line.img = all.img;
	line.begin_x = cos(all.map.angle) * ((j * all.map.decal_x
				+ all.map.start_x) - (i * all.map.decal_y
				+ all.map.start_y));
	line.begin_y = ((j * all.map.decal_x + all.map.start_x)
			+ (i * all.map.decal_y
				+ all.map.start_y)) * sin(all.map.angle)
		- all.map.tab[i][j] * all.map.profondeur;
	line.end_x = cos(all.map.angle) * ((j * all.map.decal_x
				+ all.map.start_x)
			- ((i + 1) * all.map.decal_y + all.map.start_y));
	line.end_y = ((j
				* all.map.decal_x + all.map.start_x)
			+ ((i + 1) * all.map.decal_y + all.map.start_y))
		* sin(all.map.angle) - all.map.tab[i + 1][j] * all.map.profondeur;
	line.b_color = color(all, i, j);
	line.e_color = color(all, i + 1, j);
	draw_line(line);
}
