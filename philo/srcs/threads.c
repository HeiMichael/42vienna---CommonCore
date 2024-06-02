/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:10:39 by miheider          #+#    #+#             */
/*   Updated: 2024/06/01 19:48:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_and_create(t_rules *game, pthread_t *check)
{
	if (pthread_create(check, NULL, &is_dead, game->philos))
	{
		philo_error(-6);
		clean_up(game);
		return (-1);
	}
	return (0);
}

int	create_philo(t_rules *game)
{
	size_t	i;

	i = 0;
	timestamp(game);
	while (i < game->num_phil)
	{
		if (pthread_create(&game->philos[i].thread, NULL, &routine, \
					&game->philos[i]))
		{
			philo_error(-6);
			while (i < 0)
			{
				i--;
				pthread_join(game->philos[i].thread, NULL);
			}
			clean_up(game);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	join_philo(t_rules *game)
{
	size_t	i;

	i = 0;
	while (i < game->num_phil)
	{
		if (pthread_join(game->philos[i].thread, NULL))
		{
			philo_error(-7);
			while (i < game->num_phil)
			{
				pthread_join(game->philos[i].thread, NULL);
				i++;
			}
			clean_up(game);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	create_threads(t_rules *game)
{
	pthread_t	check;

	if (init_and_create(game, &check) < 0)
		return (-1);
	if (create_philo(game) < 0)
	{
		pthread_join(check, NULL);
		return (-1);
	}
	if (join_philo(game) < 0)
	{
		pthread_join(check, NULL);
		return (-1);
	}
	if (pthread_join(check, NULL))
	{
		philo_error(-7);
		clean_up(game);
		return (-1);
	}
	return (0);
}
