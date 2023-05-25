#include "monty.h"
/**
 * mon_push - Pushes a value to a stack_t linked list
 * @head: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
*/
void mon_push(stack_t **head, unsigned int line_number)
{
	int n, x = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			x++;
		for (; bus.arg[x] != '\0'; x++)
		{
			if (bus.arg[x] > 57 || bus.arg[x] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
