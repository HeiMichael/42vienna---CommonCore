/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_spots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:40:29 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 18:37:13 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_left(t_map_inf *inf)
{
	if (inf->x == 0
		|| inf->map[inf->y][inf->x - 1] == ' '
		|| (inf->map[inf->y][inf->x - 1] != '0'
		&& inf->map[inf->y][inf->x - 1] != '1'
		&& inf->map[inf->y][inf->x - 1] != 'N'
		&& inf->map[inf->y][inf->x - 1] != 'S'
		&& inf->map[inf->y][inf->x - 1] != 'W'
		&& inf->map[inf->y][inf->x - 1] != 'E'))
	{
		free_map_array(inf->extra_map, inf->line_count);
		free_exit(inf->cubed, "Error\nFloor not enclosed\n");
	}
}

void	check_right(t_map_inf *inf)
{
	if (inf->map[inf->y][inf->x + 1] == '\0'
		|| inf->map[inf->y][inf->x + 1] == ' '
		|| (inf->map[inf->y][inf->x + 1] != '0'
		&& inf->map[inf->y][inf->x + 1] != '1'
		&& inf->map[inf->y][inf->x + 1] != 'N'
		&& inf->map[inf->y][inf->x + 1] != 'S'
		&& inf->map[inf->y][inf->x + 1] != 'W'
		&& inf->map[inf->y][inf->x + 1] != 'E'))
	{
		free_map_array(inf->extra_map, inf->line_count);
		free_exit(inf->cubed, "Error\nFloor not enclosed\n");
	}
}

void	check_top(t_map_inf *inf)
{
	if (inf->y == 0 || inf->map[inf->y - 1][inf->x] == ' '
		|| (inf->map[inf->y - 1][inf->x] != '0'
		&& inf->map[inf->y - 1][inf->x] != '1'
		&& inf->map[inf->y - 1][inf->x] != 'N'
		&& inf->map[inf->y - 1][inf->x] != 'S'
		&& inf->map[inf->y - 1][inf->x] != 'W'
		&& inf->map[inf->y - 1][inf->x] != 'E'))
	{
		free_map_array(inf->extra_map, inf->line_count);
		free_exit(inf->cubed, "Error\nFloor not enclosed\n");
	}
}

void	check_bottom(t_map_inf *inf)
{
	if (inf->y == inf->line_count - 1
		|| inf->x >= (int)ft_strlen(inf->map[inf->y + 1])
		|| inf->map[inf->y + 1][inf->x] == ' '
		|| (inf->map[inf->y + 1][inf->x] != '0'
		&& inf->map[inf->y + 1][inf->x] != '1'
		&& inf->map[inf->y + 1][inf->x] != 'N'
		&& inf->map[inf->y + 1][inf->x] != 'S'
		&& inf->map[inf->y + 1][inf->x] != 'W'
		&& inf->map[inf->y + 1][inf->x] != 'E'))
	{
		free_map_array(inf->extra_map, inf->cubed->grid_y);
		free_exit(inf->cubed, "Error\nFloor not enclosed\n");
	}
}
