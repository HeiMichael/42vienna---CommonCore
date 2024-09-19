/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:47:53 by miheider          #+#    #+#             */
/*   Updated: 2024/08/30 20:07:55 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*this function calculates and returns the horizontal distance from the
camera to the wall.*/
double	calc_hor_distance(t_cub *cubed)
{
	double	delta_x;
	double	delta_y;

	delta_x = cubed->ray->hor_x - cubed->ray->cam_x;
	delta_y = cubed->ray->hor_y - cubed->ray->cam_y;
	return (sqrt(delta_x * delta_x + delta_y * delta_y));
}

/*this function calculates and returns the vertical distance from the
camera to the wall.*/
double	calc_ver_distance(t_cub *cubed)
{
	double	delta_x;
	double	delta_y;

	delta_x = cubed->ray->ver_x - cubed->ray->cam_x;
	delta_y = cubed->ray->ver_y - cubed->ray->cam_y;
	return (sqrt(delta_x * delta_x + delta_y * delta_y));
}

/*depending on which distance is shorter, the x and y distance are 
stored in the cubed struct and depending on the angle of the ray
the side of the wall the ray hits is stored*/
void	side_decidion(t_cub *cubed, double ray_angle, double angle_diff)
{
	if (cubed->ray->ver_dist < cubed->ray->hor_dist)
	{
		cubed->ray->distance = cubed->ray->ver_dist * cos(angle_diff);
		cubed->ray->x = cubed->ray->ver_x;
		cubed->ray->y = cubed->ray->ver_y;
		if (ray_angle > PI_2 && ray_angle < PI_3)
			cubed->ray->side = 2;
		else
			cubed->ray->side = 4;
	}
	else
	{
		cubed->ray->distance = cubed->ray->hor_dist * cos(angle_diff);
		cubed->ray->x = cubed->ray->hor_x;
		cubed->ray->y = cubed->ray->hor_y;
		if (ray_angle > 0 && ray_angle < PI)
			cubed->ray->side = 1;
		else
			cubed->ray->side = 3;
	}
}

/*this function calls the function to see from which side the rays
hit the wall and in the second part the textures coordinates are 
calculated.*/
void	compare_distance(t_cub *cubed, double ray_angle)
{
	double	angle_diff;
	double	wall_x;

	angle_diff = fabs(cubed->player->angle - ray_angle);
	if (angle_diff > PI)
		angle_diff = 2 * PI - angle_diff;
	side_decidion(cubed, ray_angle, angle_diff);
	if (cubed->ray->side == 1 || cubed->ray->side == 3)
		wall_x = cubed->ray->x - floor(cubed->ray->x);
	else
		wall_x = cubed->ray->y - floor(cubed->ray->y);
	cubed->ray->tex_x = (int)(wall_x
			* cubed->textures[cubed->ray->side - 1].width);
	if ((cubed->ray->side == 1 && cubed->ray->x > cubed->player->player_x)
		|| (cubed->ray->side == 3 && cubed->ray->y < cubed->player->player_y)
		|| (cubed->ray->side == 2 && cubed->ray->x < cubed->player->player_x)
		|| (cubed->ray->side == 4 && cubed->ray->y > cubed->player->player_y))
	{
		cubed->ray->tex_x = cubed->textures[cubed->ray->side - 1].width
			- cubed->ray->tex_x - 1;
	}
}
