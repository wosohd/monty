#include "monty.h"

/**
 * f_pint - prints the top element on the stack
 * @stack: pointer to head of stack
 * @line_number: The current working line number of a Monty bytecodes file
 * 
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
