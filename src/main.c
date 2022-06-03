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

int	end(int keycode, t_imagewin *imagewin)
{
	if (keycode == 53)
	{
		mlx_destroy_window(imagewin->mlx, imagewin->win);
		exit(0);
	}
	return (0);
}

void	wrong_input(int argc, char *argv[])
{
	if (argc < 2)
		write(1, "Input required\n", 16);
	else if (argv[1][0] < 1 || argv[1][0] > 3)
		write(1, "Wrong input\n", 13);
	write(1, "1 - Mandelbrot\n", 16);
	write(1, "2 - Julia\n", 11);
	write(1, "3 - Burning Ship\n", 18);
	write(1, "ie: ./fractol 1\n", 17);
	exit (0);
}

int	render_next_frame(t_hold *hold)
{
	if (hold->mouse->isdown == 4)
	{
		draw_screen(hold->imagewin, hold->mouse, hold->render);
		hold->mouse->isdown = 0;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_mouse		mouse;
	t_imagewin	imagewin;
	int			render;
	t_hold		hold;

	render = 0;
	if ((argc == 2) && (argv[1][0] > 48) && (argv[1][0] < 52))
		render = argv[1][0] - 48;
	else
		wrong_input(argc, argv);
	imagewin.mlx = mlx_init();
	imagewin.win = mlx_new_window(imagewin.mlx,
			WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	mlx_mouse_hook(imagewin.win, mouse_hook_init, &mouse);
	mlx_hook(imagewin.win, 2, 1L << 0, end, &imagewin);
	hold.imagewin = &imagewin;
	hold.mouse = &mouse;
	mouse.zoomval = 1;
	hold.render = render;
	mlx_loop_hook(imagewin.mlx, render_next_frame, &hold);
	mlx_loop(imagewin.mlx);
	return (0);
}
