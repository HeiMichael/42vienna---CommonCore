

#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *head_b;
    t_stack *last_a;

    if (*stack_b != NULL)
	{
        head_b = *stack_b;
        if (head_b->next == head_b)
            *stack_b = NULL; // If head_b is the only element in stack_b
	    else
		{
            head_b->prev->next = head_b->next;
            head_b->next->prev = head_b->prev;
            *stack_b = head_b->next; // Update stack_b to the next node
        }
        if (*stack_a == NULL) {
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
            *stack_a = head_b; // Update stack_a to head_b
        }
        printf("pa\n");
    }
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *head_a;
    t_stack *last_b;

    if (*stack_a != NULL)
	{
        head_a = *stack_a;
        // Removing head_a from stack_a
        if (head_a->next == head_a)
		{
            *stack_a = NULL; // If head_a is the only element in stack_a
        }
		else
		{
            head_a->prev->next = head_a->next;
            head_a->next->prev = head_a->prev;
            *stack_a = head_a->next; // Update stack_a to the next node
        }
        if (*stack_b == NULL)
		{
            *stack_b = head_a;
            head_a->next = head_a;
            head_a->prev = head_a;
        }
		else
		{
            last_b = (*stack_b)->prev;
            // Inserting head_a into stack_b
            head_a->next = *stack_b;
            head_a->prev = last_b;
            (*stack_b)->prev = head_a;
            last_b->next = head_a;
            *stack_b = head_a; // Update stack_b to head_a
        }
        printf("pb\n");
    }
}