#include "monty.h"
/**
 * mon_mul -  Multiplies the second value from the top of
 *             a stack_t linked list by the top value
 * @head: pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file
*/
void mon_mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
