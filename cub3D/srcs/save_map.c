/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:51:23 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:44 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_error(t_cub *cubed, char *line, int fd)
{
	if (line)
		free(line);
	close(fd);
	free_exit(cubed, "Error\nInvalid map\n");
}

void	map_newline_error(t_cub *cubed, char *line, int fd)
{
	unsigned char	booly;

	free(line);
	while (1)
	{
		line = get_next_line(fd, &booly, cubed->pot);
		if (line != NULL)
		{
			free(line);
		}
		else
			break ;
	}
	map_error(cubed, line, fd);
}

void	save_map(t_cub *cubed, char *line, int *map_index, int fd)
{
	char			*newline;

	if (line && line[0] == '\n')
		map_newline_error(cubed, line, fd);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
		*newline = '\0';
	if (*map_index >= cubed->grid_y)
		map_error(cubed, line, fd);
	cubed->map[*map_index] = ft_strdup(line);
	if (!cubed->map[*map_index])
		map_error(cubed, line, fd);
	cubed->grid_x = ft_strlen(line);
	(*map_index)++;
}
