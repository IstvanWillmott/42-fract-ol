/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:01:32 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/09 17:01:35 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

t_complex xyto_complex(int x, int y)
{
	t_complex	p;
	p.r = (double)x / WIN_WIDTH;
	p.i = (double)y /WIN_HEIGHT;
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
	t_complex xc;
	t_complex yc;
	t_complex temp;
	//t_viewport v;
	int max_iteration;
	int i;

	max_iteration = 50;
	//v.xmin = -2.0f;
	//v.xmax = 1.0f;
	//v.ymin = -1.0f;
	//v.ymax = 1.0f;
	//v.offx = -0.5f;
	//v.offy = 0.5f;
	//v.zoom = 0;
	i = 0;
	xc = xyto_complex(x, y);
	yc = xyto_complex(x, y);
	while (((xc.r * xc.r + xc.i * xc.i) < (1 << 8)) && (i < max_iteration))
	{
		temp.r = xc.r * xc.r - xc.i * xc.i + yc.r;
		temp.i = xc.r * xc.i * 2 + yc.i;
		if (xc.r == temp.r && xc.i == temp.i)
		{
			//i = max_iteration;
			break ;
		}
		xc.r = temp.r;
		xc.i = temp.i;
		i++;
	}
	return (i);
}