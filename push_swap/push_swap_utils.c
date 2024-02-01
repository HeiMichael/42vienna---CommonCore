/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:58:48 by miheider          #+#    #+#             */
/*   Updated: 2024/01/30 14:08:11 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok(char *s1, const char *delim, long *numbers)
{
	static char	*str;
	char		*start;

	if (s1)
		str = s1;
	if (!str)
		return (0);
	while (*str && ft_strchr(delim, *str))
		str++;
	if (*str == '\0')
		return (0);
	start = str;
	while (*str && !ft_strchr(delim, *str))
		str++;
	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}
	length_of_token(start, numbers);
	return (start);
}

void	append_list(t_stack **stack, t_stack *new_node)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	if (NULL == *stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		temp = head;
		while (temp->next != head)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = head;
		temp->next = new_node;
		head->prev = new_node;
	}
}

void	swap_numbers(t_stack *i, t_stack *j)
{
	int	temp;

	temp = i->number;
	i->number = j->number;
	j->number = temp;
}
