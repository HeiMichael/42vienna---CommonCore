/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:01:27 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 11:50:47 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*This fuction adds the calculated distance as long as it hits a wall.*/
void	horizontal_intersection(t_cub *cubed, int *depth_of_field)
{
	while (*depth_of_field < cubed->ray->max_grid_x)
	{
		cubed->ray->map_x = floor(cubed->ray->hor_x / TILE_SIZE);
		cubed->ray->map_y = floor(cubed->ray->hor_y / TILE_SIZE);
		if (cubed->ray->map_x < 0 || cubed->ray->map_y < 0
			|| cubed->ray->map_y >= cubed->ray->max_grid_y
			|| cubed->ray->map_x
			>= get_row_length(cubed->map, cubed->ray->map_y))
		{
			break ;
		}
		if (cubed->map[cubed->ray->map_y][cubed->ray->map_x] == '1')
		{
			*depth_of_field = cubed->ray->max_grid_x;
			break ;
		}
		else
		{
			cubed->ray->hor_x += cubed->ray->off_x;
			cubed->ray->hor_y += cubed->ray->off_y;
			(*depth_of_field)++;
		}
	}
}

void	vertical_intersection(t_cub *cubed, int *depth_of_field)
{
	while (*depth_of_field < cubed->ray->max_grid_y)
	{
		cubed->ray->map_x = floor(cubed->ray->ver_x / TILE_SIZE);
		cubed->ray->map_y = floor(cubed->ray->ver_y / TILE_SIZE);
		if (cubed->ray->map_x < 0 || cubed->ray->map_y < 0
			|| cubed->ray->map_y >= cubed->ray->max_grid_y
			|| cubed->ray->map_x
			>= get_row_length(cubed->map, cubed->ray->map_y))
		{
			break ;
		}
		if (cubed->map[cubed->ray->map_y][cubed->ray->map_x] == '1')
		{
			*depth_of_field = cubed->ray->max_grid_y;
			break ;
		}
		else
		{
			cubed->ray->ver_x += cubed->ray->off_x;
			cubed->ray->ver_y += cubed->ray->off_y;
			(*depth_of_field)++;
		}
	}
}

/*This function calculates the y + x distance to the next vertical 
intersection. The behaviour is different if the ray looks left (>2PI - <3PI/2),
right (<PI/2 - >3PI/2) or up/down (no intersection)*/
void	vertical_check(t_cub *cubed, double ray_angle, int *depth_of_field)
{
	if (ray_angle > PI_2 && ray_angle < PI_3)
	{
		cubed->ray->ver_x = (((int)(cubed->ray->cam_x / TILE_SIZE)
					* TILE_SIZE) - 0.0001);
		cubed->ray->ver_y = (cubed->ray->cam_x - cubed->ray->ver_x)
			* (-tan(ray_angle)) + cubed->ray->cam_y;
		cubed->ray->off_x = -TILE_SIZE;
		cubed->ray->off_y = -cubed->ray->off_x * (-tan(ray_angle));
	}
	else if (ray_angle < PI_2 || ray_angle > PI_3)
	{
		cubed->ray->ver_x = (((int)(cubed->ray->cam_x / TILE_SIZE)
					* TILE_SIZE) + TILE_SIZE);
		cubed->ray->ver_y = (cubed->ray->cam_x - cubed->ray->ver_x)
			* (-tan(ray_angle)) + cubed->ray->cam_y;
		cubed->ray->off_x = TILE_SIZE;
		cubed->ray->off_y = -cubed->ray->off_x * (-tan(ray_angle));
	}
	else
	{
		cubed->ray->ver_x = cubed->ray->cam_x;
		cubed->ray->ver_y = cubed->ray->cam_y;
		*depth_of_field = cubed->ray->max_grid_y;
	}
	vertical_intersection(cubed, depth_of_field);
}

/*This function calculates the y + x distance to the next horizontal 
intersection. The behaviour is differnet if the ray looks up (0 - PI),
looks down (PI - 2PI) or to the left/right (no intersection)*/
void	horizontal_check(t_cub *cubed, double ray_angle, int *depth_of_field)
{
	if (ray_angle > PI)
	{
		cubed->ray->hor_y = (((int)(cubed->ray->cam_y / TILE_SIZE)
					* TILE_SIZE) - 0.0001);
		cubed->ray->hor_x = (cubed->ray->cam_y - cubed->ray->hor_y)
			* (-1 / tan(ray_angle)) + cubed->ray->cam_x;
		cubed->ray->off_y = -TILE_SIZE;
		cubed->ray->off_x = -cubed->ray->off_y * (-1 / tan(ray_angle));
	}
	else if (ray_angle < PI)
	{
		cubed->ray->hor_y = (((int)(cubed->ray->cam_y / TILE_SIZE)
					* TILE_SIZE) + TILE_SIZE);
		cubed->ray->hor_x = (cubed->ray->cam_y - cubed->ray->hor_y)
			* (-1 / tan(ray_angle)) + cubed->ray->cam_x;
		cubed->ray->off_y = TILE_SIZE;
		cubed->ray->off_x = -cubed->ray->off_y * (-1 / tan(ray_angle));
	}
	else
	{
		cubed->ray->hor_x = cubed->ray->cam_x;
		cubed->ray->hor_y = cubed->ray->cam_y;
		*depth_of_field = cubed->ray->max_grid_x;
	}
	horizontal_intersection(cubed, depth_of_field);
}

/*main function for calculating the ray casting.*/
int	raycast(t_cub *cubed)
{
	int		ray_index;
	int		depth_of_field;
	double	ray_angle;

	ray_angle = cubed->player->angle - (30 * ONE_DEGREE);
	ray_angle = check_angle(ray_angle);
	ray_index = 0;
	while (ray_index < SCREEN_W)
	{
		cubed->ray->cam_x = TILE_SIZE * cubed->player->player_x;
		cubed->ray->cam_y = TILE_SIZE * cubed->player->player_y;
		depth_of_field = 0;
		horizontal_check(cubed, ray_angle, &depth_of_field);
		cubed->ray->hor_dist = calc_hor_distance(cubed);
		depth_of_field = 0;
		vertical_check(cubed, ray_angle, &depth_of_field);
		cubed->ray->ver_dist = calc_ver_distance(cubed);
		compare_distance(cubed, ray_angle);
		render_walls(cubed, ray_index);
		ray_angle += 60 * ONE_DEGREE / SCREEN_W;
		ray_angle = check_angle(ray_angle);
		ray_index++;
	}
	return (1);
}
