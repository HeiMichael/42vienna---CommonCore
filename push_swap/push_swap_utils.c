/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:58:48 by miheider          #+#    #+#             */
/*   Updated: 2023/12/12 19:58:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_strtok(char *s1, const char *delim)
{
	static char *str;
	char		*start;

	if (s1)
        str = s1;
    if (!str)
        return (0);
    while (*str && ft_strchr(delim, *str))						//skipping delimiters
        str++;
    if (*str == '\0')										//if end of string is reached
        return (0);
    start = str;
	while (*str && !ft_strchr(delim, *str))					//finding end of token
        str++;
    if (*str != '\0')
	{
        *str = '\0'; 					// Replace delimiter with null terminator temporarily
        str++;
	}
	length_of_token(start);
    return (start); 										// Return the start of the token
}

void	append_list(t_stack **stack, t_stack *new_node)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
//	if (NULL == *stack)
//	{
//		*stack = new_node;
//		new_node->next = new_node;
//		new_node->prev = new_node;
//	}
//	else
//	{
		temp = head;
		while (temp->next != head)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = head;
		temp->next = new_node;
		head->prev = new_node;
//	}
}
/*
void	sort_stack_c(int *stack_c, int size)
{
	int	temp;
	int i;

	i = 0;
	while (i < (size - 1))
	{
		if (stack_c[i] > stack_c[i + 1])
		{
			temp = stack_c[i];
			stack_c[i] = stack_c[i + 1];
			stack_c[i + 1] = temp;
		}
		else
			i++;
	}
}

void	sorted_dupc(t_stack **stack_a, int *stack_c, int size)
{
	t_stack	*head_a;
	int		i;

	(stack_c) = (int *)ft_calloc(size, sizeof(int));

	head_a = (*stack_a);
	i = 0;
	while (head_a->next != *stack_a)
	{
		stack_c[i] = head_a->number;
		head_a = head_a->next;
		i++;
	}
	sort_stack_c(stack_c, i);
}
	*/
