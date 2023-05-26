#include "monty.h"
/**
 * mon_pstr - Prints the string contained in a stack_t linked list
 * @head: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
*/
void mon_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
