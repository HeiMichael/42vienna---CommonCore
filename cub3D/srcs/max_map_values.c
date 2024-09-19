/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_map_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:11:49 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:34 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_map_data(t_cub *cubed, char *file, char ***map, int *lines)
{
	*map = save_map_to_array(cubed, file, lines);
}

int	find_row_start(char *row)
{
	int	j;

	j = 0;
	while (row[j] && (row[j] == ' ' || row[j] == '\t'))
		j++;
	return (j);
}

int	calculate_row_length(char *row, int start_index)
{
	int	row_length;
	int	k;
	int	j;

	row_length = 0;
	j = start_index;
	k = j;
	while (row[j] != '\0' && row[j] != '\n')
	{
		if (row[j] != ' ' && row[j] != '\t')
			row_length = j - k + 1;
		j++;
	}
	return (row_length);
}

int	calculate_max_width(char **map, int line_count)
{
	int	max_width;
	int	row_length;
	int	i;
	int	start_index;

	max_width = 0;
	i = 0;
	while (i < line_count)
	{
		start_index = find_row_start(map[i]);
		if (map[i][start_index] == '1')
		{
			row_length = calculate_row_length(map[i], start_index);
			if (row_length > max_width)
				max_width = row_length;
		}
		i++;
	}
	return (max_width);
}

void	find_max_map_values(t_cub *cubed, char *map_file)
{
	char	**map;
	int		line_count;
	int		max_width;

	initialize_map_data(cubed, map_file, &map, &line_count);
	max_width = calculate_max_width(map, line_count);
	cubed->ray->max_grid_y = line_count;
	cubed->ray->max_grid_x = max_width;
	free_map_array(map, line_count);
}
