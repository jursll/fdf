/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:40:21 by julrusse          #+#    #+#             */
/*   Updated: 2025/01/03 17:30:49 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int iso_x(int x, int y, int z)
{
	(void)z;
	return ((x - y) * cos(0.523599));
}

static int iso_y(int x, int y, int z)
{
	return ((x + y) * sin(0.523599) - z);
}

static void	project_and_draw(t_data *data, int x, int y)
{
	int	x1, y1, x2, y2;

	x1 = iso_x(x, y, data->map.grid[y][x]);
	y1 = iso_y(x, y, data->map.grid[y][x]);
	if (x + 1 < data->map.width)
	{
		x2 = iso_x(x + 1, y, data->map.grid[y][x + 1]);
		y2 = iso_y(x + 1, y, data->map.grid[y][x + 1]);
		draw_line(data, x1, y1, x2, y2);
	}
	if (y + 1 < data->map.height)
	{
		x2 = iso_x(x, y + 1, data->map.grid[y + 1][x]);
		y2 = iso_y(x, y + 1, data->map.grid[y + 1][x]);
		draw_line(data, x1, y1, x2, y2);
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			project_and_draw(data, x, y);
			x++;
		}
		y++;
	}
}
