/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:36:36 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:32 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	count_map_lines(t_cub *cubed, int *map_lines, char *map_file)
{
	char			*line;
	int				fd;
	unsigned char	booly;

	*map_lines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		free_exit(cubed, "Error\nFailed to open map file\n");
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line == NULL)
			break ;
		if (line[0] != '\0' && (ft_strchr("01", line[0])
				|| ft_strchr(" \t", line[0])))
		{
			(*map_lines)++;
		}
		free(line);
	}
	close(fd);
}

void	color_count_error(t_cub *cubed, char *line, int fd)
{
	free(line);
	close(fd);
	free_exit(cubed, "Error\nMore than one F or C color.\n");
}

void	process_line(t_cub *cubed, char *line, t_map_data *map_data, int fd)
{
	if (!(map_data->start_saving_map))
	{
		if (is_color_line(cubed, line, fd))
		{
			save_colors(cubed, line, fd);
			if (ft_strncmp(line, "F ", 2) == 0)
				map_data->floor_color_count++;
			else if (ft_strncmp(line, "C ", 2) == 0)
				map_data->ceiling_color_count++;
			if (map_data->floor_color_count > 1
				|| map_data->ceiling_color_count > 1)
				color_count_error(cubed, line, fd);
		}
		save_texture_paths(cubed, line, fd);
		if (line[0] != '\0' && (ft_strchr("01", line[0])
				|| ft_strchr(" \t", line[0])))
			map_data->start_saving_map = 1;
	}
	if (map_data->start_saving_map)
		save_map(cubed, line, &(map_data->map_index), fd);
}
