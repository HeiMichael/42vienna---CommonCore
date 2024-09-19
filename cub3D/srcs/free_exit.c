/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:58:15 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:03 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_ray(t_cub *cubed)
{
	if (cubed->ray)
	{
		free(cubed->ray);
		cubed->ray = NULL;
	}
}

void	free_pot(t_cub *cubed)
{
	int	i;

	i = 0;
	while (i < FD)
	{
		if (cubed->pot[i])
		{
			free(cubed->pot[i]);
			cubed->pot[i] = NULL;
		}
		i++;
	}
	free(cubed->pot);
}

int	free_exit(t_cub *cubed, char *message)
{
	free_pot(cubed);
	free_mlx(cubed);
	free_map(cubed);
	free_player(cubed);
	if (cubed->textures)
		free(cubed->textures);
	free_map_data(cubed);
	free_ray(cubed);
	if (message != NULL && *message != '\0')
	{
		ft_putstr_fd(message, 2);
		exit(1);
	}
	else
		exit(0);
}
