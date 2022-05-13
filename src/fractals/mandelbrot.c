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

t_complex xyto_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}

void mandelbrot(t_mlx *mlx, int x, int y)
{
	t_complex xc;
	t_complex yc;
	t_complex temp;
	t_viewport v;
	int cur_iteration;
	int max_iteration;

	cur_iteration = 0;
	max_iteration = 1;
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
	xc = xyto_complex(x, y, v);
	yc = xyto_complex(x, y, v);
	while ((x*x + y*y <= 2) && (cur_iteration < max_iteration))
	{
		
	}
}