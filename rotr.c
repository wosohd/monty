#include "monty.h"
/**
  *mon_rotr- Rotates the bottom value of a stack_t linked list to the top
  *@head: pointer to the top mode node of a stack_t linked list
  *@line_number: current working line number of a Monty bytecodes file
 */
void mon_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
