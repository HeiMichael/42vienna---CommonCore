/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:08:38 by miheider          #+#    #+#             */
/*   Updated: 2024/05/28 17:15:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	skip_whitespace_and_sign(char *str, int *j)
{
	while ((str[*j] >= 9 && str[*j] <= 13) || str[*j] == 32)
		(*j)++;
	if (str[*j] == 43)
		(*j)++;
	if (str[*j] < 48 || str[*j] > 57)
		return (-3);
	return (0);
}

int	check_max(char *argv)
{
	argv -= 10;
	printf("arg: %s\n", argv);
	return (ft_strncmp(argv, "2147483647", 10));
}

void	counter(int *j, int *counter)
{
	(*j)++;
	(*counter)++;
}

int	check_substring(char *str)
{
	int	j;
	int	count;
	int	result;

	j = 0;
	count = 0;
	result = skip_whitespace_and_sign(str, &j);
	if (result != 0)
		return (result);
	while ((str[j] >= 48 && str[j] <= 57))
		counter(&j, &count);
	if (count > 10 || (count == 10 && check_max(&str[j]) > 0))
		return (-2);
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == 32)
		j++;
	if (str[j] != '\0')
		return (-3);
	return (0);
}

int	check_input(char **argv)
{
	int	i;
	int	result;

	i = 0;
	while (argv[i])
	{
		result = check_substring(argv[i]);
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}
