/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:28:50 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 12:26:03 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel_to_image(t_cub *cubed, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
	{
		dst = cubed->img.addr + (y * cubed->img.line_length + x
				* (cubed->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	loading_textures(t_cub *cubed)
{
	int	bpp;
	int	size_line;
	int	endian;

	cubed->textures[0].img = mlx_xpm_file_to_image(cubed->mlx_connection,
			cubed->map_data->no_texture, &cubed->textures[0].width,
			&cubed->textures[0].height);
	cubed->textures[0].pixel = (int *)mlx_get_data_addr(cubed->textures[0].img,
			&bpp, &size_line, &endian);
	cubed->textures[2].img = mlx_xpm_file_to_image(cubed->mlx_connection,
			cubed->map_data->so_texture, &cubed->textures[2].width,
			&cubed->textures[2].height);
	cubed->textures[2].pixel = (int *)mlx_get_data_addr(cubed->textures[2].img,
			&bpp, &size_line, &endian);
	cubed->textures[3].img = mlx_xpm_file_to_image(cubed->mlx_connection,
			cubed->map_data->we_texture, &cubed->textures[3].width,
			&cubed->textures[3].height);
	cubed->textures[3].pixel = (int *)mlx_get_data_addr(cubed->textures[3].img,
			&bpp, &size_line, &endian);
	cubed->textures[1].img = mlx_xpm_file_to_image(cubed->mlx_connection,
			cubed->map_data->ea_texture, &cubed->textures[1].width,
			&cubed->textures[1].height);
	cubed->textures[1].pixel = (int *)mlx_get_data_addr(cubed->textures[1].img,
			&bpp, &size_line, &endian);
}

void	init_map(t_cub *cubed, int map_height)
{
	int	i;

	i = 0;
	cubed->map = allocate_memory(sizeof(char *), map_height + 1, *cubed);
	if (!cubed->map)
		free_exit(cubed, "Error\nFailed to allocate memory for map\n");
	cubed->grid_y = map_height;
	while (i <= map_height)
	{
		cubed->map[i] = NULL;
		i++;
	}
}

void	init_mlx(t_cub *cubed)
{
	cubed->mlx_connection = mlx_init();
	if (!cubed->mlx_connection)
	{
		free_exit(cubed, "Error: \nUnable to initialize MLX connection.\n");
	}
	cubed->mlx_window = mlx_new_window(cubed->mlx_connection,
			SCREEN_W, SCREEN_H, cubed->name);
	if (!cubed->mlx_window)
	{
		free_exit(cubed, "Error: \nUnable to create MLX window.\n");
	}
	cubed->img.img = mlx_new_image(cubed->mlx_connection, SCREEN_W, SCREEN_H);
	if (!cubed->img.img)
	{
		free_exit(cubed, "Error: \nUnable to create image\n");
	}
	cubed->img.addr = mlx_get_data_addr(cubed->img.img,
			&cubed->img.bits_per_pixel, &cubed->img.line_length,
			&cubed->img.endian);
	if (!cubed->img.addr)
	{
		free_exit(cubed, "Error: \nUnable to create image\n");
	}
	loading_textures(cubed);
}

void	init_cubed(t_cub *cubed)
{
	ft_memset(cubed, 0, sizeof(t_cub));
	cubed->ray = NULL;
	cubed->map_data = NULL;
	cubed->player = NULL;
	cubed->textures = NULL;
	cubed->pot = ft_calloc(FD, sizeof(char *));
	if (!cubed->pot)
		free_exit(cubed, "Error\nFailed to allocate memory for map\n");
	cubed->ray = allocate_memory(sizeof(t_ray), 1, *cubed);
	cubed->map_data = allocate_memory(sizeof(t_map), 1, *cubed);
	cubed->textures = allocate_memory(sizeof(t_texture), 4, *cubed);
}
