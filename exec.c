#include "monty.h"
/**
* execute - executes the opcode in the file
* @stack: head linked stack list
* @line_number: The current working line number
* @file: poiner to monty file
* @content: content in current working line
*/
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
				{"push", mon_push}, {"pall", mon_pall}, {"pint", mon_pint},
				{"pop", mon_pop},
				{"swap", mon_swap},
				{"add", mon_add},
				{"nop", mon_nop},
				{"sub", mon_sub},
				{"div", mon_div},
				{"mul", mon_mul},
				{"mod", mon_mod},
				{"pchar", mon_pchar},
				{"pstr", mon_pstr},
				{"rotl", mon_rotl},
				{"rotr", mon_rotr},
				{"queue", mon_queue},
				{"stack", mon_stack},
				{NULL, NULL}
				};
	unsigned int x = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[x].opcode && op)
	{
		if (strcmp(op, opst[x].opcode) == 0)
		{	opst[x].f(stack, line_number);
			return (0);
		}
		x++;
	}
	if (op && opst[x].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
