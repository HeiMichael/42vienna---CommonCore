/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:42:10 by miheider          #+#    #+#             */
/*   Updated: 2024/05/29 17:24:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_for_dead(t_phil *philos)
{
	pthread_mutex_lock(&(philos->game->deads));
	if (philos->game->dead == 0)
	{
		pthread_mutex_unlock(&(philos->game->deads));
		return (0);
	}
	pthread_mutex_unlock(&(philos->game->deads));
	return (1);
}

void	print_message(t_phil *philos, int id, char *message)
{
	long long	time;

	time = timestamp(philos->game);
	pthread_mutex_lock(&(philos->game->write));
	if ((check_for_dead(philos)) == 0)
	{
		printf("%lld %d %s\n", time, id, message);
	}
	pthread_mutex_unlock(&(philos->game->write));
}

void	*is_dead_cont(t_phil *philos, int i)
{
	pthread_mutex_lock(&philos->game->deads);
	if (timestamp(philos->game) > philos[i].time_death)
	{
		pthread_mutex_unlock(&philos->game->deads);
		print_message(philos, i + 1, "died");
		pthread_mutex_lock(&philos->game->deads);
		philos->game->dead = 1;
		pthread_mutex_unlock(&philos->game->deads);
		return (NULL);
	}
	pthread_mutex_unlock(&philos->game->deads);
	return ((void *)5);
}

void	*is_dead(void *arg)
{
	t_phil	*philos;
	size_t	i;

	philos = (t_phil *)arg;
	i = 0;
	while ((check_for_dead(philos)) == 0)
	{
		i = 0;
		pthread_mutex_lock(&(philos->game->deads));
		if (philos->count_meal != -1)
		{
			pthread_mutex_unlock(&(philos->game->deads));
			pthread_mutex_lock(&philos->game->deads);
			if ((size_t)philos->game->finished_meal == philos->game->num_phil)
				return (pthread_mutex_unlock(&philos->game->deads), NULL);
			pthread_mutex_unlock(&philos->game->deads);
		}
		while (i < philos->game->num_phil)
		{
			if (is_dead_cont(philos, i) == NULL)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

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
	pthread_mutex_lock(&philos->game->deads);
	philos->count_meal += 1;
	pthread_mutex_unlock(&philos->game->deads);
	pthread_mutex_lock(&philos->game->eat);
	if (philos->count_meal != -1 && check_for_dead(philos) == 0)
	{
		if (philos->count_meal == philos->game->num_meal)
		{
			pthread_mutex_lock(&(philos->game->deads));
			philos->game->finished_meal += 1;
			pthread_mutex_unlock(&(philos->game->deads));
		}
	}
	pthread_mutex_unlock(&philos->game->eat);
	usleep(philos->game->time_eat * 1000);
	pthread_mutex_lock(&(philos->game->deads));
    philos->time_death = timestamp(philos->game) + philos->game->time_die;
	pthread_mutex_unlock(&(philos->game->deads));
	pthread_mutex_unlock(philos->right_f);
	pthread_mutex_unlock(philos->left_f);
}

void	thinking(t_phil *philos)
{
	int	diff;

	diff = 0;
	print_message(philos, philos->id, "is thinking");
	usleep(300);
	diff = philos->game->time_eat - philos->game->time_sleep;
	if (diff >= 0 && philos->game->num_phil % 2 == 1)
		usleep((diff * 1000) + 2000);
}

void	sleeping(t_phil *philos)
{
	print_message(philos, philos->id, "is sleeping");
	usleep(philos->game->time_sleep * 1000);
}

void	*routine(void *arg)
{
	int		i;
	t_phil	*philos;

	philos = (t_phil *)arg;
	if (philos->game->num_phil == 1)
	{
		print_message(philos, philos->id, "has taken a fork");
		usleep(philos->game->time_die * 1000);
		print_message(philos, philos->id, "died");
		philos->game->dead = 1;
		return (NULL);
	}
	if (philos->id % 2 == 1)
		usleep((philos->game->time_eat / 2) * 1000);
	i = 0;
	while ((i < philos->game->num_meal || philos->game->num_meal == -1)
		&& check_for_dead(philos) == 0)
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
		i++;
	}
	return (NULL);
}

int	create_threads(t_rules *game)
{
	size_t		i;
	pthread_t	check;

	game->time_start = timestamp(game);
	if (pthread_create(&check, NULL, &is_dead, game->philos))
		return (philo_error(-6), -1);
	i = 0;
	while (i < game->num_phil)
	{
		if (pthread_create(&game->philos[i].thread, NULL, \
					&routine, &game->philos[i]))
		{
			philo_error(-6);
			while (i > 0)
			{
				i--;
				pthread_join(game->philos[i].thread, NULL);
			}
			pthread_join(check, NULL);
			return (-1);
		}
		i++;
	}
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
			pthread_join(check, NULL);
			return (-1);
		}
		i++;
	}
	if (pthread_join(check, NULL))
		return (philo_error(-7), -1);
	return (0);
}
