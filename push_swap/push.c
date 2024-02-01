/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:31:32 by miheider          #+#    #+#             */
/*   Updated: 2023/12/22 13:32:38 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_cont(t_stack **stack_a, t_stack *head_b, t_stack *last_a)
{
	if (*stack_a == NULL)
	{
		*stack_a = head_b;
		head_b->next = head_b;
		head_b->prev = head_b;
	}
	else
	{
		last_a = (*stack_a)->prev;
		head_b->next = *stack_a;
		head_b->prev = last_a;
		(*stack_a)->prev = head_b;
		last_a->next = head_b;
		*stack_a = head_b;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;
	t_stack	*last_a;

	head_b = NULL;
	last_a = NULL;
	if (*stack_b != NULL)
	{
		head_b = *stack_b;
		if (head_b->next == head_b)
		{
			*stack_b = NULL;
		}
		else
		{
			head_b->prev->next = head_b->next;
			head_b->next->prev = head_b->prev;
			*stack_b = head_b->next;
		}
		pa_cont(stack_a, head_b, last_a);
		ft_printf("pa\n");
	}
}

void	pb_cont(t_stack **stack_b, t_stack *head_a, t_stack *last_b)
{
	if (*stack_b == NULL)
	{
		*stack_b = head_a;
		head_a->next = head_a;
		head_a->prev = head_a;
	}
	else
	{
		last_b = (*stack_b)->prev;
		head_a->next = *stack_b;
		head_a->prev = last_b;
		(*stack_b)->prev = head_a;
		last_b->next = head_a;
		*stack_b = head_a;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*last_b;

	head_a = NULL;
	last_b = NULL;
	if (*stack_a != NULL)
	{
		head_a = *stack_a;
		if (head_a->next == head_a)
		{
			*stack_a = NULL;
		}
		else
		{
			head_a->prev->next = head_a->next;
			head_a->next->prev = head_a->prev;
			*stack_a = head_a->next;
		}
		pb_cont(stack_b, head_a, last_b);
		ft_printf("pb\n");
	}
}
