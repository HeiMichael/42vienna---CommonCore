/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:42:10 by miheider          #+#    #+#             */
/*   Updated: 2024/06/01 23:05:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_phil *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_f);
		print_message(philos, philos->id, "has taken a fork");
	}
	pthread_mutex_lock(philos->left_f);
	print_message(philos, philos->id, "has taken a fork");
	if (philos->id % 2 == 1)
	{
		pthread_mutex_lock(philos->right_f);
		print_message(philos, philos->id, "has taken a fork");
	}
}

void	eating(t_phil *philos)
{
	take_forks(philos);
	pthread_mutex_lock(&(philos->game->deads));
	if (current_time(philos->game) <= philos->time_death)
		philos->time_death = current_time(philos->game) \
			+ philos->game->time_die;
	pthread_mutex_unlock(&(philos->game->deads));
	print_message(philos, philos->id, "is eating");
	my_usleep(philos->game->time_eat * 1000);
	pthread_mutex_lock(&philos->game->eat);
	pthread_mutex_unlock(philos->right_f);
	pthread_mutex_unlock(philos->left_f);
	philos->count_meal += 1;
	pthread_mutex_unlock(&philos->game->eat);
	if (philos->game->num_meal != -1 && check_for_dead(philos) == 0)
	{
		pthread_mutex_lock(&philos->game->eat);
		if (philos->count_meal == philos->game->num_meal)
		{
			philos->game->finished_meal += 1;
		}
		pthread_mutex_unlock(&philos->game->eat);
	}
}

void	thinking(t_phil *philos)
{
	int	diff;

	diff = 0;
	print_message(philos, philos->id, "is thinking");
	my_usleep(300);
	diff = philos->game->time_eat - philos->game->time_sleep;
	if (diff >= 0 && philos->game->num_phil % 2 == 1)
		my_usleep((diff * 1000) + 2700);
}

void	sleeping(t_phil *philos)
{
	print_message(philos, philos->id, "is sleeping");
	my_usleep(philos->game->time_sleep * 1000);
}

void	*routine(void *arg)
{
	int		i;
	t_phil	*philos;

	philos = (t_phil *)arg;
	if (philos->game->num_phil == 1)
	{
		print_message(philos, philos->id, "has taken a fork");
		my_usleep(philos->game->time_die * 1000);
		print_message(philos, philos->id, "died");
		philos->game->dead = 1;
		return (NULL);
	}
	if (philos->id % 2 == 1)
		my_usleep((philos->game->time_eat / 2) * 1000);
	i = 0;
	while (check_for_dead(philos) == 0)
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
		i++;
	}
	return (NULL);
}
