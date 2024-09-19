/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:59:57 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 16:45:36 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(t_cub *cubed, const char *map_file)
{
	unsigned char	booly;
	int				fd;
	char			*line;
	int				line_count;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		free_exit(cubed, "Error\nFailed to open map file\n");
	line_count = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line == NULL)
			break ;
		line_count++;
		free(line);
	}
	close(fd);
	return (line_count);
}

void	handle_lines(int *start_saving, char *line, char **array, int *index)
{
	if (!*start_saving)
	{
		if (line[0] == '1' || line[0] == ' ')
			*start_saving = 1;
		else
		{
			free(line);
			return ;
		}
	}
	if (*start_saving)
		array[(*index)++] = line;
	else
		free(line);
}

void	process_file_lines(t_cub *cubed, int fd, char **map_array, int *index)
{
	unsigned char	booly;
	char			*line;
	int				start_saving_map;

	start_saving_map = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line == NULL)
			break ;
		handle_lines(&start_saving_map, line, map_array, index);
	}
}

char	**save_map_to_array(t_cub *cubed, const char *map_file, int *line_count)
{
	char	**map_array;
	int		fd;
	int		index;

	*line_count = count_lines(cubed, map_file);
	map_array = allocate_memory(sizeof(char *), *line_count, *cubed);
	if (!map_array)
		free_exit(cubed, "Error\nFailed to allocate memory for map\n");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		free_map_array(map_array, *line_count);
		free_exit(cubed, "Error\nFailed to open map file\n");
	}
	index = 0;
	process_file_lines(cubed, fd, map_array, &index);
	close(fd);
	*line_count = index;
	return (map_array);
}

void	free_map_array(char **map, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
