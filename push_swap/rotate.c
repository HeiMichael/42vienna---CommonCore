/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:48:22 by miheider          #+#    #+#             */
/*   Updated: 2023/12/13 00:06:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*head_a;

	if (*stack_a != NULL)
	{
		head_a = *stack_a;
		head_a = head_a->next;
		*stack_a = head_a;
		printf("ra\n");
	}
}

void	rb(t_stack **stack_b)
{
	t_stack	*head_b;

	if (*stack_b != NULL)
	{
		head_b = *stack_b;
		head_b = head_b->next;
		*stack_b = head_b;
		printf("ra\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (*stack_a != NULL || *stack_b != NULL)
	{
		head_a = *stack_a;
		head_a = head_a->next;
		*stack_a = head_a;
		head_b = *stack_b;
		head_b = head_b->next;
		*stack_b = head_b;
	}
	ft_printf("rr\n");
}
