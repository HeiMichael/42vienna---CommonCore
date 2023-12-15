/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:16:20 by miheider          #+#    #+#             */
/*   Updated: 2023/12/14 23:22:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <complex.h>

/*
void    print_situation(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *current_b;

}
*/
void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->next->number
		> (*stack_a)->prev->number)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->number > (*stack_a)->prev->number && (*stack_a)->prev->number > (*stack_a)->next->number)
		ra(stack_a);
	else if ((*stack_a)->number < (*stack_a)->prev->number && (*stack_a)->next->number > (*stack_a)->prev->number)
	{
			rra(stack_a);
			sa(stack_a);
	}
	else if ((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->prev->number > (*stack_a)->number)
		sa(stack_a);
	else if ((*stack_a)->number < (*stack_a)->next->number && (*stack_a)->next->number < (*stack_a)->prev->number)
		return ;
	else
		rra(stack_a);
	ft_printf("+++head->number=%d --- %d\n", (*stack_a)->number, (*stack_a)->min);
}

void    sort_four(t_stack **stack_a, t_stack **stack_b)
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
	else if ((*stack_b)->number > (*stack_a)->number && ((*stack_b)->number < ((*stack_a)->next->number)))
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if (((*stack_b)->number < ((*stack_a)->prev->number)) && ((*stack_b)->number > (*stack_a)->next->number))
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if (((*stack_b)->number < (*stack_a)->number) || ((*stack_b)->number > (*stack_a)->prev->number))
		pa(stack_a, stack_b);
	else if (((*stack_b)->number > (*stack_a)->number) && ((*stack_b)->number
		< (*stack_a)->next->number))
	{
		ra(stack_a);
		pa(stack_a, stack_a);
	}
	else if (((*stack_b)->number > (*stack_a)->next->number && (*stack_b)->number < (*stack_a)->prev->number))
	{
		rra(stack_a);
		pa(stack_a, stack_b);
	}
	if (((*stack_b)->number < (*stack_a)->number) && ((*stack_b)->number		> (*stack_a)->prev->number))
		pa(stack_a, stack_b);



}







































/*{
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	if ((*stack_b)->number < (*stack_a)->number)
		pa(stack_a, stack_b);
	else if (((*stack_b)->number > (*stack_a)->number) && ((*stack_b)->number < (*stack_a)->next->number))
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if (((*stack_b)->number > (*stack_a)->next->next->number) && (*stack_b)->number < (*stack_a)->prev->prev->number)
	{
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else if (((*stack_b)->number > (*stack_a)->prev->prev->number) && (*stack_b)->number < (*stack_a)->prev->number)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if((*stack_b)->number > (*stack_a)->prev->number)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}*/
