/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:05:22 by miheider          #+#    #+#             */
/*   Updated: 2024/01/25 16:27:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goal_a(t_stack **stack_a, t_stack **stack_c, int argc)
{
	t_stack	*head_a;
	t_stack	*head_c;

	head_a = *stack_a;
	head_c = *stack_c;
	while (1)
	{
		head_a = *stack_a;
		while (1)
		{
			if (head_c->number == head_a->number)
			{
				head_a->goal = head_c->index;
				head_a->total_len = argc;
				head_a->stack = 1;
			}
			head_a = head_a->next;
			if (head_a == *stack_a)
				break ;
		}
		head_c = head_c->next;
		if (head_c == *stack_c)
			break ;
	}
}

void	sort_stack_c(t_stack **stack_c)
{
	t_stack	*i;
	t_stack	*j;
	int		temp;

	i = *stack_c;
	while (i->next != *stack_c)
	{
		j = i->next;
		while (j != *stack_c)
		{
			if (i->number > j->number)
				swap_numbers(i, j);
			j = j->next;
		}
		i = i->next;
	}
	temp = 0;
	i = *stack_c;
	while (i->next != *stack_c)
	{
		i->index = temp;
		temp++;
		i = i->next;
	}
}

void	stack_info_cont(t_stack *head_a, t_stack **stack_c)
{
	t_stack	*new_node;
	t_stack	*head_c;

	head_c = *stack_c;
	new_node = ft_calloc(1, sizeof(*new_node));
	if (!new_node)
		free_and_exit(&head_a, stack_c);
	new_node->number = head_a->number;
	new_node->index = head_a->index;
	if (*stack_c == NULL)
	{
		*stack_c = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		head_c = new_node;
	}
	else
	{
		new_node->prev = head_c->prev;
		new_node->next = head_c;
		head_c->prev->next = new_node;
		head_c->prev = new_node;
	}
}

void	stack_info(t_stack **stack_a, t_stack **stack_c)
{
	t_stack	*head_a;
	t_stack	*head_c;

	head_a = *stack_a;
	head_c = NULL;
	if (head_a == NULL)
		return ;
	while (head_a != *stack_a || head_c == NULL)
	{
		stack_info_cont(head_a, stack_c);
		head_a = head_a->next;
		head_c = *stack_c;
		sort_stack_c(stack_c);
	}
}

void	sort_rest(t_stack **stack_a, t_stack **stack_b,
			t_stack **stack_c, int argc)
{
	stack_info(stack_a, stack_c);
	goal_a(stack_a, stack_c, argc);
	algorithm(stack_a, stack_b, stack_c);
	(*stack_b) = NULL;
}
