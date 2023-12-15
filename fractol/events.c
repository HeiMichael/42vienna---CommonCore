/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:22:46 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:38:57 by miheider         ###   ########.fr       */
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
	exit(0);
}

int	keys(int keysym, t_fractol *red_thread)
{
	if (keysym == XK_Escape)
		close_all(red_thread);
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left
		|| keysym == XK_Right)
		arrow(keysym, red_thread);
	if (keysym == XK_a || keysym == XK_s)
		color_preset1(keysym, red_thread);
	if (keysym == XK_d || keysym == XK_f)
		color_preset2(keysym, red_thread);
	if (keysym == XK_g || keysym == XK_h)
		color_preset3(keysym, red_thread);
	if (keysym == XK_j || keysym == XK_k)
		color_preset4(keysym, red_thread);
	if (keysym == XK_q || keysym == XK_w || keysym == XK_e || keysym == XK_r
		|| keysym == XK_t || keysym == XK_z || keysym == XK_u || keysym == XK_i
		|| keysym == XK_o)
		change_color1(keysym, red_thread);
	if (keysym == XK_y || keysym == XK_x || keysym == XK_c || keysym == XK_v
		|| keysym == XK_b || keysym == XK_n || keysym == XK_m
		|| keysym == XK_comma || keysym == XK_period)
		change_color2(keysym, red_thread);
	if (keysym == XK_l || keysym == XK_p)
		resolution(keysym, red_thread);
	pixels(red_thread);
	return (0);
}

int	zoom(int key, int x, int y, t_fractol *red_thread)
{
	if (x <= WIDTH && y <= HEIGHT)
	{
		if (key == Button4 && red_thread->zoom > 0.0005)
			red_thread->zoom = red_thread->zoom * 0.95;
		else if (key == Button5 && red_thread->zoom < 2147483647)
			red_thread->zoom = red_thread->zoom * 1.05;
		pixels(red_thread);
	}
	return (0);
}

void	events(t_fractol *red_thread)
{
	mlx_hook(red_thread->mlx_window, KeyPress, KeyPressMask, keys, red_thread);
	mlx_mouse_hook(red_thread->mlx_window, zoom, red_thread);
	mlx_hook(red_thread->mlx_window, 17, 0L, close_all, red_thread);
	mlx_loop(red_thread->mlx_connection);
}
