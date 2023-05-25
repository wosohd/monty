#include "monty.h"

/**
 * f_push - pushes an element onto top of the stack
 * @stack: pointer to the top stack
 * @line_number: The current working line number of a Monty bytecodes file
 * @temp: Pointer to instruction
 */
void f_push(stack_t **stack, unsigned int line_number, char *temp)
{

	stack_t *new_top;

	(void)line_number;

	if (temp == NULL || _isdigit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(temp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			f_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_top->n = atoi(temp);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	*stack = new_top;
}


/**
 *  _isdigit - discovers if char is a digit or not
 *
 *  @str: Char passed in
 *
 *  Return: 1 for digit, otherwise 0
 */

int _isdigit(char *str)
{

	int j = 0;


	if (str[j] == '-')
	{
		j++;
	}
	while (str[j] != '\0')
	{
		if (!isdigit(str[j]))
		{
			return (1);
		}
		j++;
	}

	return (0);
}
