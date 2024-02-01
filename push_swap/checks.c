/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:30:26 by miheider          #+#    #+#             */
/*   Updated: 2024/01/30 14:07:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(long *numbers, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (numbers[i] > numbers[i + 1])
		{
			return ;
		}
		i++;
	}
	free(numbers);
	exit(0);
}

void	check_args(int argc, char **argv)
{
	int	i;

	while (*argv[1] == 32)
		argv[1]++;
	if (argc <= 1 || (argc == 1 && argv[1][0] == '\0'))
		error_message(1, NULL);
	if (argc == 2 && (argv[1][0] == '\0'))
		error_message(1, NULL);
	if (argc == 2 && (argv[1][0] == 43 || argv[1][0] == 45) && ((argv[1][1]
		< 48 && argv[1][1] > 57) || argv[1][1] == '\0'))
		error_message(1, NULL);
	if (argc > 2)
	{
		i = 0;
		while (i < (argc - 1))
		{
			if ((argv[i][0] == 43 || argv[i][0] == 45) && ((argv[i][1]
				< 48 && argv[i][1] > 57) || argv[i][1] == '\0'))
				error_message(1, NULL);
			i++;
		}
	}
}

void	check_duplicate(long *numbers, int count, long number)
{
	int	i;

	if (number < -2147483648 || number > 2147483647)
		error_message(1, numbers);
	i = 0;
	while (i < count)
	{
		if (numbers[i] == number)
		{
			error_message(1, numbers);
		}
		i++;
	}
}

long	*check_input(int argc, char **argv)
{
	long	*numbers;
	long	number;
	int		num_index;

	num_index = 0;
	numbers = (long *)ft_calloc(argc, sizeof(long));
	if (!numbers)
		exit(1);
	while (argc > 0)
	{
		number = ft_atol(*argv, numbers);
		check_duplicate(numbers, num_index, number);
		numbers[num_index++] = number;
		argv++;
		argc--;
	}
	is_sorted(numbers, num_index);
	return (numbers);
}

long	*check_input_str(char **argv, int *argc)
{
	long	*numbers;
	int		num_index;
	long	number;
	char	*token;

	num_index = 0;
	*argc = input_len(argv);
	numbers = (long *)ft_calloc((*argc), sizeof(long));
	if (!numbers)
		exit(1);
	token = ft_strtok(*argv, " ", numbers);
	while (token != NULL)
	{
		number = ft_atol(token, numbers);
		check_duplicate(numbers, num_index, number);
		numbers[num_index++] = number;
		token = ft_strtok(NULL, " ", numbers);
	}
	is_sorted(numbers, num_index);
	return (numbers);
}
