/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:47:40 by miheider          #+#    #+#             */
/*   Updated: 2023/12/22 16:49:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap_nodes(stack_a);
	(*stack_a)->index = 1;
	(*stack_a)->next->index = 2;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_nodes(stack_b);
	(*stack_b)->index = 1;
	(*stack_b)->next->index = 2;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	(*stack_a)->index = 1;
	(*stack_a)->next->index = 2;
	swap_nodes(stack_b);
	(*stack_b)->index = 1;
	(*stack_b)->next->index = 2;
	ft_printf("ss\n");
}
