/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:17:30 by miheider          #+#    #+#             */
/*   Updated: 2023/12/14 20:34:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	check_if_finished(t_stack **stack_a, int **stack_c)
{
	t_stack	*head_a;
	int		i;

	head_a = *stack_a;
	i = 0;
	while (head_a->next != *stack_a)
	{
		if (head_a->number == *stack_c[i])
		{
			*head_a = *head_a->next;
		}
		else
		{
			return ;
		}
		i++;
	}
	ft_printf("OK - sorted correctly");
	exit (EXIT_SUCCESS);
}


void	sorting_three(t_stack **stack_a, int **stack_c, t_total **total)
{
	while (1)
	{
		if (((*stack_a)->next->number > (*stack_a)->number) &&
			((*stack_a)->next->number > (*stack_a)->prev->number))
			rra(stack_a);
		else if ((((*stack_a)->prev->number > (*stack_a)->next->number) &&
			((*stack_a)->prev->number > (*stack_a)->number)) ||
			(((*stack_a)->number > (*stack_a)->next->number) &&
			((*stack_a)->next->number > (*stack_a)->prev->number)))
			sa(stack_a, total);
		else if (((*stack_a)->number > (*stack_a)->next->number) &&
			((*stack_a)->number > (*stack_a)->prev->number) &&
			((*stack_a)->prev->number > (*stack_a)->next->number))
			ra(stack_a);
		check_if_finished(stack_a, stack_c);
	}
}*/
