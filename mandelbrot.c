/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:44:35 by miheider          #+#    #+#             */
/*   Updated: 2023/11/19 16:21:25 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z(n+1) = z²(n) + c mit Anfangswert z(0) = 0
// - x Iterationen um Verhalten zu beobachten:
// - Divergenz(weiß/bunt) oder Konvergenz(schwarz)

#include "fractol.h"
#include "stdio.h"

void	mandelbrot(int x, int y, double re, double im, t_fractol *red_thread)
{
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
			red_thread->z_im * red_thread->z_im) > 2147483647)
			break ;
		red_thread->iter++;
	}
	if (red_thread->iter == ITER_MAX)
		my_mlx_pixel_put(&red_thread->image, x, y, COLOR1);
	else
		my_mlx_pixel_put(&red_thread->image, x, y, COLOR2 * red_thread->iter);
}
