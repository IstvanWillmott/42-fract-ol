/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:47:16 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/20 11:47:18 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

void	mouse_complex(t_mouse *mouse)
{
	mouse->mouse_complex.r = (((double)mouse->x / ((WIN_WIDTH) * 0.26) - 2));
	mouse->mouse_complex.i = (((double)mouse->y / ((WIN_HEIGHT) * 0.45) - 1.1));
}

int	mouse_hook_init(int keycode, int x, int y, t_mouse *mouse)
{
	mouse->isdown = keycode;
	if (mouse->isdown == 4)
	{
		mouse->lastx = mouse->x;
		mouse->lasty = mouse->y;
		mouse->x = x;
		mouse->y = y;
		mouse->zoomval += 1;
	}
	mouse_complex(mouse);
	return (0);
}
