/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:38:05 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/01 21:03:41 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_mlx_textures(t_cub *cubed)
{
	int	i;

	i = 0;
	if (cubed->textures)
	{
		while (i < 4)
		{
			if (cubed->textures[i].img)
			{
				mlx_destroy_image(cubed->mlx_connection,
					cubed->textures[i].img);
				cubed->textures[i].img = NULL;
			}
			i++;
		}
		free(cubed->textures);
		cubed->textures = NULL;
	}
}

void	free_mlx(t_cub *cubed)
{
	if (cubed->mlx_connection)
	{
		if (cubed->img.img)
		{
			mlx_destroy_image(cubed->mlx_connection, cubed->img.img);
			cubed->img.img = NULL;
		}
		free_mlx_textures(cubed);
		if (cubed->mlx_window)
		{
			mlx_destroy_window(cubed->mlx_connection, cubed->mlx_window);
			cubed->mlx_window = NULL;
		}
		mlx_destroy_display(cubed->mlx_connection);
		free(cubed->mlx_connection);
		cubed->mlx_connection = NULL;
	}
}

void	free_map(t_cub *cubed)
{
	int	i;

	i = 0;
	if (cubed->map)
	{
		while (cubed->map[i])
		{
			free(cubed->map[i]);
			i++;
		}
		free(cubed->map);
		cubed->map = NULL;
	}
}

void	free_player(t_cub *cubed)
{
	if (cubed->player)
	{
		free(cubed->player);
		cubed->player = NULL;
	}
}

void	free_map_data(t_cub *cubed)
{
	if (cubed->map_data)
	{
		if (cubed->map_data->no_texture)
		{
			free(cubed->map_data->no_texture);
			cubed->map_data->no_texture = NULL;
		}
		if (cubed->map_data->so_texture)
		{
			free(cubed->map_data->so_texture);
			cubed->map_data->so_texture = NULL;
		}
		if (cubed->map_data->we_texture)
		{
			free(cubed->map_data->we_texture);
			cubed->map_data->we_texture = NULL;
		}
		if (cubed->map_data->ea_texture)
		{
			free(cubed->map_data->ea_texture);
			cubed->map_data->ea_texture = NULL;
		}
		free(cubed->map_data);
		cubed->map_data = NULL;
	}
}
