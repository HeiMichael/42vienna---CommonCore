/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:19:18 by miheider          #+#    #+#             */
/*   Updated: 2024/01/03 16:29:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	error_message(int errnumb)
{
	if (errnumb == 1)
		ft_putstr_fd("Error: No input. Please enter \"mandelbrot\" or "
			"\"julia\" \"value1\" \"value2\"!", 1);
	if (errnumb == 2)
		ft_putstr_fd("Error: Invalid input. Please enter \"mandelbrot\""
			" or \"julia\" \"value1\" \"value2\"!", 1);
	if (errnumb == 3)
		ft_putstr_fd("Error: Invalid input. Wrong number of inputs!", 1);
	if (errnumb == 4)
		ft_putstr_fd("Error: Invalid input. Input is not a number!", 1);
	exit (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
