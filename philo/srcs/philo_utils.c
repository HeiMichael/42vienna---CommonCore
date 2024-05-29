/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:14:36 by miheider          #+#    #+#             */
/*   Updated: 2024/05/28 16:11:51 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)   //if(!s1 || !s2)
{ 
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	ft_philo_atoi(char *input)
{
	size_t	i;
	int		result;

	if (NULL == input)
		return (-1);
	i = 0;
	result = 0;
	while (input[i])
	{
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
			i++;
		if (input[i] == '+')
			i++;
		while (input[i] >= 48 && input[i] <= 57)
		{
			result = result * 10 + input[i] - 48;
			i++;
		}
	}
	return (result);
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
