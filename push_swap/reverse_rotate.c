/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:48:53 by miheider          #+#    #+#             */
/*   Updated: 2023/12/22 13:56:43 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;

	if (*stack != NULL)
	{
		head = *stack;
		head = head->prev;
		*stack = head;
	}
}

void	rra(t_stack **stack_a)
{
	if (*stack_a != NULL)
		reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b != NULL)
		reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL || *stack_b != NULL)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	ft_printf("rrr\n");
}
