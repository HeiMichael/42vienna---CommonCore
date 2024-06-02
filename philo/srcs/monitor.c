/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:19:51 by miheider          #+#    #+#             */
/*   Updated: 2024/06/01 21:49:15 by miheider         ###   ########.fr       */
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

	pthread_mutex_lock(&(philos->game->write));
	time = current_time(philos->game);
	if ((check_for_dead(philos)) == 0)
	{
		ft_putnbr_fd (time, 1);
		write (1, " ", 1);
		ft_putnbr_fd (id, 1);
		write (1, " ", 1);
		ft_putstr_fd (message, 1);
		write (1, "\n", 1);
	}
	pthread_mutex_unlock(&(philos->game->write));
}

void	*is_dead_cont(t_rules *game, int i)
{
	pthread_mutex_lock(&(game->deads));
	if (current_time(game) > (game->philos[i].time_death))
	{
		pthread_mutex_unlock(&(game->deads));
		print_message(game->philos, i + 1, "died");
		pthread_mutex_lock(&game->deads);
		game->dead = 1;
		pthread_mutex_unlock(&game->deads);
		return (NULL);
	}
	pthread_mutex_unlock(&(game->deads));
	return ((void *)5);
}

void	*is_dead(void *arg)
{
	t_phil	*philos;
	size_t	i;

	philos = (t_phil *)arg;
	i = 0;
	my_usleep(100);
	while ((check_for_dead(philos)) == 0)
	{
		i = 0;
		if (philos->game->num_meal != -1)
		{
			pthread_mutex_lock(&(philos->game->eat));
			if (philos->game->finished_meal == (int)philos->game->num_phil)
				return (set_dead(philos), NULL);
			pthread_mutex_unlock(&(philos->game->eat));
		}
		while (i < philos->game->num_phil)
		{
			if (is_dead_cont(philos->game, i) == NULL)
				return (NULL);
			i++;
		}
		my_usleep(3700);
	}
	return (NULL);
}
