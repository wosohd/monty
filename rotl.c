#include "monty.h"
/**
  *mon_rotl- Rotates the top value of a stack_t linked list to the bottom
  *@head: pointer to the top mode node
  *@line_number: current working line number
 */
void mon_rotl(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
