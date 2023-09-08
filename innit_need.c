/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_need.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:12:56 by hlasota           #+#    #+#             */
/*   Updated: 2023/09/08 15:51:14 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	count_lines_in_file(const char *filename)
{
	int		file;
	int		lines;
	char	buffer[1];

	file = donne_fd(filename);
	lines = 0;
	while (read(file, buffer, sizeof(buffer)) > 0)
		if (buffer[0] == '\n')
			lines++;
	if (buffer[0] != '\n' && lines > 0)
		lines++;
	close(file);
	return (lines);
}

int	extract_line_lenght(char *str)
{
	char	*ptr;
	int		count;

	ptr = str;
	count = 0;
	while (*ptr != '\0' || *ptr != '\n')
	{
		if (*ptr == 0)
			return (count);
		while (*ptr == ' ')
			ptr++;
		count++;
		while (*ptr != ' ' && *ptr != '\0')
			ptr++;
	}
	free(str);
	return (count);
}

int	donne_fd(const char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit (-1);
	}
	return (file);
}

void	extract_map(int fd, t_map map)
{
	char	*line;
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	while (i <= map.tab_height)
	{
		line = get_next_line(fd);
		ptr = line;
		j = 0;
		while (*ptr != '\0')
		{
			while (*ptr == ' ')
				ptr++;
			map.tab[i][j++] = atoi(ptr);
			while (*ptr != ' ' && *ptr != '\0')
				ptr++;
		}
		free(line);
		i++;
	}
	map_fst_error(map.tab);
}

void	map_fst_error(int **tab)
{
	int	i;

	i = 1;
	if (!(tab[0][0] * -1 >= 0))
	{
		while (i * 10 <= tab[0][0])
			i *= 10;
		tab[0][0] = tab[0][0] % i;
	}
}
