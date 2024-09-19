/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:37:21 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:27 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map_inf	init_map_inf(t_cub *cubed, char **map, int lines, char **extra_map)
{
	t_map_inf	inf;

	inf.cubed = cubed;
	inf.map = map;
	inf.line_count = lines;
	inf.extra_map = extra_map;
	return (inf);
}

void	check_spots_main(t_map_inf *inf, int y, int x)
{
	inf->y = y;
	inf->x = x;
	check_left(inf);
	check_right(inf);
	check_top(inf);
	check_bottom(inf);
}

void	find_open_spots(t_cub *cubed, char **map, int lines, char **extra_map)
{
	int			y;
	int			x;
	t_map_inf	inf;

	if (cubed == NULL || map == NULL)
		free_exit(cubed, "Error: cubed or map is NULL");
	y = 0;
	inf = init_map_inf(cubed, map, lines, extra_map);
	while (y < lines)
	{
		if (map[y] == NULL)
			free_exit(cubed, "Error: map row is NULL");
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				check_spots_main(&inf, y, x);
			}
			x++;
		}
		y++;
	}
}
