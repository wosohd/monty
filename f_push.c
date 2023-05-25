#include "monty.h"
/**
 * mon_push - Pushes a value to a stack_t linked list.
 * @stack: pointer to the top mode node
 * @line_number: The current working line number
 */
void mon_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int x;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
