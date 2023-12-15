/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:30:26 by miheider          #+#    #+#             */
/*   Updated: 2023/12/15 20:36:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include "push_swap.h"

void is_sorted(long *numbers, int size)
{
    int i;

    i = 0;
    while (i < (size - 1))
    {
        ft_printf("issorted: %ld\n", numbers[i]);
        if (numbers[i] > numbers[i + 1])
            return ;
        i++;
    }
    exit(1);
}

void check_args(int argc, char **argv)
{
    int i;

    if (argc <= 1 || (argc == 1 && argv[1][0] == '\0'))
   	    exit(1);
    if (argc == 2 && argv[1][0] == 32)
    	error_message(4);
    if (argc == 2 && (argv[1][0] == 43 || argv[1][0] == 45) && ((argv[1][1] < 48 && argv[1][1] > 57) || argv[1][1] == '\0'))
    	error_message(5);
    if (argc > 2)
    {
        i = 0;
        while (i < (argc - 1))
        {
            if (argv[i][0] == 32)
                error_message(4);
            if ((argv[i][0] == 43 || argv[i][0] == 45) && ((argv[i][1] < 48 && argv[i][1] > 57) || argv[i][1] == '\0'))
    	        error_message(5);
            i++;
        }

    }
}

void check_duplicate(const long *numbers, int count, long number)
{
	int	i;

    if (number < -2147483648 || number > 2147483647)
        error_message(3);
    i = 0;
    while (i < count)
	{
        if (numbers[i] == number)
        {
        	error_message(2);
        }
		i++;
    }
}

long *check_input(int argc, char **argv)
{
    long    *numbers;
    long    number;
    int     num_index = 0;

    numbers = (long *)ft_calloc(argc, sizeof(long));
    if (!numbers)
        exit(-3);
    while (argc > 0)
    {
        number = ft_atol(*argv);
        check_duplicate(numbers, num_index, number);
        numbers[num_index++] = number;
        argv++;
        argc--;
    }
    is_sorted(numbers, num_index);
    return(numbers);
}

long *check_input_str(char **argv, int *argc)
{
    long    *numbers;
    int     num_index = 0;
    long    number;

    *argc = input_len(argv);
    numbers = (long *)ft_calloc((*argc), sizeof(long));
    if (!numbers)
        exit(-3);
    char *token = ft_strtok(*argv, " ");
    while (token != NULL)
    {
        number = ft_atol(token);
        check_duplicate(numbers, num_index, number);
        numbers[num_index++] = number;
        token = ft_strtok(NULL, " ");
    }
    is_sorted(numbers, num_index);
    return(numbers);
}