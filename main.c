/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:44:35 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/10 10:32:55 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_all	st_innit(t_vars vars, t_all all, t_data img, const char *filename)
{
	int		fd;
	int		i;

	fd = donne_fd(filename);
	all.img = img;
	all.map.tab_height = count_lines_in_file(filename) - 1;
	all.map.x = get_next_line(fd);
	all.map.tab_width = extract_line_lenght(all.map.x) - 1;
	free(all.map.x);
	all.map.tab = (int **)malloc((all.map.tab_height + 1) * sizeof(int **));
	i = 0;
	while (i <= all.map.tab_height)
		all.map.tab[i++] = (int *)malloc((all.map.tab_width) * sizeof(int *));
	fd = donne_fd(filename);
	extract_map(fd, all.map);
	close(fd);
	all.map.decal_x = vars.width / all.map.tab_width ;
	all.map.decal_y = vars.height / all.map.tab_height;
	all.map.start_x = 220;
	all.map.start_y = -120;
	all.map.angle = 0.523599;
	all.map.profondeur = 1;
	st_innit_bis(all);
	return (all);
}

void	st_innit_bis(t_all all)
{
	all.map.max = ft_max(all.map);
	all.map.min = ft_absol(ft_min(all.map));
	if (all.map.min != 0)
		all.map.col_minus = (int)(0xff / all.map.min);
	else
		all.map.col_minus = 0;
	if (all.map.max != 0)
		all.map.col_plus = (int)(0xff / all.map.max);
	else
		all.map.col_plus = 0;
}

int	main(int argc, char const *argv[])
{
	t_vars	vars;
	t_all	all;
	t_data	img;

	if (argc != 2)
	{
		perror("Erreur avec les arguments");
		return (1);
	}
	vars.mlx = mlx_init();
	vars.width = 640;
	vars.height = 480;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FdF");
	all.vars = vars;
	img.img = mlx_new_image(all.vars.mlx, 10000, 10000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	all = st_innit(vars, all, img, argv[1]);
	dessiner(all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &all);
	mlx_loop(all.vars.mlx);
}
