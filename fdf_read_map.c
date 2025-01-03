/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:02:04 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/22 15:49:18 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	fill_grid_line(char *line, t_map *map, int y)
{
	// Splits the line and fills map->grid[y].
	// Add implementation here, ensuring Norminette compliance.
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
		return ; // Handle errors appropriately.
	line = get_next_line(fd);
	while (line)
	{
	if (fill_grid_line(line, map, y) < 0)
	{
		free(line);
		// Handle allocation errors and cleanup.
		return ;
	}
	free(line);
	line = get_next_line(fd);
	y++;
}
	close(fd);
	map->height = y;
}
