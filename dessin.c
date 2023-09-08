/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:12:10 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/07 17:22:25 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	remplir(t_all all)
{
	int		i;
	t_line	line;

	i = 0;
	while (i <= all.vars.height)
	{
		line.img = all.img;
		line.begin_x = 0;
		line.begin_y = i;
		line.end_x = all.vars.width;
		line.end_y = i;
		line.b_color = 0x000000;
		draw_line(line);
		i++;
	}
}

void	dessiner(t_all all)
{
	int	i;
	int	j;

	i = 0;
	remplir(all);
	while (i < all.map.tab_height)
	{
		j = 0;
		while (j < all.map.tab_width)
		{
			if (j != all.map.tab_width)
				dl(all, i, j);
			dl_hauteur(all, i, j++);
		}
		i++;
	}
	j = 0;
}
