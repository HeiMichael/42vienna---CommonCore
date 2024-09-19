/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:13:32 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 13:46:40 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_collision(t_cub *cubed, double x, double y)
{
	double	a;
	double	b;

	a = x - 0.1;
	b = y - 0.1;
	x += 0.1;
	y += 0.1;
	cubed->ray->coll_x = (int)x;
	cubed->ray->coll_y = (int)y;
	cubed->ray->coll_a = (int)a;
	cubed->ray->coll_b = (int)b;
	if (check_borders(cubed))
		return (1);
	if (cubed->map[(int)y][(int)x] == 49 || cubed->map[(int)b][(int)a] == 49
		|| cubed->map[(int)y][(int)x] == 32
		|| cubed->map[(int)y][(int)x] == '\n'
		|| cubed->map[(int)b][(int)a] == '\n'
		|| cubed->map[(int)y][(int)x] == '\0'
		|| cubed->map[(int)b][(int)a] == '\0')
		return (1);
	else
		return (0);
}

void	check_collision(t_cub *cubed, double *new_x, double *new_y)
{
	if (!is_collision(cubed, *new_x, *new_y))
	{
		cubed->player->player_x = *new_x;
		cubed->player->player_y = *new_y;
	}
}

void	calc_move(t_cub *cubed, double *new_x, double *new_y, int dec)
{
	if (dec == 0)
	{
		*new_x = cubed->player->player_x + cos(cubed->player->angle) * 0.4;
		*new_y = cubed->player->player_y + sin(cubed->player->angle) * 0.4;
	}
	if (dec == 1)
	{
		*new_x = cubed->player->player_x - cos(cubed->player->angle) * 0.4;
		*new_y = cubed->player->player_y - sin(cubed->player->angle) * 0.4;
	}
	if (dec == 2)
	{
		*new_x = cubed->player->player_x + sin(cubed->player->angle) * 0.4;
		*new_y = cubed->player->player_y - cos(cubed->player->angle) * 0.4;
	}
	if (dec == 3)
	{
		*new_x = cubed->player->player_x - sin(cubed->player->angle) * 0.4;
		*new_y = cubed->player->player_y + cos(cubed->player->angle) * 0.4;
	}
	check_collision(cubed, new_x, new_y);
}

int	movement(int keysym, t_cub *cubed)
{
	double	new_x;
	double	new_y;

	if (keysym == XK_Escape)
		free_exit(cubed, NULL);
	if (keysym == XK_Right)
	{
		cubed->player->angle += ONE_DEGREE * 5;
		cubed->player->angle = check_angle(cubed->player->angle);
	}
	if (keysym == XK_Left)
	{
		cubed->player->angle -= ONE_DEGREE * 5;
		cubed->player->angle = check_angle(cubed->player->angle);
	}
	if (keysym == XK_w)
		calc_move(cubed, &new_x, &new_y, 0);
	if (keysym == XK_s)
		calc_move(cubed, &new_x, &new_y, 1);
	if (keysym == XK_a)
		calc_move(cubed, &new_x, &new_y, 2);
	if (keysym == XK_d)
		calc_move(cubed, &new_x, &new_y, 3);
	return (0);
}

int	x_click(t_cub *cubed)
{
	free_exit(cubed, NULL);
	return (0);
}
