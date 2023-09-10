/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:10:43 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/10 11:34:51 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	deplacements(int keycode, t_all *all)
{
	if (keycode == 119)
	{
		all->map.start_y = (all->map.start_y - 10);
		all->map.start_x = all->map.start_x - 10;
	}
	if (keycode == 115)
	{
		all->map.start_y = (all->map.start_y + 10);
		all->map.start_x = (all->map.start_x + 10);
	}
	if (keycode == 97)
	{
		all->map.start_x = all->map.start_x - 10;
		all->map.start_y = (all->map.start_y + 10);
	}
	if (keycode == 100)
	{
		all->map.start_x = (all->map.start_x + 10);
		all->map.start_y = (all->map.start_y - 10);
	}
}

void	profondeur(int keycode, t_all *all)
{
	if (keycode == 113)
	{
		if (all->map.profondeur - 0.1 <= 0)
			all->map.profondeur = 0;
		else
			all->map.profondeur -= 0.1;
	}
	if (keycode == 101)
		all->map.profondeur = all->map.profondeur + 0.1;
}

void	ft_close(t_all all)
{
	int	i;

	i = 0;
	while (i < all.map.tab_height + 1)
		free(all.map.tab[i++]);
	free(all.map.tab);
	mlx_destroy_window(all.vars.mlx, all.vars.win);
	mlx_destroy_image(all.vars.mlx, all.img.img);
	mlx_destroy_display(all.vars.mlx);
	free(all.vars.mlx);
	exit(2);
}

int	key_hook(int keycode, t_all *all)
{
	deplacements(keycode, all);
	profondeur(keycode, all);
	if (keycode == 65362)
	{
		all->map.decal_x -= 1;
		all->map.decal_y -= 1;
	}
	if (keycode == 65364)
	{
		all->map.decal_x += 1;
		all->map.decal_y += 1;
	}
	if (keycode == 65361)
		all->map.angle -= 0.02;
	if (keycode == 65363)
		all->map.angle += 0.02;
	if (keycode == 65307)
		ft_close(*all);
	dessiner(*all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}
