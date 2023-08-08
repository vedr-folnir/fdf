#include	"mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

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

void	ligne(t_img p1, t_img p2, t_vars vars)
{
	int	x;
	int	y;
	int	i;
	printf("%d-%d--%d-%d\n", p1.x,p2.x,p1.y,p2.y);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		x = ft_absol(p1.x - p2.x);
		y = ft_absol(p1.y - p2.y);
		i = 0;
		printf("%d\n", x/y);
		if (y == 0)
		{
			if (p1.x - p2.x > 0)
				mlx_pixel_put(vars.mlx, vars.win,
				 --p1.x, p1.y, 0x00FFFF00);
			else
				mlx_pixel_put(vars.mlx, vars.win,
				 ++p1.x, p1.y, 0x00FFFF00);
			continue;
		}
		if (x/y > 0)
		{
			while (i < x/y)
			{
				if (p1.x - p2.x > 0)
					mlx_pixel_put(vars.mlx, vars.win,
					 --p1.x, p1.y, 0x00FFFF00);
				else
					mlx_pixel_put(vars.mlx, vars.win,
					 ++p1.x, p1.y, 0x00FFFF00);
				i++;
			}
		}
		if (p1.y - p2.y > 0 )
			mlx_pixel_put(vars.mlx, vars.win,
			 p1.x, --p1.y, 0x00FFFF00);
		else
				mlx_pixel_put(vars.mlx, vars.win,
			 p1.x, ++p1.y, 0x00FFFF00);
		
	}
}

/*if (x > y)
		{
			if (p1.x - p2.x > 0)
				mlx_pixel_put(vars.mlx, vars.win,
				 --p1.x, p1.y, 0x00FFFF00);
			else
				mlx_pixel_put(vars.mlx, vars.win,
				 ++p1.x, p1.y, 0x00FFFF00);
		}
		else
		{
			if (p1.y - p2.y > 0)
				mlx_pixel_put(vars.mlx, vars.win,
				 p1.x, --p1.y, 0x00FFFF00);
			else
				mlx_pixel_put(vars.mlx, vars.win,
				 p1.x, ++p1.y, 0x00FFFF00);
		}*/

int	key_hook(int keycode, /*t_vars *vars,*/ t_all *all)
{
	//mlx_clear_window(all->vars.mlx, all->vars.win);
	t_img p;
	p.x = 10;
	p.y = 400;
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

int	main(void)
{
	t_vars	vars;
	t_img	image;
	t_all	all;
	

	vars.mlx = mlx_init();
	vars.width = 640;
	vars.height = 480;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FdF");
	image.x = 320;
	image.y = 240;
	all.vars=vars;
	all.img=image;
	mlx_key_hook(all.vars.win, key_hook, &all);



	t_img p;
	p.x = 25;
	p.y = 401;
	ligne(p, image, vars);

	mlx_loop(vars.mlx);
}