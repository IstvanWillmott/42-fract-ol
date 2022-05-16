/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:01:32 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/16 14:45:50 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

t_complex xyto_complex(int x, int y)
{
	t_complex	p;

	p.r = (double)x / (WIN_WIDTH * 0.26) - 2;
	p.i = (double)y / (WIN_HEIGHT * 0.45) - 1.1;
	/*
	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	*/
	return (p);
}

int mandelbrot(int x, int y)
{
	t_complex z;
	t_complex c;
	t_complex temp;
	//t_viewport v;
	int max_iteration;
	int i;

	max_iteration = 2000;
	i = 0;
	z = xyto_complex(x, y);
	c = xyto_complex(x, y);
	while (((z.r * z.r + z.i * z.i) < (4)) && (i < max_iteration))
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp.r;
		i++;
	}
	return (i);
}
