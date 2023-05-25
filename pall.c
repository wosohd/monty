#include "monty.h"
/**
 * mon_pall -  Prints the values of a stack_t linked list
 * @head: pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
 * 
*/
void mon_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
