/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:55:06 by miheider          #+#    #+#             */
/*   Updated: 2024/05/28 16:26:56 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_error(int ret)
{
	if (ret == -1)
		write(2, "Error: input must be 4 or 5 pos integer.\n", 42);
	if (ret == -2)
		write(2, "Error: input greater than INT_MAX.\n", 36);
	if (ret == -3)
		write(2, "Error: invalid input.\n", 23);
	if (ret == -4)
		write(2, "Error: input must be greater than 0.\n", 38);
	if (ret == -5)
		write(2, "Error: malloc error.\n", 22);
	if (ret == -6)
		write(2, "pthread_create fail.\n", 22);
	if (ret == -7)
		write(2, "pthread_join fail.\n", 22);
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
