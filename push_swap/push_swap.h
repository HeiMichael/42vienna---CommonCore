/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:16 by miheider          #+#    #+#             */
/*   Updated: 2023/12/15 21:47:55 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <unistd.h>			//exit
#include <stdio.h>			//sizeof
#include <stdlib.h>			//exit
#include <stddef.h>			//NULL

typedef struct s_stack
{
	int				number;
	int				index;
	int				goal;
	int				stack_len;
	int				min;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);

//checker functions - checking input
long	*check_input(int argc, char **argv);
long	*check_input_str(char **argv, int *argc);
void	check_number(int *number);
void 	check_duplicate(const long *numbers, int count, long number);
void 	check_args(int argc, char **argv);
void	is_sorted(long *numbers, int size);
void	find_min_max(t_stack **stack_a, long *arg, int argc);
void	sort_three(t_stack **stack_a);
void    sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	swap_values(int *value_one, int *value_two);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//error
char	error_message(int error);

//utilizer functions
long	ft_atol(const char *nptr);
char 	*ft_strtok(char *s1, const char *delim);
void	length_of_token(char *token);
int		input_len(char **argv);
void	append_list(t_stack **stack, t_stack *new_node);
//void	get_numbers(int argc, char **argv, t_stack **stack_a, int *stack_c);
//void	sorted_dupc(t_stack **stack_a, int *stack_c, int size);
//void	sort_stack_c(int *stack_c, int size);
//void	sorting_three(t_stack **stack_a, int **stack_c);
//void	check_if_finished(t_stack **a_stack, int **stack_c);


#endif
