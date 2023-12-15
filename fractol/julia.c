/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:50:46 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:14:39 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z-->f(z)-->f(f(z))-->...
// - Verhalten beobachten (stabil - chaotisch)

// - extra: Sierpinski-Dreieck
// - extra: burning ship
#include "fractol.h"
#include <complex.h>

int	julia_color(double smooth_iter, t_fractol *red_thread)
{
	int		red;
	int		green;
	int		blue;

	red = (int)((sin(smooth_iter * 0.05) + 1.0) * 127);
	green = (int)((sin(smooth_iter * 0.03) + 1.0) * 127);
	blue = (int)((sin(smooth_iter * 0.01) + 1.0) * 127);
	red += red_thread->rj_min;
	green += red_thread->gj_min;
	blue += red_thread->bj_min;
	red_thread->color = (red << 16) | (green << 8) | blue;
	return (red_thread->color);
}

void	calc_julia(t_fractol *red_thread)
{
	while (red_thread->iter < red_thread->iter_max)
	{
		red_thread->temp = red_thread->z_real;
		red_thread->z_real = red_thread->z_real * red_thread->z_real
			- red_thread->z_im * red_thread->z_im + red_thread->julia_real;
		red_thread->z_im = 2 * red_thread->z_im * red_thread->temp
			+ red_thread->julia_im;
		if ((red_thread->z_real * red_thread->z_real + red_thread->z_im \
			* red_thread->z_im) > ESCAPE * ESCAPE)
			break ;
		red_thread->iter++;
	}
}

void	julia(double re, double im, t_fractol *red_thread)
{
	double	smooth_iter;

	red_thread->iter = 0;
	red_thread->z_real = (re / red_thread->zoom) + red_thread->hor
		/ red_thread->zoom;
	red_thread->z_im = (im / red_thread->zoom) + red_thread->ver
		/ red_thread->zoom;
	calc_julia(red_thread);
	if (red_thread->iter == red_thread->iter_max)
		red_thread->color = COLOR2;
	else
	{
		smooth_iter = check_for_color(red_thread);
		red_thread->color = julia_color(smooth_iter, red_thread);
	}
	my_mlx_pixel_put(&red_thread->image, red_thread->x,
		red_thread->y, red_thread->color);
}
