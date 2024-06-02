/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:55:49 by miheider          #+#    #+#             */
/*   Updated: 2024/05/31 14:02:05 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	current_time(t_rules *game)
{
	struct timeval	end;
	long			elapsed;

	if (gettimeofday(&end, NULL))
		return (-1);
	elapsed = (end.tv_sec * 1000 + end.tv_usec / 1000) - game->time_start;
	return (elapsed);
}

long	timestamp(t_rules *game)
{
	struct timeval	start;
	struct timeval	end;
	long			elapsed;

	pthread_mutex_lock(&(game->timestamp));
	if (game->time_start == 0)
	{
		if (gettimeofday(&start, NULL))
			return (-1);
		game->time_start = start.tv_sec * 1000 + start.tv_usec / 1000;
		pthread_mutex_unlock(&(game->timestamp));
		return (0);
	}
	else
	{
		if (gettimeofday(&end, NULL))
			return (-1);
		elapsed = (end.tv_sec * 1000 + end.tv_usec / 1000) - game->time_start;
		pthread_mutex_unlock(&(game->timestamp));
		return (elapsed);
	}
}

void	set_dead(t_phil *philos)
{
	pthread_mutex_lock(&philos->game->deads);
	philos->game->dead = 1;
	pthread_mutex_unlock(&philos->game->deads);
	pthread_mutex_unlock(&(philos->game->eat));
}
