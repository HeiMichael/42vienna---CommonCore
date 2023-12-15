/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:44:35 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:45:28 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z(n+1) = z²(n) + c mit Anfangswert z(0) = 0
// - x Iterationen um Verhalten zu beobachten:
// - Divergenz(weiß/bunt) oder Konvergenz(schwarz)

#include "fractol_bonus.h"

void	mandelbrot_color(double iterations, t_fractol *red_thread)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(((int)fmod(iterations * red_thread->r_sh, (double) \
		(red_thread->r_max - red_thread->r_min))) + red_thread->r_min);
	green = (int)(((int)fmod(iterations * red_thread->g_sh, (double) \
		(red_thread->g_max - red_thread->g_min))) + red_thread->g_min);
	blue = (int)(((int)fmod(iterations * red_thread->b_sh, (double) \
		(red_thread->b_max - red_thread->b_min))) + red_thread->b_min);
	red_thread->color = (red << 16) | (green << 8) | blue;
	my_mlx_pixel_put(&red_thread->image, red_thread->x, red_thread->y,
		red_thread->color);
}

double	check_for_color(t_fractol *red_thread)
{
	double	log_temp;
	double	i;
	double	iterations;

	iterations = 0.0;
	log_temp = log(red_thread->z_real * red_thread->z_real \
		+ red_thread->z_im * red_thread->z_im) / 2;
	i = log(log_temp / log(2)) / log(2);
	iterations = red_thread->iter + 1 - i;
	return (iterations);
}

void	mandelbrot(double re, double im, t_fractol *red_thread)
{
	double	iterations;

	red_thread->z_real = 0.0;
	red_thread->z_im = 0.0;
	red_thread->iter = 0;
	red_thread->c_real = ((re / red_thread->zoom) + red_thread->hor);
	red_thread->c_im = ((im / red_thread->zoom) + red_thread->ver);
	while (red_thread->iter < red_thread->iter_max)
	{
		red_thread->temp = red_thread->z_real;
		red_thread->z_real = red_thread->z_real * red_thread->z_real
			- red_thread->z_im * red_thread->z_im + red_thread->c_real;
		red_thread->z_im = 2 * red_thread->temp * red_thread->z_im
			+ red_thread->c_im;
		if (fabs(red_thread->z_real * red_thread->z_real
				+ red_thread->z_im * red_thread->z_im) > ESCAPE)
			break ;
		red_thread->iter++;
	}
	iterations = check_for_color(red_thread);
	if (red_thread->iter == red_thread->iter_max)
		my_mlx_pixel_put(&red_thread->image, red_thread->x,
			red_thread->y, COLOR1);
	else
		mandelbrot_color(iterations, red_thread);
}
