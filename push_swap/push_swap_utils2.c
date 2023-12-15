/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:59:16 by miheider          #+#    #+#             */
/*   Updated: 2023/12/14 21:59:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <complex.h>

long	ft_atol(const char *nptr)
{
	int		i;
	long	x;
	int		sign;

	sign = 1;
	x = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] != '\0' && nptr[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] != '\0' && nptr[i] == 43)
		i++;
	else if (nptr[i] < 48 || nptr[i] > 57)
		error_message(7);
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		x = 10 * x + nptr[i] - 48;
		i++;
	}
	return (sign * x);
}

void	length_of_token(char *token)
{
	long	i;

	i = 0;
	while (token[i])
		i++;
	if (i >= 12)
		error_message(4);
	return ;
}
int	input_len(char **argv)
{
	int	i;
	int	wc;

    i = 0;
	while (argv[0][i])
	{
		while (argv[0][i] && (argv[0][i] == ' ' || argv[0][i] == '\t' || argv[0][i] == '\n'))
			i++;
		if (argv[0][i])
			wc++;
		while (argv[0][i] && (argv[0][i] != ' ' && argv[0][i] != '\t' && argv[0][i] != '\n'))
			i++;
	}
	return (wc);
}
