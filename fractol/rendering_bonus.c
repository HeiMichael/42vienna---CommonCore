/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:29 by miheider          #+#    #+#             */
/*   Updated: 2023/12/03 16:49:24 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	rescale_pixels(t_fractol *red_thread)
{
	double	re;
	double	im;

	if (ft_strncmp(red_thread->name, "mandelbrot", 10) == 0)
	{
		re = (((0.5 - (-2)) * red_thread->x) / ((double)WIDTH)) + (-2);
		im = (((((-1.5) - 1.5) * red_thread->y) / ((double)HEIGHT)) + 1.5);
		mandelbrot (re, im, red_thread);
	}
	else if (ft_strncmp(red_thread->name, "burning_ship", 12) == 0)
	{
		re = (((1 - (-2)) * red_thread->x) / ((double)WIDTH)) + (-2);
		im = ((((0.7 + 2) * red_thread->y) / ((double)HEIGHT)) - 2);
		burning_ship (re, im, red_thread);
	}
	else
	{
		re = (((2 - (-2)) * red_thread->x) / ((double)WIDTH)) + (-2);
		im = (((((-2) - 2) * red_thread->y) / ((double)HEIGHT)) + 2);
		julia (re, im, red_thread);
	}
}

void	pixels(t_fractol *red_thread)
{
	mlx_clear_window(red_thread->mlx_connection, red_thread->mlx_window);
	red_thread->y = 0;
	while (red_thread->y <= HEIGHT)
	{
		red_thread->x = 0;
		while (red_thread->x <= WIDTH)
		{
			rescale_pixels(red_thread);
			red_thread->x++;
		}
		red_thread->y++;
	}
	mlx_put_image_to_window (red_thread->mlx_connection,
		red_thread->mlx_window, red_thread->image.img, 0, 0);
}
