/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:48:22 by miheider          #+#    #+#             */
/*   Updated: 2023/12/23 16:21:31 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;

	if (*stack != NULL)
	{
		head = *stack;
		head = head->next;
		*stack = head;
	}
}

void	ra(t_stack **stack_a)
{
	if (stack_a != NULL)
		rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (*stack_b != NULL)
		rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL || *stack_b != NULL)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	ft_printf("rr\n");
}
