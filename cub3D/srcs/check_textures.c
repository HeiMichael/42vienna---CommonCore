/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:09:19 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:35 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	correct_prefixes(char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (true);
	if (line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (true);
	if (line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (true);
	if (line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2] == ' '
			|| line[i + 2] == '\t'))
		return (true);
	if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (true);
	if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (true);
	return (false);
}

void	parse_texture_path(char **texture_path, char *line)
{
	char	*path_start;
	char	*path_end;
	char	*newline;

	path_start = ft_strchr(line, ' ') + 1;
	while (*path_start == ' ' || *path_start == '\t')
		path_start++;
	newline = ft_strchr(path_start, '\n');
	if (newline != NULL)
		*newline = '\0';
	path_end = path_start + ft_strlen(path_start) - 1;
	while (path_end > path_start && (*path_end == ' ' || *path_end == '\t'))
	{
		*path_end = '\0';
		path_end--;
	}
	*texture_path = ft_strdup(path_start);
}

bool	valid_texture_paths(t_cub *cubed)
{
	int	fd;

	if (!cubed->map_data->no_texture || !cubed->map_data->so_texture
		|| !cubed->map_data->we_texture || !cubed->map_data->ea_texture)
		return (false);
	fd = open(cubed->map_data->no_texture, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	fd = open(cubed->map_data->so_texture, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	fd = open(cubed->map_data->we_texture, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	fd = open(cubed->map_data->ea_texture, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void	texture_path_dupl_error(t_cub *cubed, char *line, int fd)
{
	free(line);
	close(fd);
	free_exit(cubed, "Error\nDuplicate texture path\n");
}

void	save_texture_paths(t_cub *cubed, char *line, int fd)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (cubed->map_data->no_texture != NULL)
			texture_path_dupl_error(cubed, line, fd);
		parse_texture_path(&cubed->map_data->no_texture, line);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (cubed->map_data->so_texture != NULL)
			texture_path_dupl_error(cubed, line, fd);
		parse_texture_path(&cubed->map_data->so_texture, line);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (cubed->map_data->we_texture != NULL)
			texture_path_dupl_error(cubed, line, fd);
		parse_texture_path(&cubed->map_data->we_texture, line);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (cubed->map_data->ea_texture != NULL)
			texture_path_dupl_error(cubed, line, fd);
		parse_texture_path(&cubed->map_data->ea_texture, line);
	}
}
