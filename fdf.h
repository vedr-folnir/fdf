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

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_vars {
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	*x;
	int		tab_height;
	int		tab_width;
	int		decal_x;
	int		decal_y;
	int		start_x;
	int		start_y;
	float	angle;
	float	profondeur;
	int		**tab;
	int		min;
	int		max;
	int		col_plus;
	int		col_minus;
}				t_map;

typedef struct s_all {
	t_vars	vars;
	t_data	img;
	t_map	map;
}				t_all;

typedef struct s_line {
	t_data	img;
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		b_color;
	int		e_color;
}				t_line;

t_all	st_innit(t_vars vars, t_all all, t_data img, const char *filename);
int		ft_absol(int val);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_line line);
void	deplacements(int keycode, t_all *all);
void	ft_close(t_all all);
int		key_hook(int keycode, t_all *all);
int		val_x(t_all all, int i, int j);
int		val_y(t_all all, int i, int j);
void	dl(t_all all, int i, int j);
void	der_val_hauteur(t_all all, int i, int j);
void	dl_hauteur(t_all all, int i, int j);
void	remplir(t_all all);
void	dessiner(t_all all);
int		count_lines_in_file(const char *filename);
int		extract_line_lenght(char *str);
int		donne_fd(const char *path);
void	extract_map(int fd, t_map map);
void	map_fst_error(int **tab);
int		ft_min(t_map map);
int		ft_max(t_map map);
void	st_innit_bis(t_all all);
int		color(t_all all, int i, int j);

#endif
