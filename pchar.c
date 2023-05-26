#include "monty.h"
/**
 * mon_pchar -  Prints the character in the top value
 *               node of a stack_t linked list
 * @head: pointer to the top mode node of a stack_t linked list.
 * @line_number: current working line number
*/
void mon_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
