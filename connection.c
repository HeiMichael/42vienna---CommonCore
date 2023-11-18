/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:01:57 by miheider          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *red_thread)
{
	red_thread->mlx_connection = mlx_init();							//est. connection
	if (NULL == red_thread->mlx_connection)
		exit(1);
	red_thread->mlx_window = mlx_new_window(red_thread->mlx_connection, WIDTH,
		HEIGHT, red_thread->name);
	if (NULL == red_thread->mlx_window)							//create window
	{
		mlx_destroy_display(red_thread->mlx_connection);
		free(red_thread->mlx_connection);
	}
	red_thread->image.img = mlx_new_image(red_thread->mlx_connection,
		WIDTH, HEIGHT);	//create image
	if (NULL == red_thread->image.img)
	{
		mlx_destroy_window(red_thread->mlx_connection, red_thread->mlx_window);
		mlx_destroy_display(red_thread->mlx_connection);
		free(red_thread->mlx_connection);
	}
	red_thread->image.addr = mlx_get_data_addr(red_thread->image.img,
		&red_thread->image.bits_per_pixel, &red_thread->image.line_length,
		&red_thread->image.endian); 										//returns information to modify it later, returns char address that repr the beginning of the memory areaa where the image is stored
}
