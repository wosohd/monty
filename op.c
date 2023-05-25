#include "monty.h"

/**
 * go - Operators
 *
 * @op_f: Char pointer
 * @l: line
 * @stak: stack
 *
 */


void (*go(char *op_f, unsigned int l, stack_t **stak))(stack_t**, unsigned int)
{
	int count;

	instruction_t operation[] = {
		{"pall", f_pall},
		{"add", f_add},
		{"pint", f_pint},
		{"swap", f_swap},
		{"pop", f_pop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"nop", f_nop},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{NULL, NULL}
	};

	for (count = 0; operation[count].opcode != NULL; count++)
	{
		if (strcmp(operation[count].opcode, op_f) == 0)
		{
			return (operation[count].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	f_free(*stak);
	exit(EXIT_FAILURE);
}
