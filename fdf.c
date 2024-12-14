/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:02:04 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/14 16:39:38 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	read_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y = 0;

	fd = open(filename, O_RDONLY);
	y = 0;

	while ((line = get_next_line(fd)))
	{
		// Utilise ft_split pour remplir map->grid[y]
		// ...
		y++;
		free(line);
	}
	close(fd);
	map->height = y;
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			// Projette les points (x, y, z) en (x', y')
			x1 = iso_x(x, y, data->map.grid[y][x]);
			y1 = iso_y(x, y, data->map.grid[y][x]);
			// Trace une ligne vers le point de droite
			if (x + 1 < data->map.width)
			{
				x2 = iso_x(x + 1, y, data->map.grid[y][x + 1]);
				y2 = iso_y(x + 1, y, data->map.grid[y][x + 1]);
				draw_line(data, x1, y1, x2, y2);
			}
			// Trace une ligne vers le point en dessous
			if (y + 1 < data->map.height)
			{
				x2 = iso_x(x, y + 1, data->map.grid[y + 1][x]);
				y2 = iso_y(x, y + 1, data->map.grid[y + 1][x]);
				draw_line(data, x1, y1, x2, y2);
			}
			x++; // Passe au point suivant dans la ligne
		}
		y++; // Passe à la ligne suivante
	}
}

void draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
    // Utilise ton algorithme de Bresenham ici
}

int	main(int ac, char **av)
{
	t_data	data;

	if	(ac != 2)
		return (ft_printf("Usage: ./fdf_program map.fdf\n"), 1);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1200, 1200, "FDF");
	data.img = mlx_new_image(data.mlx, 1200, 1200);
	data.addr = mlx_get_data_addr(data.img, data.bits_per_pixel, data.line_length, data.endian)

	read_map(av[1], &data.map);

	draw_map(&data);

	mlx_loop(data.mlx);
	return (0)
}
