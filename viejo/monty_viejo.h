#ifndef MONTY_VIEJO_H
#define MONTY_VIEJO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

/* Structures */

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

typedef void (*instruction_fn)(stack_t **stack);

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
        instruction_fn fn;
} instruction_t;

/**
 * enum stack_mode_n - stack mode enumeration
 * @LIFO: operate as a stack
 * @FIFO: operate as a queue
 */
typedef enum stack_mode_n
{
	LIFO = 0,
	FIFO = 1
} stack_mode_t;

/**
 * struct op_env_s - operation environment
 * @sp: top of the stack
 * @argv: argument vector
 * @line: line buffer
 * @linesz: line buffer size
 * @lineno: line number
 */
typedef struct op_env_s
{
	stack_t *sp;
	char **argv;	/*op_env*/
	char *line;		/*line_buf*/ 
	size_t linesz;	/*line_buf_size*/
	size_t lineno; 	/*line_count*/
} op_env_t;

/* Global variables */

extern op_env_t op_env;

/* Main functions */

int main(int argc, char **argv);
char **tokenize(char *str);
size_t count_tokens(const char *str);
instruction_fn get_instruction_fn(const char *opcode);
void free_op_env(void);
void free_stack(stack_t **sp);

/* Opcode functions */

void op_add(stack_t **sp);
void op_nop(stack_t **sp __attribute__((unused)));
void op_pall(stack_t **sp);
void op_pint(stack_t **sp);
void op_pop(stack_t **sp);
void op_push(stack_t **sp);
void op_swap(stack_t **sp);

#endif