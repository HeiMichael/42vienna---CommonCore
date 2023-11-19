/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:44:35 by miheider          #+#    #+#             */
/*   Updated: 2023/11/19 17:55:09 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z(n+1) = z²(n) + c mit Anfangswert z(0) = 0
// - x Iterationen um Verhalten zu beobachten:
// - Divergenz(weiß/bunt) oder Konvergenz(schwarz)

#include "fractol.h"

double	check_for_color (t_fractol *red_thread)
{
	double	log_temp;
	double	i;
	double	iterations;

	iterations = 0.0;
	log_temp = log(red_thread->z_real * red_thread->z_real + red_thread->z_im * red_thread->z_im) / 2;
	i = log(log_temp / log(2)) / log(2);
	iterations = red_thread->iter + 1 - i;
	return (iterations);
}


void	mandelbrot(int x, int y, double re, double im, t_fractol *red_thread)
{
	double	iterations;
	int	color;
	int	red;
	int	green;
	int	blue;

	red_thread->z_real = 0.0;
	red_thread->z_im = 0.0;
	red_thread->iter = 0;
	red_thread->c_real = (double)re / red_thread->zoom;
	red_thread->c_im = (double)im / red_thread->zoom;
	while (red_thread->iter < ITER_MAX)
	{
		red_thread->temp = red_thread->z_real;
		red_thread->z_real = red_thread->z_real * red_thread->z_real -
			red_thread->z_im * red_thread->z_im + red_thread->c_real;	//Real comp
		red_thread->z_im = 2 * red_thread->temp * red_thread->z_im + 	//Imag comp
			red_thread->c_im;
		if (fabs(red_thread->z_real * red_thread->z_real +
			red_thread->z_im * red_thread->z_im) > ESCAPE * ESCAPE)
			break ;
		red_thread->iter++;
	}
	iterations = check_for_color(red_thread);
	if (red_thread->iter == ITER_MAX)
		my_mlx_pixel_put(&red_thread->image, x, y, COLOR1);
	else
	{
		red = (int)(((int)fmod(iterations * RED_SHIFT, (double)(RED_MAX - RED_MIN))) + RED_MIN);
		green = (int)(((int)fmod(iterations * GREEN_SHIFT, (double)(GREEN_MAX - GREEN_MIN))) + GREEN_MIN);
		blue = (int)(((int)fmod(iterations * BLUE_SHIFT, (double)(BLUE_MAX - BLUE_MIN))) + BLUE_MIN);
		color = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(&red_thread->image, x, y, color);
	}


//	if (red_thread->iter == ITER_MAX)
//		my_mlx_pixel_put(&red_thread->image, x, y, COLOR1);
//	else
//		my_mlx_pixel_put(&red_thread->image, x, y, COLOR2 * red_thread->iter);
}
