/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:59:16 by miheider          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr, long *numbers)
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
	if ((nptr[i] < 48 || nptr[i] > 57))
		error_message(1, numbers);
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
		x = 10 * x + nptr[i++] - 48;
	if (nptr[i] != 0 && (nptr[i] < 48 || nptr[i] > 57))
		error_message(1, numbers);
	return (sign * x);
}

void	length_of_token(char *token, long *numbers)
{
	long	i;

	i = 0;
	while (token[i])
		i++;
	if (i >= 12)
		error_message(1, numbers);
	return ;
}

int	input_len(char **argv)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (argv[0][i])
	{
		while (argv[0][i] && (argv[0][i] == ' ' || argv[0][i] == '\t'
			|| argv[0][i] == '\n'))
			i++;
		if (argv[0][i])
			wc++;
		while (argv[0][i] && (argv[0][i] != ' '
			&& argv[0][i] != '\t' && argv[0][i] != '\n'))
			i++;
	}
	return (wc);
}

void	index_stack(t_stack **stack, int x)
{
	t_stack	*head;
	int		i;

	i = 1;
	if (*stack == NULL)
		return ;
	head = *stack;
	while (1)
	{
		head->index = i;
		i++;
		head = head->next;
		if (head == *stack)
			break ;
	}
	head = *stack;
	i--;
	while (1)
	{
		head->stack = x;
		head->index_max = i;
		head = head->next;
		if (head == *stack)
			break ;
	}
}
