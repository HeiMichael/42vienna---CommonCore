/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:00:15 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:57 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_texture_paths(t_cub *cubed, int fd)
{
	if (!valid_texture_paths(cubed))
	{
		close(fd);
		free_exit(cubed, "Error\nInvalid texture path\n");
	}
}

void	read_map_file(t_cub *cubed, char *map_file, int start_saving_map)
{
	char			*line;
	int				fd;
	unsigned char	booly;
	t_map_data		map_data;

	map_data.start_saving_map = start_saving_map;
	map_data.floor_color_count = 0;
	map_data.ceiling_color_count = 0;
	map_data.map_index = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		free_exit(cubed, "Error\nFailed to open map file\n");
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line == NULL)
			break ;
		process_line(cubed, line, &map_data, fd);
		free(line);
	}
	check_texture_paths(cubed, fd);
	close(fd);
	if (map_data.floor_color_count != 1 || map_data.ceiling_color_count != 1)
		free_exit(cubed, "Error\nMissing floor or ceiling color.\n");
}

void	read_map_file_main(t_cub *cubed, char *map_file)
{
	int	map_lines;
	int	start_saving_map;

	map_lines = -1;
	start_saving_map = 0;
	cubed->player = allocate_memory(sizeof(t_player), 1, *cubed);
	count_map_lines(cubed, &map_lines, map_file);
	init_map(cubed, map_lines);
	read_map_file(cubed, map_file, start_saving_map);
}

void	handle_input_main(t_cub *cubed, char *map_file)
{
	check_file_extension(cubed, map_file);
	read_map_file_main(cubed, map_file);
	find_invalid_lines(cubed, map_file);
	find_player(cubed);
	find_max_map_values(cubed, map_file);
	check_valid_map(cubed, map_file);
}
