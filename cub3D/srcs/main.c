/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:33:25 by miheider          #+#    #+#             */
/*   Updated: 2024/09/11 17:24:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_and_events(t_cub *cubed)
{
	mlx_clear_window(cubed->mlx_connection, cubed->mlx_window);
	raycast(cubed);
	mlx_put_image_to_window(cubed->mlx_connection, cubed->mlx_window,
		cubed->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	cubed;

	ft_memset(&cubed, 0, sizeof(t_cub));
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments", 2);
		return (1);
	}
	init_cubed(&cubed);
	handle_input_main(&cubed, argv[1]);
	cubed.name = "cub3D";
	init_mlx(&cubed);
	mlx_loop_hook(cubed.mlx_connection, render_and_events, &cubed);
	mlx_key_hook(cubed.mlx_window, movement, &cubed);
	mlx_hook(cubed.mlx_window, 17, 0L, x_click, &cubed);
	mlx_loop(cubed.mlx_connection);
	return (0);
}
