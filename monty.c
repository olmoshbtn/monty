#include "monty.h"

op_env_t op_env = {NULL, NULL, NULL, 0, 1, LIFO};

/**
 * main - doubly linked list representation of a stack (or queue)
 * @argc: argument count
 * @argv: array with the arguments values
 *
 * Return: If successful it returns EXIT_SUCCESS; otherwise,
 *         it returns EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	ssize_t n_read = 0;

	if (argc != 2)
		print_fail("USAGE: monty file\n");

	if (!freopen(argv[1], "r", stdin))
		print_fail("Error: Can't open file %s\n", argv[1]);

	atexit(free_op_env);

	while ((n_read = getline(&op_env.line, &op_env.linesz, stdin)) > 0)
	{
		op_env.argv = tokenize(op_env.line);

		if (op_env.argv && **op_env.argv != '#')
			get_instruction_fn(*op_env.argv)(&op_env.sp);

		free(op_env.argv);
		op_env.argv = NULL;
		op_env.lineno += 1;
	}
	return (EXIT_SUCCESS);
}
