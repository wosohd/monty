#include "monty.h"

/**
 *  f_free - Free stack
 *
 *  @stack: Stack pointer
 *
 *  Return: Void
 */


void f_free(stack_t *stack)
{
	if (stack)
	{
		f_free(stack->next);
		free(stack);
	}
}
