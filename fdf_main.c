/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:41:34 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/22 15:42:02 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf_program maps/map.fdf\n"), (1));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error: MLX initialization failed.\n"), (1));
	data.win = mlx_new_window(data.mlx, 1200, 1200, "FDF");
	data.img = mlx_new_image(data.mlx, 1200, 1200);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	read_map(argv[1], &data.map);
	draw_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
