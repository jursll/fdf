/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:23:03 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/22 15:44:46 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_map
{
	int	**grid;
	int	width;
	int	height;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}	t_data;

void	read_map(char *filename, t_map *map);
void	draw_map(t_data *data);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2);
int		iso_x(int x, int y, int z);
int		iso_y(int x, int y, int z);

#endif
