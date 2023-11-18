/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:50:46 by miheider          #+#    #+#             */
/*   Updated: 2023/11/18 19:38:19 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - z-->f(z)-->f(f(z))-->...
// - Verhalten beobachten (stabil - chaotisch)

// - extra: Sierpinski-Dreieck
// - extra: burning ship
#include "fractol.h"

void	julia(double x, double y, t_fractol *red_thread)
{
	red_thread->iter = 0;
	//red_thread.c_real = argv[2];
	//red_thread.c_im = argv[3];
	red_thread->z_real = x / red_thread->zoom; //OFFSET?
	red_thread->z_im = y / red_thread->zoom; //OFFSET?

	while (red_thread->iter < ITER_MAX)
	{
		red_thread->temp = red_thread->z_real;
		red_thread->z_real = red_thread->z_real * red_thread->z_real -
			red_thread->z_im * red_thread->z_im + red_thread->c_real;	//Real comp
		red_thread->z_im = 2 * red_thread->z_im * red_thread->temp + //Imag comp
			red_thread->c_im;
		red_thread->iter++;
	}
	if (red_thread->iter == ITER_MAX)
	{
		my_mlx_pixel_put(&red_thread->image, x, y, 0x0);
	}
	else
	{
		my_mlx_pixel_put(&red_thread->image, x, y, 0x134567 * red_thread->iter);
	}
}
