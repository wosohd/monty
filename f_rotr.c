#include "monty.h"

/**
 *  get_rotr - Rotates the bottom value of a stack_t linked list to the top
 *  @stack: Stack
 *  @line_number: The current working line number
 *
 */
void f_rotr(stack_t **stack, unsigned int line_number)
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
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}
