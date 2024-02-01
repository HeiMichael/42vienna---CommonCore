/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:12:20 by miheider          #+#    #+#             */
/*   Updated: 2024/01/25 16:26:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error_message(int error, long *numbers)
{
	if (error == 1)
		ft_printf("Error!\n");
	free(numbers);
	exit (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (*stack == NULL)
		return ;
	current = *stack;
	next_node = current->next;
	while (next_node != *stack)
	{
		free(current);
		current = next_node;
		next_node = current->next;
	}
	free(current);
	*stack = NULL;
}

void	free_and_exit(t_stack **stack_a, t_stack **stack_c)
{
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_c)
		free_stack(stack_c);
	exit (1);
}
