/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:08:04 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/13 12:08:07 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void pixel_draw(t_image *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->ptr + (y * data->stride + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = colour;
}

//#include <stdio.h>

void draw_screen(t_mlx *mlx, void *mlx_win)
{
	t_image image;
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	image.image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image.ptr = mlx_get_data_addr(image.image, &image.bits_per_pixel, &image.stride, &image.endian);
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			ret = mandelbrot(x, y);
			if (ret == 50)
				pixel_draw(&image, x, y, 0x00000000);
			else
				pixel_draw(&image, x, y, 0x00FFFFFF);
			//printf("%d, %d rets: %d\n", x, y, ret);
			y++;
		}
		if (y == WIN_HEIGHT)
			y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, image.image, 0, 0);
}