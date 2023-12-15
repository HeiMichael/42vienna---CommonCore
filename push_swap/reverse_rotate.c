/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:48:53 by miheider          #+#    #+#             */
/*   Updated: 2023/12/13 00:07:24 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*head_a;

	if (*stack_a != NULL)
	{
		head_a = *stack_a;
		head_a = head_a->prev;
		*stack_a = head_a;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*head_b;

	if (*stack_b != NULL)
	{
		head_b = *stack_b;
		head_b = head_b->prev;
		*stack_b = head_b;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (*stack_a != NULL || *stack_b != NULL)
	{
		head_a = *stack_a;
		head_a = head_a->prev;
		*stack_a = head_a;
		head_b = *stack_b;
		head_b = head_b->prev;
		*stack_b = head_b;
	}
	ft_printf("rrr\n");
}
