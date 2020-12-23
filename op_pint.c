#include "monty.h"

/**
 * op_pint - print the value at the top of the stack
 * @sp: stack pointer
 */
void op_pint(stack_t **sp)
{
	if (*sp)
		printf("%d\n", (*sp)->n);
	else
		print_fail("L%u: can't pint, stack empty\n", op_env.lineno);
}