#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void mon_push(stack_t **head, unsigned int number);
void mon_pall(stack_t **head, unsigned int number);
void mon_pint(stack_t **head, unsigned int number);
void mon_pop(stack_t **head, unsigned int line_number);
void mon_swap(stack_t **head, unsigned int line_number);
void mon_add(stack_t **head, unsigned int line_number);
void mon_nop(stack_t **head, unsigned int line_number);
void mon_sub(stack_t **head, unsigned int line_number);
void mon_div(stack_t **head, unsigned int line_number);
void mon_mul(stack_t **head, unsigned int line_number);
void mon_mod(stack_t **head, unsigned int line_number);
void mon_pchar(stack_t **head, unsigned int line_number);
void mon_pstr(stack_t **head, unsigned int line_number);
void mon_rotl(stack_t **head, unsigned int line_number);
void mon_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

void mon_queue(stack_t **head, unsigned int line_number);
void mon_stack(stack_t **head, unsigned int );

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
int execute(char *content, stack_t **head, unsigned int line_number, FILE *file);
void free_stack(stack_t *head);







