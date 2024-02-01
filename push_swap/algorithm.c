/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:44:33 by miheider          #+#    #+#             */
/*   Updated: 2024/01/23 19:38:40 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack **stack)
{
	t_stack	*head;
	int		check;

	check = 1;
	if (*stack == NULL)
		return (1);
	head = *stack;
	while (1)
	{
		if (head->goal > head->next->goal && head->next != *stack)
			check = 0;
		head = head->next;
		if (head == *stack)
			break ;
	}
	return (check);
}

int	stack_len(t_stack **stack)
{
	t_stack	*current;
	int		i;

	current = *stack;
	if (*stack == NULL)
		return (0);
	i = 0;
	while (1)
	{
		current = current->next;
		i++;
		if (current == *stack)
			break ;
	}
	return (i);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c)
{
	int	i;
	int	j;
	int	size;

	*stack_c = *stack_c;
	size = stack_len(stack_a);
	i = 0;
	while (stack_sorted(stack_a) == 0)
	{
		j = 0;
		while (j < size && stack_sorted(stack_a) == 0)
		{
			if ((*stack_a)->goal >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_len(stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
