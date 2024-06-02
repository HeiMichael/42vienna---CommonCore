/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:55:06 by miheider          #+#    #+#             */
/*   Updated: 2024/05/30 15:33:53 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_error(int ret)
{
	if (ret == -1)
		ft_putstr_fd("Error: input must be 4 or 5 pos integer.\n", 2);
	if (ret == -2)
		ft_putstr_fd("Error: input greater than INT_MAX.\n", 2);
	if (ret == -3)
		ft_putstr_fd("Error: invalid input.\n", 2);
	if (ret == -4)
		ft_putstr_fd("Error: input must be greater than 0.\n", 2);
	if (ret == -6)
		ft_putstr_fd("Error: pthread_create fail.\n", 2);
	if (ret == -7)
		ft_putstr_fd("Error: pthread_join fail.\n", 2);
	if (ret == -8)
		ft_putstr_fd("Error: mutex fail.\n", 2);
}

void	mutex_error(int ret, int status, int i, t_rules *game)
{
	int	j;

	if (ret == -5)
		ft_putstr_fd("Error: malloc error.\n", 2);
	j = 0;
	while (j <= i)
	{
		if (pthread_mutex_destroy(&game->forks[i]))
			return ;
		i++;
	}
	if (status > 2)
		pthread_mutex_destroy(&game->write);
	if (status > 3)
		pthread_mutex_destroy(&game->eat);
	if (status > 4)
		pthread_mutex_destroy(&game->timestamp);
	if (status > 5)
		pthread_mutex_destroy(&game->deads);
	free(game->forks);
	game->forks = NULL;
	free(game->philos);
	game->philos = NULL;
}

int	clean_up(t_rules *game)
{
	size_t	i;

	i = 0;
	while (i < game->num_phil)
	{
		if (pthread_mutex_destroy(&game->forks[i]))
			return (-1);
		i++;
	}
	if (pthread_mutex_destroy(&game->write)
		|| pthread_mutex_destroy(&game->eat)
		|| pthread_mutex_destroy(&game->deads)
		|| pthread_mutex_destroy(&game->timestamp))
		return (-1);
	if (game->forks != NULL)
	{
		free(game->forks);
		game->forks = NULL;
	}
	if (game->philos != NULL)
	{
		free(game->philos);
		game->philos = NULL;
	}
	return (0);
}
