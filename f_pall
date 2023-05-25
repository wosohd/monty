#include "monty.h"

/**
 * f_pall - prints all elements on the stack
 * @stack: pointer to head of stack
 * @line_number: The current working line number of a Monty bytecodes file
 */

void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}
