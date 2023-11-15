/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:01:57 by miheider          #+#    #+#             */
/*   Updated: 2023/11/15 11:38:59 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *red_thread)
{
	red_thread->mlx->connection = mlx_init()								//est. connection
	if (NULL == red_thread->mlx-connection)
		return (1);								//TODO Error
	red_thread->mlx_window = mlx_new_window(red_thread->mlx_connection, WIDTH, 
		HIGHT, red_thread->name);
	if (NULL == red_thread->mlx_window)										//create window
	{
		mlx_destroy_display(red_thread->mlx_connection);
		free(red_thred->connection);
		return (1);								//TODO Error
	}				
	red_thread->image.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT)	//create image
	{
		mlx_destroy_window(red_thred->mlx_connection, red_thread->mlx_window);
		mlx_destroy_display(red_thread->mlx_connection);
		free(red_thread->mlx_connection);
		return (1);								//TODO Error
	}
	red_thread->image.addr = mlx_get_data_addr(red_thread->image.img, 
		&red_thread->image.bits_per_pixel, &red_thread->image.line_length, 
		&red_thread->image.endian); 										//returns information to modify it later, returns char address that repr the beginning of the memory areaa where the image is stored				
}
