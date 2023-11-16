/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:29 by miheider          #+#    #+#             */
/*   Updated: 2023/11/16 16:33:01 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rescale_pixels(int x, int y, t_fractol *red_thread)
{
//	rescaling+mandelbrot mit neuen Werten aufrufen
	double	re;
	double	im;

	re = ((((0.5 - (-2)) * (x - 0)) / (WIDTH)) + (-2));
	im = ((((1.5 - (-1.5) * (y - 0)) / (HIGTH))) + (-1.5));
	if (red_thread->name == "mandelbrot")
		mandelbrot (re, im, &red_thread);
	else
		julia (re, im, &red_thread);
}

void pixels(t_fractol *red_thread)
{
	int x;
	int	y;

	y = 0;
	while (x <= HIGHT)
	{
		y = 0;
		while (y <= WIDTH)
		{
			rescale_pixel (x, y, &red_thread);
			y++;
		}
		x++;
	}
}
