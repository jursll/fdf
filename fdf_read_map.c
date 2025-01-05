/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:02:04 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/05 16:03:29 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	fill_grid_line(char *line, t_map *map, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values)
		return (-1);
	map->grid[y] = malloc(sizeof(int) * map->width);
	if (!map->grid[y])
	{
		int i = 0;                                                                                                                                                                     
		while (values[i])
			free(values[i++]);
		free(values);
		return (-1);
	}
	x = 0;
	while (values[x] && x < map->width)
	{
		map->grid[y][x] = ft_atoi(values[x]);
		free(values[x]);
		x++;
	}
	free(values);
	return (0);
}

void	read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	if (line)
	{
		char **first_line = ft_split(line, ' ');
		map->width = 0;
		while (first_line[map->width])
			map->width++;
		free(line);
		int i = 0;
		while (first_line[i])
			free(first_line[i++]);
		free(first_line);
	}
	else
		return ;
	map->grid = malloc(sizeof(int *) * 1000);
	while (line)
	{
		if (fill_grid_line(line, map, y) < 0)
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	map->height = y;
}
