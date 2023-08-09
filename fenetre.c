/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:44:35 by hlasota           #+#    #+#             */
/*   Updated: 2023/08/09 18:10:32 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

/* w = 119, a = 97,  s = 115,  d = 100*/
typedef struct	s_img {
	int		x;
	int		y;
}				t_img;

typedef struct	s_vars {
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_all {
	t_vars	vars;
	t_img	img;
	char	**map;
}				t_all;

int ft_absol(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int draw_line(t_vars vars, int beginX, int beginY,
 int endX, int endY, int color)
{
	double deltaX; 
	double deltaY;
	int pixels;
	double pixelX = beginX;
	double pixelY = beginY;

	deltaY = endY - beginY;
	deltaX = endX - beginX;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		mlx_pixel_put(vars.mlx, vars.win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

int	key_hook(int keycode, /*t_vars *vars,*/ t_all *all)
{
	//mlx_clear_window(all->vars.mlx, all->vars.win);

	/*while (p.x != i && p.y != 200)
	{
		if (p.x % 10 == 0)
			mlx_pixel_put(all->vars.mlx, all->vars.win, p.x++, p.y--, 0x00FFFF00);
		else
			mlx_pixel_put(all->vars.mlx, all->vars.win, p.x++, p.y--, 0x00FF0000);
	}*/
	//ligne(p, all->img, all->vars);
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

int	win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int main(int argc, char const *argv[])
{
	t_vars	vars;
	t_img	image;
	t_all	all;
	
	printf("%s\n", argv[1]);
	int fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	char *map = gnl(fd);
	printf("%s\n", map);
	vars.mlx = mlx_init();
	vars.width = 640;
	vars.height = 480;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FdF");
	image.x = 320;
	image.y = 240;
	all.vars=vars;
	all.img=image;
	mlx_key_hook(all.vars.win, key_hook, &all);

	mlx_hook(vars.win, 2, 1L<<1, esc_close, &vars);
	mlx_hook(vars.win, 17, 1L<<17, win_close, &vars);

	t_img p;
	p.x = 25;
	p.y = 401;
	draw_line(vars, p.x, p.y, image.x, image.y, 0xFFFFFF);
	draw_line(vars, image.x, image.y, 40, 66, 0xFF00FF);
	mlx_loop(vars.mlx);
}