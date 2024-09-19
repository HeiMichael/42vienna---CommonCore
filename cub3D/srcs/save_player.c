/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:06:18 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:02 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	save_player_direction(t_cub *cubed, char direction)
{
	if (direction == 'N')
		cubed->player->angle = PI_3;
	else if (direction == 'S')
		cubed->player->angle = PI_2;
	else if (direction == 'W')
		cubed->player->angle = PI;
	else if (direction == 'E')
		cubed->player->angle = 0;
}

int	search_row_for_player(t_cub *cubed, char *row, int i, int *player_count)
{
	unsigned int	j;

	j = 0;
	while (j < ft_strlen(row))
	{
		if (ft_strchr("NSWE", row[j]))
		{
			if (*player_count == 0)
			{
				cubed->player->player_x = j;
				cubed->player->player_y = i;
				save_player_direction(cubed, row[j]);
				(*player_count)++;
			}
			else
				free_exit(cubed, "Error\nMore than one player\n");
		}
		j++;
	}
	return (*player_count);
}

void	find_player(t_cub *cubed)
{
	int	player_count;
	int	i;

	player_count = 0;
	i = 0;
	while (i < cubed->grid_y)
	{
		player_count = search_row_for_player(cubed, cubed->map[i],
				i, &player_count);
		i++;
	}
	if (player_count == 0)
		free_exit(cubed, "Error\nNo player found in the map\n");
}

void	player_can_move(t_cub *cubed)
{
	int		player_x;
	int		player_y;
	char	**map;

	player_y = cubed->player->player_y;
	player_x = cubed->player->player_x;
	map = cubed->map;
	if ((player_y - 1 >= 0 && map[player_y - 1][player_x] == '1')
		&& (player_y + 1 < cubed->grid_y && map[player_y + 1][player_x] == '1')
		&& (player_x - 1 >= 0 && map[player_y][player_x - 1] == '1')
		&& (player_x + 1 < cubed->grid_x
		&& map[player_y][player_x + 1] == '1'))
	{
		free_exit(cubed, "Error\nPlayer can't move\n");
	}
}
