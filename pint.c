#include "monty.h"
/**
 * mon_pint - Prints the top value of a stack_t linked list
 * @head: stack head
 * @line_number: The current working line number
*/
void mon_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
