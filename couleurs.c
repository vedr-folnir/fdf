/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleurs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:41:15 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/08 17:28:43 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_max(t_map map)
{
	int	i;
	int	j;

	map.max = map.tab[0][0];
	i = 0;
	while (i < map.tab_height)
	{
		j = 0;
		while (j < map.tab_width)
		{
			if (map.tab[i][j] > map.max)
				map.max = map.tab[i][j];
			j++;
		}
		i++;
	}
	return (map.max);
}

int	ft_min(t_map map)
{
	int	i;
	int	j;

	map.min = map.tab[0][0];
	i = 0;
	while (i < map.tab_height)
	{
		j = 0;
		while (j < map.tab_width)
		{
			if (map.tab[i][j] < map.min)
				map.min = map.tab[i][j];
			j++;
		}
		i++;
	}
	return (map.min);
}
