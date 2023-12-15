/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:47:40 by miheider          #+#    #+#             */
/*   Updated: 2023/12/13 00:13:20 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(int *value_one, int *value_two)
{
	int	temp;

	temp = *value_one;
	*value_one = *value_two;
	*value_two = temp;
}

void	sa(t_stack **stack_a)
{
	t_stack *temp;

//	if ((*total)->stack_a_len >= 2)
//	{
        temp = *stack_a;
        swap_values(&((*stack_a)->number), &((*stack_a)->next->number));
        swap_values(&((*stack_a)->goal), &((*stack_a)->next->goal));
        *stack_a = temp;
        ft_printf("sa\n");
//   }
}

void	sb(t_stack **stack_b)
{
	t_stack *temp;

//	if ((*total)->stack_b_len >= 2)
//	{
        temp = *stack_b;
        swap_values(&((*stack_b)->number), &((*stack_b)->next->number));
        swap_values(&((*stack_b)->goal), &((*stack_b)->next->goal));
        *stack_b = temp;
        ft_printf("sb\n");
//    }
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp1;
	t_stack	*temp2;

//	 if (((*total)->stack_a_len >= 2) && ((*total)->stack_b_len >= 2))
//	 {
        temp1 = *stack_a;
        temp2 = *stack_b;
        swap_values(&((*stack_a)->number), &((*stack_a)->next->number));
        swap_values(&((*stack_a)->goal), &((*stack_a)->next->goal));
        *stack_a = temp1;
        swap_values(&((*stack_b)->number), &((*stack_b)->next->number));
        swap_values(&((*stack_b)->goal), &((*stack_b)->next->goal));
        *stack_b = temp2;
        ft_printf("ss\n");
//    }
}
