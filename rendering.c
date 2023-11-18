/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:29 by miheider          #+#    #+#             */
/*   Updated: 2023/11/18 19:37:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "stdio.h"

void	rescale_pixels(int x, int y, t_fractol *red_thread)
{
//	rescaling+mandelbrot mit neuen Werten aufrufen
	double	re;
	double	im;


	//re = (x / (double)WIDTH) * ((1.0 - (-1.5))) + (-1.5);
	//im = (y / (double)HEIGHT) * (((-1.2) - (1.2))) + (1.2);
	re = (((0.5 - (-2)) * x) / ((double)WIDTH)) + (-2);
	im = (((((-1.5) - 1.5) * y) / ((double)HEIGHT)) + 1.5);
	//printf("%lf %lf\n", re, im);
	if (ft_strncmp(red_thread->name, "mandelbrot", 10) == 0)
		mandelbrot (x, y, re, im, red_thread);
	else
		julia (re, im, red_thread);
}

void pixels(t_fractol *red_thread)
{
	int x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			//my_mlx_pixel_put(&red_thread->image, x, y, 0xFFFFFF);
			//printf("%d %d\n", x, y);
			rescale_pixels(x, y, red_thread);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window( red_thread->mlx_connection,  red_thread->mlx_window,  red_thread->image.img,  0,  0);

}
