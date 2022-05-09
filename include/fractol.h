/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:04 by iwillmot          #+#    #+#             */
/*   Updated: 2022/05/09 13:42:05 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <pthread.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ZOOM 1.1f
# define THREADS 8

typedef struct	s_rgba
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_rgba;

typedef struct s_mouse
{
	char	isdown;
	int		x;
	int		y;
	int		lastx;
	int		lasty;
}	t_mouse;

typedef struct s_image
{
	void	*image;
	char	*ptr;
	int		bits_per_pixel;
	int		stride;
	int		endian;
}	t_image;

#endif
