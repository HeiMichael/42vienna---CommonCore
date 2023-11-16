/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:23:48 by miheider          #+#    #+#             */
/*   Updated: 2023/11/16 16:48:09 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
 #define FRACTOL_H


#include <errno.h>
#include <stdlib.h>					//malloc, free
#include <unistd.h> 				//write
#include "minilibx-linux/mlx.h"		//MiniLibX

#define WIDTH	1920
#define HEIGHT	1080


typedef struct	s_data
{
	void	*img;					//pointer to image struct
	char	*addr;					//points to actual pixel
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex			//
{
	double	real;
	double	im;
}	t_complex;

typedef struct	s_fractol			//est. pointer
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	*zoom;
	int		iter;
	double	c_real;
	double	c_im;
	double	z_real;
	double	z_im;
	double	temp;
	int		inter_max;
	t_data	image;
}	t_fractol;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init(t_fractol *red_thread);
void	close(t_fractol red_thread);
void	escape(t_fractol red_thread);
void	zoom(int button, int x, int y, void *param);
void	events(t_fractol *red_thread);
int		main(int argc, char *argv[]);
int		mandelbrot(int x, int y, t_fractol red_thread);
void	rescale_pixels(int x, int y, t_fractol *red_thread);
void 	pixels(t_fractol *red_thread);



{








#endif
