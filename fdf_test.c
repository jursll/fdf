/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:04:00 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/14 15:59:48 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		x, y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 500;
	y = 250;
	while (y < (1080 - 250))
	{
		x = 500;
		while (x < (1920 - 500))
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	x = 700 + 200;
	y = 350;
	while (y < (350 + 150))
	{
		x = 700 + 200;
		while (x < (1920 - 700 - 200))
		{
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	x = 700;
	y = 350 + 150;
	while (y < (350 + 150 + 150))
	{
		x = 700;
		while (x < (1920 - 700))
		{
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	x = 700 + 200;
	y = 350 + 150 + 150;
	while (y < (350 + 150 + 150 + 150))
	{
		x = 700 + 200;
		while (x < (1920 - 700 - 200))
		{
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
