#include "monty.h"

/**
 * f_rotl - Rotates the top value of a stack_t linked list to the bottom
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number
 * 
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		*stack = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}
