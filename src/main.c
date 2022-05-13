/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:46:12 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/09 12:46:14 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void pixel_test(t_image *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->ptr + (y * data->stride + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = colour;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_image image;
	int g = 0;
	int b = 0;
	//void	*mlx_img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	image.image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image.ptr = mlx_get_data_addr(image.image, &image.bits_per_pixel, &image.stride, &image.endian);
	while (g < WIN_WIDTH)
	{
		while (b < WIN_HEIGHT)
		{
			pixel_test(&image, g, b, 0x009999FF);
			b++;
		}
		if (b == WIN_HEIGHT)
			b = 0;
		pixel_test(&image, g, b+10, 0x000033CC);
		pixel_test(&image, g, b+b, 0x0000FFFF);
		pixel_test(&image, g, b+15, 0x0066FF00);
		pixel_test(&image, g, b+20, 0x00FFFF00);
		g++;
		b++;
	}
	mlx_put_image_to_window(mlx, mlx_win, image.image, 0, 0);

	mlx_loop(mlx);
	return (0);
}