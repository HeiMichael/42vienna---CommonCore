/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:24 by miheider          #+#    #+#             */
/*   Updated: 2024/09/09 13:16:49 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	check_angle(double ray_angle)
{
	if (ray_angle < 0)
		ray_angle += 2 * PI;
	if (ray_angle >= 2 * PI)
		ray_angle -= 2 * PI;
	return (ray_angle);
}

int	check_borders(t_cub *cubed)
{
	if (cubed->ray->coll_a < 0
		|| cubed->ray->coll_b < 0
		|| cubed->ray->coll_x < 0
		|| cubed->ray->coll_y < 0
		|| cubed->ray->coll_a >= cubed->ray->max_grid_x
		|| cubed->ray->coll_b >= cubed->ray->max_grid_y
		|| cubed->ray->coll_x >= cubed->ray->max_grid_x
		|| cubed->ray->coll_y >= cubed->ray->max_grid_y)
	{
		return (1);
	}
	else
		return (0);
}
