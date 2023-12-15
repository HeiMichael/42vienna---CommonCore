/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:22:46 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:38:52 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	follow_zoom(t_fractol **red_thread, double zoom_factor, \
		double zoom_x, double zoom_y)
{
	long double	move_factor;

	if (!ft_strncmp((*red_thread)->name, "burning_ship", 12))
	{
		(*red_thread)->hor += ((zoom_x - 0.5) * 2) \
			/ (*red_thread)->zoom * zoom_factor;
		(*red_thread)->ver += ((zoom_y - 0.5) * 2) \
			/ (*red_thread)->zoom * zoom_factor;
	}
	else if (!ft_strncmp((*red_thread)->name, "mandelbrot", 10))
	{
		move_factor = 1.0f;
		(*red_thread)->zoom *= zoom_factor;
		(*red_thread)->hor += ((zoom_x - 0.5) * move_factor / 20);
		(*red_thread)->ver -= ((zoom_y - 0.5) * move_factor / 20);
	}
	else if (!ft_strncmp((*red_thread)->name, "julia", 5))
	{
		move_factor = 0.5f;
		(*red_thread)->zoom *= zoom_factor;
		(*red_thread)->hor += ((zoom_x - 0.5) * move_factor);
		(*red_thread)->ver -= ((zoom_y - 0.5) * move_factor);
	}
}

int	zoom(int key, int x, int y, t_fractol *red_thread)
{
	double	zoom_x;
	double	zoom_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	if (x <= WIDTH && y <= HEIGHT && x >= 0 && y >= 0)
	{
		if (key == Button4 && red_thread->zoom > 0.000005)
			zoom_factor *= 0.98;
		else if (key == Button5 && red_thread->zoom < 2147483647)
			zoom_factor *= 1.02;
		zoom_x = (double)x / WIDTH;
		zoom_y = (double)y / HEIGHT;
		follow_zoom(&red_thread, zoom_factor, zoom_x, zoom_y);
	}
	red_thread->zoom *= zoom_factor;
	red_thread->x = red_thread->curx;
	red_thread->y = red_thread->cury;
	pixels(red_thread);
	return (0);
}

void	events(t_fractol *red_thread)
{
	mlx_hook(red_thread->mlx_window, KeyPress, KeyPressMask, keys, red_thread);
	mlx_mouse_hook(red_thread->mlx_window, zoom, red_thread);
	mlx_hook(red_thread->mlx_window, 17, 0L, close_all, red_thread);
	mlx_loop(red_thread->mlx_connection);
}
/*
int	zoom(int key, int x, int y, t_fractol *red_thread)
{
	double	zoom_factor;
	
	zoom_factor = 1.0;
	if (x <= WIDTH && y <= HEIGHT && x >= 0 && y >= 0)
	{
		if (key == Button4 && red_thread->zoom > 0.0005)
			zoom_factor *= 0.98;
		else if (key == Button5 && red_thread->zoom < 2147483647)
			zoom_factor *= 1.02;
		pixels(red_thread);
	}
	if (key == Button4)
	{
		red_thread->hor += -((y - HEIGHT / 2.0f) / HEIGHT * zoom_factor);
		red_thread->ver += -((x - WIDTH / 2.0f) / WIDTH * zoom_factor);
	}
	if (key == Button5)
	{
		red_thread->hor -= -((y - HEIGHT / 2.0f) / HEIGHT * zoom_factor);
		red_thread->ver -= -((x - WIDTH / 2.0f) / WIDTH * zoom_factor);	
	}
	red_thread->zoom *= zoom_factor;
	red_thread->x = red_thread->curx;
	red_thread->y = red_thread->cury;
	pixels(red_thread);
	return (0);
}




int zoom(int key, int x, int y, t_fractol *red_thread) 
{
	double zoom_factor;
    
    red_thread->curx = (double)x / WIDTH;
    red_thread->cury = (double)y / HEIGHT;
	zoom_factor = 1.0;
    if (x <= WIDTH && y <= HEIGHT) {
        if (key == Button4 && red_thread->zoom > 0.0005)
            zoom_factor = 0.95;
        else if (key == Button5 && red_thread->zoom < 2147483647)
            zoom_factor = 1.05;
    }
    double target_zoom = red_thread->zoom * zoom_factor;
    double cursor_dx = (cursor_x - 0.5);
    double cursor_dy = (cursor_y - 0.5);

    red_thread->hor += cursor_dx * (target_zoom - red_thread->zoom);
    red_thread->ver += cursor_dy * (target_zoom - red_thread->zoom);
    red_thread->zoom = target_zoom;

    pixels(red_thread); // Render the fractal after the zoom

    return 0;
}*/
