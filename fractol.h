/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:23:48 by miheider          #+#    #+#             */
/*   Updated: 2023/11/18 19:38:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
 #define FRACTOL_H


#include <errno.h>
#include <stdlib.h>					//malloc, free
#include <unistd.h> 				//write
#include <mlx.h>					//MiniLibX
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define WIDTH		880
#define HEIGHT		880
#define ITER_MAX	70


typedef struct	s_data
{
	void	*img;					//pointer to image struct
	char	*addr;					//points to actual pixel
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_fractol			//est. pointer
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
	t_data	image;
}	t_fractol;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init(t_fractol *red_thread);
int		close_all(t_fractol *red_thread);
int		escape(int keysym, t_fractol *red_thread);
int		zoom(int key, int x, int y, t_fractol *red_thread);
void	events(t_fractol *red_thread);
int		main(int argc, char *argv[]);
void	mandelbrot(int x, int y, double re, double im, t_fractol *red_thread);
void	rescale_pixels(int x, int y, t_fractol *red_thread);
void 	pixels(t_fractol *red_thread);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	julia(double x, double y, t_fractol *red_thread);

#endif
