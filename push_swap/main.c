/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:49:08 by miheider          #+#    #+#             */
/*   Updated: 2024/01/30 13:36:32 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_stack **stack_a, long *arg, int argc)
{
	int		i;
	long	min;
	t_stack	*head;

	min = arg[0];
	i = 1;
	while (i < argc)
	{
		if (arg[i] < min)
			min = arg[i];
		i++;
	}
	head = *stack_a;
	i = 0;
	while (i < argc)
	{
		if (head->number == min)
		{
			head->smin = 1;
			break ;
		}
		head = head->next;
		i++;
	}
}

void	init_stack(t_stack **stack_a, long *arg, int argc)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < argc)
	{
		new_node = (t_stack *)ft_calloc(1, sizeof(*new_node));
		if (NULL == new_node)
		{
			free(arg);
			free_stack(stack_a);
			exit (1);
		}
		new_node->number = arg[i];
		new_node->index = i;
		new_node->stack = 1;
		new_node->total = argc;
		append_list(stack_a, new_node);
		i++;
	}
	find_min_max(stack_a, arg, argc);
}

void	sort(int argc, t_stack **stack_a, t_stack **stack_b, t_stack **stack_c)
{
	if (argc == 2)
		sa(stack_a);
	if (argc == 3)
		sort_three(stack_a);
	if (argc == 4)
		sort_four(stack_a, stack_b);
	if (argc == 5)
		sort_five(stack_a, stack_b);
	if (argc > 5)
		sort_rest(stack_a, stack_b, stack_c, argc);
}

int	main(int argc, char **argv)
{
	long	*arg;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;

	stack_a = NULL;
	stack_b = NULL;
	stack_c = NULL;
	if (argc == 1)
		return (0);
	check_args(argc, argv);
	argc = argc - 1;
	if (argc == 1)
		arg = check_input_str(argv + 1, &argc);
	else
		arg = check_input(argc, argv + 1);
	init_stack(&stack_a, arg, argc);
	free(arg);
	sort(argc, &stack_a, &stack_b, &stack_c);
	free_stack(&stack_a);
	free_stack(&stack_c);
	return (0);
}
