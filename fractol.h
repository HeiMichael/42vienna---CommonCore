/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:23:48 by miheider          #+#    #+#             */
/*   Updated: 2023/11/10 17:20:21 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
 #define FLACTOL_H


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
	t_data	image;
}	t_fractol;





#endif
