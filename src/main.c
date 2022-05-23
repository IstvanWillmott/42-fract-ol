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

int end(int keycode, t_imagewin *imagewin)
{
	if (keycode == 53)
	{
		mlx_destroy_window(imagewin->mlx, imagewin->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
	//t_mlx	*mlx;
	//void	*mlx_win;
	t_mouse	mouse;
	t_imagewin imagewin;

	imagewin.mlx = mlx_init();
	imagewin.win = mlx_new_window(imagewin.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	draw_screen(&imagewin);
	mlx_mouse_hook(imagewin.win, mouse_hook_init, &mouse);
	//mlx_key_hook(imagewin.mlx, end, &imagewin);
	mlx_hook(imagewin.win, 2, 1L<<0, end, &imagewin);
	mlx_loop(imagewin.mlx);
	return (0);
}