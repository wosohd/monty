#include "monty.h"
/**
  *mon_sub- Subtracts the second value from the top of
 *             a stack_t linked list by the top value
  *@head: pointer to the top mode node of a stack_t linked list
  *@line_number: current working line number of a Monty bytecodes file
 */
void mon_sub(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
