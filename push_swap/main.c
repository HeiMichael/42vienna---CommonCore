/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:49:08 by miheider          #+#    #+#             */
/*   Updated: 2023/12/15 21:45:08 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_min_max(t_stack **stack_a, long *arg, int argc)
{
	int		i;
	long 	min;
	t_stack *head;

	min = arg[0];
	i = 1;
	while (i < argc)
	{
		if (arg[i] < min)
				min = arg[i];
		i++;
	}
	ft_printf("Minimum==%d\n\n", min);
	head = *stack_a;
	i = 0;
	while (i < argc)
	{
		if (head->number == min)
		{
			head->min = 1;
			ft_printf("+++head->number=%d --- %d\n", head->number, head->min);
			break;
		}
		head = head->next;
		i++;
	}
}


void init_stack(t_stack **stack_a, long *arg, int argc)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < argc)
	{
		new_node = (t_stack *)ft_calloc(1, sizeof(*new_node));
		if (NULL == new_node)
			exit (3);
		new_node->number = arg[i];
		new_node->index = i;
		if (NULL == *stack_a)					//add_first
		{
			*stack_a = new_node;
			new_node->next = new_node;
			new_node->prev = new_node;
		}
		else
			append_list(stack_a, new_node);
		i++;
	}
	find_min_max(stack_a, arg, argc);
}

int main(int argc, char **argv)
{
	long	*arg;
	t_stack *stack_a;
	t_stack	*stack_b;
//	t_stack	*stack_c;

	stack_a = NULL;
	stack_b = NULL;
//	stack_c = NULL;
	check_args(argc, argv);
	argc = argc - 1;
	if (argc == 1)
		arg = check_input_str(argv + 1, &argc);
	else
		arg = check_input(argc, argv + 1);
	init_stack(&stack_a, arg, argc);
	if (argc == 2)
		sa(&stack_a);
	if (argc == 3)
        sort_three(&stack_a);
	if (argc == 4)
		sort_four(&stack_a, &stack_b);
	if (argc == 5)
		sort_five(&stack_a, &stack_b);


	ft_printf("Argumente: %d\n", argc);
	int i = 0;
	while (i < argc)
	{
		ft_printf("Array an Stelle %d = %d\n", i, arg[i]);
		i++;
	}
	ft_printf("Done!\n");

	t_stack	*current = stack_a;
	while (1)
	{
		int i = 0;
        ft_printf("stack:a[i] = %d --- ", current->number);
	    ft_printf("Das Minimum im Stack ist: %d\n", current->min);
        current = current->next;

        if (current == stack_a)
            break;
		i++;
	}
	if (stack_b)
	{
	t_stack	*current = stack_b;
	while (1)
	{
		int i = 0;
        ft_printf("stack_b[i] = %d\n", current->number);
        current = current->next;

        if (current == stack_b)
            break;
		i++;
	}
	}
//	init_stacks((argc - 1), (argv - 1), &stack_a, &stack_c);
/*	get_numbers(argc, argv, &stack_a, &stack_c);
	if (total->total_len == 3)
		sorting_three(&stack_a, &stack_c, &total);

*/


/*
	1. checken ob Liste bereits sortiert ist!
	2. checken wie viele Elemente:	a) wenn 3 --> sort3
									b) wenn 5 --> sort5
									c) wenn mehr --> fetter Algo
	setup_array()	//setup the stacks and basic calc (numbers of elements/already sorted...)
		switch to corr sorting path (3, 5 or more members)
*/
//	free(stack_a);
//	free(stack_b);
//	free(stack_c);
	free(stack_a);
	free(arg);
	return (0);
}
