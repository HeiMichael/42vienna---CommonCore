/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:44:35 by miheider          #+#    #+#             */
/*   Updated: 2023/11/16 19:25:37 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z(n+1) = z²(n) + c mit Anfangswert z(0) = 0
// - x Iterationen um Verhalten zu beobachten:
// - Divergenz(weiß/bunt) oder Konvergenz(schwarz)

#include "fractol.h"

int	mandelbrot(int x, int y, t_fractol *red_thread)
{
	red_thread->z_real = 0.0;
	red_thread->z_im = 0.0;
	red_thread->iter = 0;

	red_thread->c_real = x / red_thread->zoom + //OFFSET?;
	red_thread->c_im = y / red_thread->zoom + //OFFSET??;
	while (red_thread->iter < ITER_MAX)
	{
		red_thread->temp = red_thread->z_real;
		red_thread->z_real = red_thread->z_real * red_thread->z_real -
			red_thread->z_im * red_thread->z_im + red_thread->c_real;	//Real comp
		red_thread->z_im = 2 * red_thread->z_im * red_thread->temp + 	//Imag comp
			red_thread->c_im;
		red_thread_iter++;
	}

	if (red_thread->iter == ITER_MAX)
		coloring_pixels(red_thread, x, y, 0x000000);
	else
		coloring_pixels(red_thread, x, y, color * red_thread->iter);

}
