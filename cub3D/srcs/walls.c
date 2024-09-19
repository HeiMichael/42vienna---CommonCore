/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:19:34 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 11:38:24 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*This function draws the floor (first while) from the top of the screen to the
start of the wall and the ceiling (second while) from the end of the wall to 
the bottom of the screen*/
void	floor_and_ceiling(t_cub *cubed, int wall_start, int wall_end, int x)
{
	int	y;

	y = 0;
	while (y < wall_start)
	{
		put_pixel_to_image(cubed, x, y, cubed->map_data->ceiling);
		y++;
	}
	y = wall_end;
	while (y < SCREEN_H - 1)
	{
		put_pixel_to_image(cubed, x, y, cubed->map_data->floor);
		y++;
	}
}

/*this function calculates the distance from the current pixel to the top of
the wall and the texture y coordinate based on this distance. Then it clamps
tex_y to be within the texture height and gets the color from texture.*/
void	render_wall(t_cub *cubed, t_texture *texture, int x)
{
	int	d;
	int	color;
	int	y;

	y = cubed->ray->wall_start;
	while (y <= cubed->ray->wall_end)
	{
		d = y * 256 - SCREEN_H * 128 + cubed->ray->wall_height * 128;
		cubed->ray->tex_y = ((d * texture->height)
				/ cubed->ray->wall_height) / 256;
		if (cubed->ray->tex_y < 0)
			cubed->ray->tex_y = 0;
		if (cubed->ray->tex_y >= texture->height)
			cubed->ray->tex_y = texture->height - 1;
		color = texture->pixel[cubed->ray->tex_y
			* texture->width + cubed->ray->tex_x];
		put_pixel_to_image(cubed, x, y, color);
		y++;
	}
}

void	check_tex_x(t_cub *cubed, t_texture *texture)
{
	if (cubed->ray->tex_x < 0)
		cubed->ray->tex_x = 0;
	if (cubed->ray->tex_x >= texture->width)
		cubed->ray->tex_x = texture->width - 1;
}

void	adjust_wall(t_cub *cubed)
{
	if (cubed->ray->wall_end >= SCREEN_H)
		cubed->ray->wall_end = SCREEN_H - 1;
	if (cubed->ray->wall_start == cubed->ray->wall_end)
		cubed->ray->wall_end = cubed->ray->wall_start + 1;
}

/*this function first calculates the hight of the wall and where it starts
and ends. then it gets the current texture based on the side. After that
it calculates the texture x coordinate and the texture x position relative 
to the grid. The next section of the code is responsible for mapping the 
position on the wall where the ray hits (wall_x) to the corresponding 
x-coordinate (tex_x) within the texture. Last it is calling the functions
to render walls and floor/ceiling.*/
void	render_walls(t_cub *cubed, int x)
{
	double		wall_x;
	t_texture	*texture;

	cubed->ray->wall_height = (int)(SCREEN_H / (cubed->ray->distance / 64.0));
	if (cubed->ray->wall_height < 1)
		cubed->ray->wall_height = 1;
	cubed->ray->wall_start = -cubed->ray->wall_height / 2 + SCREEN_H / 2;
	if (cubed->ray->wall_start < 0)
		cubed->ray->wall_start = 0;
	cubed->ray->wall_end = cubed->ray->wall_height / 2 + SCREEN_H / 2;
	adjust_wall(cubed);
	texture = &cubed->textures[cubed->ray->side - 1];
	if (cubed->ray->side == 1 || cubed->ray->side == 3)
		wall_x = cubed->ray->hor_x;
	else
		wall_x = cubed->ray->ver_y;
	wall_x -= floor(wall_x / 64) * 64;
	if (cubed->ray->side == 1 || cubed->ray->side == 3 || cubed->ray->side == 4)
		cubed->ray->tex_x = (int)(wall_x / 64.0 * texture->width);
	else
		cubed->ray->tex_x = texture->width - 1
			- (int)(wall_x / 64.0 * texture->width);
	check_tex_x(cubed, texture);
	render_wall(cubed, texture, x);
	floor_and_ceiling(cubed, cubed->ray->wall_start, cubed->ray->wall_end, x);
}
