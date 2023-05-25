#include "monty.h"
/**
 * mon_pop -  Removes the top value element of a stack_t linked list
 * @head: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
 * 
*/
void mon_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
