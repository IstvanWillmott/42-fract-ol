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

void	pixel_draw(t_image *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->ptr + (y * data->stride + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	find_pixel(int x, int render, t_mouse *mouse, t_imagewin *imagewin)
{
	int		ret;
	int		y;
	double	times;

	ret = 0;
	times = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (render == 1)
			ret = mandelbrot(x, y, mouse);
		if (render == 2)
			ret = julia(x, y, mouse);
		if (render == 3)
			ret = julia2(x, y, mouse);
		if (render == 4)
			ret = burning(x, y, mouse);
		times = (ret * ret) / 10;
		if (ret >= 50)
			pixel_draw(&imagewin->image, x, y, 0);
		else
			pixel_draw(&imagewin->image, x, y,
				(unsigned int) 16777215 - (times * 10000));
		y++;
	}
}

void	draw_screen(t_imagewin *imagewin, t_mouse *mouse, int render)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	imagewin->image.image = mlx_new_image(imagewin->mlx, WIN_WIDTH, WIN_HEIGHT);
	imagewin->image.ptr = mlx_get_data_addr(imagewin->image.image,
			&imagewin->image.bits_per_pixel,
			&imagewin->image.stride, &imagewin->image.endian);
	while (x < WIN_WIDTH)
	{
		find_pixel(x, render, mouse, imagewin);
		x++;
	}
	mlx_put_image_to_window(imagewin->mlx, imagewin->win,
		imagewin->image.image, 0, 0);
}
