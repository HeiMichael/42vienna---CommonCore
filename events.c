/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:22:46 by miheider          #+#    #+#             */
/*   Updated: 2023/11/19 16:13:08 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_all(t_fractol *red_thread)
{
	mlx_destroy_image(red_thread->mlx_connection, red_thread->image.img);
	mlx_destroy_window(red_thread->mlx_connection, red_thread->mlx_window);
	mlx_destroy_display(red_thread->mlx_connection);
	free(red_thread->mlx_connection);
	free(red_thread->name);
	exit(1);
	return (0);													//TODO
}

int	escape(int keysym, t_fractol *red_thread)					//ESC to exit
{
	if (keysym == XK_Escape)
	{
		close_all(red_thread);
		exit (1);
	}
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *red_thread)			//zoom in/out
{
	if (x <= WIDTH && y <= HEIGHT)
	{
		if (key == Button4 && red_thread->zoom > 0.0005)
			red_thread->zoom = red_thread->zoom * 0.95;
		else if (key == Button5 && red_thread->zoom < 2147483647)
			red_thread->zoom = red_thread->zoom * 1.05;
		if (red_thread->zoom < 0.7)
			red_thread->iter = 2;
		else if (red_thread->zoom < 0.5)
			red_thread->iter = 3;
		if (red_thread->zoom < 0.2)
			red_thread->iter = 4;
		pixels(red_thread);
	}
	return (0);
}

void	events(t_fractol *red_thread)
{
	mlx_hook(red_thread->mlx_window, KeyPress, KeyPressMask, escape, &red_thread);	//ESC
	mlx_mouse_hook(red_thread->mlx_window, zoom, red_thread);						//zoom
	mlx_hook(red_thread->mlx_window, 17, 0L, close_all, red_thread);					//click on x
	mlx_loop(red_thread->mlx_connection);					//no event
}
