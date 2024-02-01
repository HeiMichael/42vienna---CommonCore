/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:16 by miheider          #+#    #+#             */
/*   Updated: 2024/01/30 14:08:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>			//exit
# include <stdio.h>				//sizeof
# include <stdlib.h>			//exit
# include <stddef.h>			//NULL

typedef struct s_stack
{
	long			number;
	int				index;
	int				goal;
	int				stack;
	int				smin;
	int				smax;
	int				index_max;
	int				target;
	int				total_len;
	int				total;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
void	free_stack(t_stack **stack);

//checker functions - checking input
long	*check_input(int argc, char **argv);
long	*check_input_str(char **argv, int *argc);
void	goal_a(t_stack **stack_a, t_stack **stack_c, int argc);
void	check_duplicate(long *numbers, int count, long number);
void	check_args(int argc, char **argv);
void	is_sorted(long *numbers, int size);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	swap_nodes(t_stack **stack);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pb_cont(t_stack **stack_b, t_stack *head_a, t_stack *last_b);
void	pa_cont(t_stack **stack_a, t_stack *head_b, t_stack *last_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_rest(t_stack **stack_a, t_stack **stack_b, \
		t_stack **stack_c, int argc);
void	stack_info(t_stack **stack_a, t_stack **stack_c);
void	stack_info_cont(t_stack *head_a, t_stack **stack_c);
int		sorted_stack(t_stack **stack);
void	algorithm(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c);
int		stack_sorted(t_stack **stack);
void	index_stack(t_stack **stack, int x);
int		stack_len(t_stack **stack);
void	swap_numbers(t_stack *i, t_stack *j);
void	sort_stack_c(t_stack **stack_c);
void	init_stack(t_stack **stack_a, long *arg, int argc);
void	sort(int argc, t_stack **stack_a, t_stack **stack_b, t_stack **stack_c);

//error
char	error_message(int error, long *numbers);
void	free_and_exit(t_stack **stack_a, t_stack **stack_c);

//utilizer functions
long	ft_atol(const char *nptr, long *numbers);
char	*ft_strtok(char *s1, const char *delim, long *numbers);
void	length_of_token(char *token, long *numbers);
int		input_len(char **argv);
void	append_list(t_stack **stack, t_stack *new_node);

#endif
