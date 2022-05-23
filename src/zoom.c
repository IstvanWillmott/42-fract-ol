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

t_complex mouse_complex(t_mouse *mouseloc)
{
	t_complex mousecomp;

	mousecomp.r = ((double)mouseloc->x / ((WIN_WIDTH) * 0.26) - 2);
	mousecomp.i = ((double)mouseloc->y / ((-WIN_HEIGHT) * 0.45)+1.1);
	return(mousecomp);
}



#include <stdio.h>

int mouse_hook_init(int keycode, int x, int y, t_mouse *mouse)
{
	t_complex mousecomp;

	printf("KeyPressed: %d\n", keycode);
	mouse->isdown = keycode;
	mouse->x = x;
	mouse->y = y;
	printf("Mousex: %d\n", mouse->x);
	printf("Mousey: %d\n\n", mouse->y);
	mousecomp = mouse_complex(mouse);
	printf("Mouse real: %f\n", mousecomp.r);
	printf("Mouse imaginary: %f\n\n", mousecomp.i);
	return (0);
}

