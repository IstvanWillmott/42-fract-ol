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

void draw_screen(t_imagewin *imagewin)
{
	//t_image image;
	int x;
	int y;
	int ret;
	int divider;

	x = 0;
	y = 0;
	ret = 0;
	divider = 5;
	imagewin->image.image = mlx_new_image(imagewin->mlx, WIN_WIDTH, WIN_HEIGHT);
	imagewin->image.ptr = mlx_get_data_addr(imagewin->image.image, &imagewin->image.bits_per_pixel, &imagewin->image.stride, &imagewin->image.endian);
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			ret = mandelbrot(x, y);
			if (ret >= 50)
				pixel_draw(&imagewin->image, x, y, 0);
			else if (ret <= 49 && ret > 30)
				pixel_draw(&imagewin->image, x, y, 0x000066FF - ret*40);
			else if (ret <= 30 && ret > 20)
				pixel_draw(&imagewin->image, x, y, 0x0033CCFF - ret*30);
			else if (ret <= 20 && ret > 10)
				pixel_draw(&imagewin->image, x, y, 0x0099FF33 - ret*20);
			else 
				pixel_draw(&imagewin->image, x, y, 0x00CCFF00 - ret*10);
			y++;
		}
		if (y == WIN_HEIGHT)
			y = 0;
		x++;
	}
	mlx_put_image_to_window(imagewin->mlx, imagewin->win, imagewin->image.image, 0, 0);
}