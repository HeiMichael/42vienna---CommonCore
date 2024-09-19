/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:01:40 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 16:45:48 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_invalid_chars(t_cub *cubed, int line_count, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < line_count)
	{
		x = 0;
		while (cubed->map[y][x] != '\0')
		{
			if (cubed->map[y][x] != '1' && cubed->map[y][x] != '0'
				&& cubed->map[y][x] != 'N' && cubed->map[y][x] != 'S'
				&& cubed->map[y][x] != 'W' && cubed->map[y][x] != 'E'
				&& cubed->map[y][x] != ' ' && cubed->map[y][x] != '\t')
			{
				free_map_array(map, line_count);
				free_exit(cubed, "Error\nInvalid character in map\n");
			}
			x++;
		}
		y++;
	}
}

void	invalid_lines_error(t_cub *cubed, char *line, int fd)
{
	free(line);
	close(fd);
	free_exit(cubed, "Error\nInvalid lines detected.\n");
}

void	validate_line(t_cub *cubed, char *line, int fd)
{
	int	i;

	i = 0;
	if (ft_strchr(line, '\t') != NULL)
		invalid_lines_error(cubed, line, fd);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '1' || line[i] == '\n'
		|| correct_prefixes(line, i))
		return ;
	invalid_lines_error(cubed, line, fd);
}

void	find_invalid_lines(t_cub *cubed, char *map_file)
{
	char			*line;
	int				fd;
	unsigned char	booly;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		free_exit(cubed, "Error\nFailed to open map file\n");
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line == NULL)
			break ;
		validate_line(cubed, line, fd);
		free(line);
	}
	close(fd);
}
