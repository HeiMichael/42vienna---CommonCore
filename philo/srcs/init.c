/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:33:25 by miheider          #+#    #+#             */
/*   Updated: 2024/05/30 15:23:22 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philos(t_rules *game)
{
	size_t	i;

	i = 0;
	while (i < game->num_phil)
	{
		game->philos[i].id = i + 1;
		game->philos[i].count_meal = 0;
		game->philos[i].right_f = &game->forks[i];
		game->philos[i].left_f = &game->forks[(i + 1) % game->num_phil];
		game->philos[i].game = game;
		game->philos[i].time_death = game->time_die;
		i++;
	}
}

int	alocate_memory(t_rules *game)
{
	game->philos = malloc(sizeof(t_phil) * game->num_phil);
	if (!game->philos)
		return (philo_error(-5), -1);
	game->forks = malloc(sizeof(pthread_mutex_t) * game->num_phil);
	if (!game->forks)
	{
		free(game->philos);
		game->philos = NULL;
		return (philo_error(-5), -1);
	}
	return (0);
}

int	init_game(t_rules *game)
{
	size_t	i;

	i = 0;
	while (i < game->num_phil)
	{
		if (pthread_mutex_init(&game->forks[i], NULL))
			return (mutex_error(-5, 1, i, game), -1);
		i++;
	}
	if (pthread_mutex_init(&(game->write), NULL))
		return (mutex_error(-5, 2, i, game), -1);
	if (pthread_mutex_init(&(game->eat), NULL))
		return (mutex_error(-5, 3, i, game), -1);
	if (pthread_mutex_init(&(game->timestamp), NULL))
		return (mutex_error(-5, 4, i, game), -1);
	if (pthread_mutex_init(&(game->deads), NULL))
		return (mutex_error(-5, 5, i, game), -1);
	game->time_start = 0;
	game->finished_meal = 0;
	game->dead = 0;
	return (0);
}

int	init_struct(t_rules *game)
{
	if (alocate_memory(game) < 0)
		return (-1);
	if (init_game(game))
		return (-1);
	init_philos(game);
	return (0);
}

int	insert_arg(t_rules *game, int argc, char **argv)
{
	memset(game, 0, sizeof(t_rules));
	game->num_phil = ft_philo_atoi(argv[1]);
	game->time_die = ft_philo_atoi(argv[2]);
	game->time_eat = ft_philo_atoi(argv[3]);
	game->time_sleep = ft_philo_atoi(argv[4]);
	if (argc == 5)
		game->num_meal = ft_philo_atoi(argv[5]);
	else
		game->num_meal = -1;
	if (game->num_phil == 0 || game->time_die == 0 || game->time_eat == 0
		|| game->time_sleep == 0 || game->num_meal == 0)
		return (-1);
	game->time_start = 0;
	return (0);
}
