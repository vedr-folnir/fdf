/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:53:32 by hlasota           #+#    #+#             */
/*   Updated: 2023/08/17 14:36:56 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
# include <math.h>

typedef struct	s_vars {
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_all {
	t_vars	vars;
	//int 	tab[11][9];

	int 	tab_height;
	int		tab_width;
	int		decal_x;
	int		decal_y;
	int		start_x;
	int		start_y;
	float 	angle;
	
}				t_all;


void draw_line(t_vars vars, int beginX, int beginY, int endX, int endY, int color);
int ft_absol(int val);
int	key_hook(int keycode, t_all *all);
void	dessiner(t_all all);