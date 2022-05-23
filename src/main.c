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

typedef struct s_hold
{
	t_mouse	*mouse;
	t_imagewin *imagewin;
}	t_hold;

int render_next_frame(t_hold *hold)
{
	draw_screen(hold->imagewin, hold->mouse);
	return (1);
}

int main(void)
{
	t_mouse	mouse;
	t_imagewin imagewin;
	t_hold hold;

	imagewin.mlx = mlx_init();
	imagewin.win = mlx_new_window(imagewin.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	//printf("1\n");
	mlx_mouse_hook(imagewin.win, mouse_hook_init, &mouse);
	//printf("2\n");
	//draw_screen(&imagewin, &mouse);
	//printf("3\n");
	//printf("4\n");
	mlx_hook(imagewin.win, 2, 1L<<0, end, &imagewin);
	hold.imagewin = &imagewin;
	hold.mouse = &mouse;
	//printf("5\n");
	mlx_loop_hook(imagewin.mlx, render_next_frame, &hold);
	//printf("6\n");
	mlx_loop(imagewin.mlx);
	return (0);
}