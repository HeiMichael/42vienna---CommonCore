/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:16:20 by miheider          #+#    #+#             */
/*   Updated: 2024/01/23 15:06:51 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number
		&& (*stack_a)->next->number > (*stack_a)->prev->number)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->number > (*stack_a)->prev->number
		&& (*stack_a)->prev->number > (*stack_a)->next->number)
		ra(stack_a);
	else if ((*stack_a)->number < (*stack_a)->prev->number
		&& (*stack_a)->next->number > (*stack_a)->prev->number)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->number > (*stack_a)->next->number
		&& (*stack_a)->prev->number > (*stack_a)->number)
		sa(stack_a);
	else if ((*stack_a)->number < (*stack_a)->next->number
		&& (*stack_a)->next->number < (*stack_a)->prev->number)
		return ;
	else
		rra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->number < (*stack_a)->number)
		pa(stack_a, stack_b);
	else if ((*stack_b)->number > (*stack_a)->prev->number)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if ((*stack_b)->number > (*stack_a)->number && ((*stack_b)->number
			< ((*stack_a)->next->number)))
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if (((*stack_b)->number < ((*stack_a)->prev->number))
		&& ((*stack_b)->number > (*stack_a)->next->number))
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next->smin == 1)
		ra(stack_a);
	else if ((*stack_a)->next->next->smin == 1)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->prev->prev->smin == 1)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->prev->smin == 1)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
