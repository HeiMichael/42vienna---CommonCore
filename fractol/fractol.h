/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:23:48 by miheider          #+#    #+#             */
/*   Updated: 2023/12/07 13:10:37 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <errno.h>
# include <stdlib.h>					//malloc, free
# include <unistd.h> 				//write
# include <mlx.h>					//MiniLibX
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH		700
# define HEIGHT		700
# define COLOR1		0x0
# define COLOR2		0xFFFFFF
# define ESCAPE		160
# define PI 		3.141592

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	zoom;
	int		iter;
	double	c_real;
	double	c_im;
	double	z_real;
	double	z_im;
	double	temp;
	double	julia_real;
	double	julia_im;
	double	hor;
	double	ver;
	int		iter_max;
	int		color;
	int		r_min;
	int		r_max;
	int		r_sh;
	int		g_min;
	int		g_max;
	int		g_sh;
	int		b_min;
	int		b_max;
	int		b_sh;
	int		rj_min;
	int		rj_max;
	double	rj_sh;
	int		gj_min;
	int		gj_max;
	double	gj_sh;
	int		bj_min;
	int		bj_max;
	double	bj_sh;
	int		x;
	int		y;
	t_data	image;
}	t_fractol;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init(t_fractol *red_thread);
void	init_struct(t_fractol *red_thread);
int		close_all(t_fractol *red_thread);
int		keys(int keysym, t_fractol *red_thread);
int		color_preset1(int keysym, t_fractol *red_thread);
int		color_preset2(int keysym, t_fractol *red_thread);
int		color_preset3(int keysym, t_fractol *red_thread);
int		color_preset4(int keysym, t_fractol *red_thread);
int		change_color1(int keysym, t_fractol *red_thread);
int		change_color2(int keysym, t_fractol *red_thread);
int		arrow(int keysym, t_fractol *red_thread);
int		zoom(int key, int x, int y, t_fractol *red_thread);
void	error_message(int errnumb);
int		get_number1(const char *nptr, int *i, t_fractol *red_thread);
double	get_number2(const char *nptr, int *i, t_fractol *red_thread);
void	events(t_fractol *red_thread);
int		main(int argc, char *argv[]);
int		resolution(int keysym, t_fractol *red_thread);
void	mandelbrot_color(double iterations, t_fractol *red_thread);
int		julia_color(double smooth_iter, t_fractol *red_thread);
void	mandelbrot(double re, double im, t_fractol *red_thread);
void	rescale_pixels(t_fractol *red_thread);
void	pixels(t_fractol *red_thread);
void	init_struct(t_fractol *red_thread);
void	julia(double re, double im, t_fractol *red_thread);
double	ft_strdou(const char *nptr, t_fractol *red_thread);
double	check_for_color(t_fractol *red_thread);
void	calc_julia(t_fractol *red_thread);

#endif
