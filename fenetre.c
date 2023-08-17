/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:44:35 by hlasota           #+#    #+#             */
/*   Updated: 2023/08/17 16:52:31 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* w = 119, a = 97,  s = 115,  d = 100,  ^ = 65362, \/ = 65364 */

typedef struct s_vars {
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_all {
	t_vars	vars;
	int		tab_height;
	int		tab_width;
	int		decal_x;
	int		decal_y;
	int		start_x;
	int		start_y;
	float	angle;
	int		**tab;
}				t_all;

int	ft_absol(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	draw_line(t_vars vars, int begin_x, int begin_y,
	int end_x, int end_y, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	pixel_x = begin_x;
	pixel_y = begin_y;
	delta_y = end_y - begin_y;
	delta_x = end_x - begin_x;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		mlx_pixel_put(vars.mlx, vars.win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 119)
		all->start_y--;
	if (keycode == 65307)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	}
	printf("%d\n", all->start_y);
	return (0);
}

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	val_x(t_all all, int i, int j)
{
	return (cos(all.angle) * ((j * all.decal_x + all.start_x) 
			- (i * all.decal_y + all.start_y - all.tab[i][j])));
}

int	val_y(t_all all, int i, int j)
{
	return (((j * all.decal_x + all.start_x) + (i * all.decal_y 
				+ all.start_y - all.tab[i][j])) * sin(all.angle) 
				- all.tab[i][j]);
}

void	dl(t_all all, int i, int j)
{
	draw_line(all.vars, val_x(all, i, j), val_y(all, i, j),
		val_x(all, i, j + 1), val_y(all, i, j + 1),
		0x00FFFF + (all.tab[i][j] + all.tab[i][j + 1]) * 20);
}

void	dl_hauteur(t_all all, int i, int j)
{
	draw_line(all.vars, cos(all.angle) * ((j * all.decal_x + all.start_x)
			- (i * all.decal_y + all.start_y)), ((j * all.decal_x
				+ all.start_x) + (i * all.decal_y + all.start_y))
		* sin(all.angle) - all.tab[i][j], cos(all.angle) * ((j 
				* all.decal_x + all.start_x) - ((i + 1) * all.decal_y
				+ all.start_y)), ((j * all.decal_x + all.start_x)
			+ ((i + 1) * all.decal_y + all.start_y)) * sin(all.angle)
		- all.tab[i + 1][j], 0x00FFFF + (all.tab[i][j] 
			+ all.tab[i][j + 1]) * 20);
}

void	dessiner(t_all all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all.tab_height)
	{
		j = 0;
		while (j <= all.tab_width)
		{
			if (j != all.tab_width)
				dl(all, i, j);
			dl_hauteur(all, i, j++);
		}
		i++;
	}
	j = 0;
	while (j < all.tab_width)
	{
		if (j != all.tab_width)
		{
			dl(all, all.tab_height, j);
		}
		j++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_all	all;
	int		i;

	vars.mlx = mlx_init();
	vars.width = 640;
	vars.height = 480;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FdF");
	all.vars = vars;
	all.tab_height = 11 - 1;
	all.tab_width = 19 - 1;
	all.decal_x = vars.width / all.tab_width - 10;
	all.decal_y = vars.height / all.tab_height - 10;
	all.start_x = 150;
	all.start_y = -120;
	all.angle = 0.523599;
	all.tab = (int **)malloc(all.tab_height * sizeof(int **));
	int	temp_tab[11][19] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
	{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
	{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
	{0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
	{0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	i = 0;
	while (i <= all.tab_height)
	{
		all.tab[i] = malloc(all.tab_width * sizeof(int *));
		all.tab[i] = temp_tab[i];
		i++;
	}
	printf("%d\n", all.start_y);
	mlx_hook(vars.win, 2, 1L << 1, esc_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	dessiner(all);
	mlx_loop(vars.mlx);
}
