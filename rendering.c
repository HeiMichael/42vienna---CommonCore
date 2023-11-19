/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:29 by miheider          #+#    #+#             */
/*   Updated: 2023/11/19 15:59:25 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "stdio.h"

void	rescale_pixels(int x, int y, t_fractol *red_thread)
{
	double	re;
	double	im;

	re = (((0.5 - (-2)) * x) / ((double)WIDTH)) + (-2);
	im = (((((-1.5) - 1.5) * y) / ((double)HEIGHT)) + 1.5);
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
			rescale_pixels(x, y, red_thread);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window( red_thread->mlx_connection,  red_thread->mlx_window,  red_thread->image.img,  0,  0);

}
