/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:08:55 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:45 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_extension(t_cub *cubed, char *map_file)
{
	const char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (extension == NULL || ft_strcmp(extension, ".cub") != 0)
		free_exit(cubed, "Error\nInvalid file extension\n");
}

void	check_valid_map(t_cub *cubed, char *map_file)
{
	char	**map;
	int		line_count;

	map = save_map_to_array(cubed, map_file, &line_count);
	find_invalid_chars(cubed, line_count, map);
	find_open_spots(cubed, cubed->map, line_count, map);
	free_map_array(map, line_count);
	player_can_move(cubed);
}
