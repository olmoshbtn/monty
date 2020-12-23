#include "monty_viejo.h"

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
        char * line_buf = NULL;
        size_t line_buf_size;
        int line_count = 0;
        ssize_t line_size;
        char **op_env = NULL;

        if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (!freopen(argv[1], "r", stdin))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

        while ((line_size = getline(&line_buf, &line_buf_size, stdin)) != -1)
        {
                op_env = tokenize(line_buf);
                if (op_env && **op_env != '#')
                        printf("exito! %c\n", **op_env);

                line_count++;
                printf("line[%06d]: chars=%06ld, buf size=%06lu, contents: %s\n", line_count,
                line_size, line_buf_size, line_buf);
        }
        
	printf("No hay errores de lectura\n");
	/* Free the allocated line buffer */
        free(line_buf);
        line_buf = NULL;
        return (EXIT_SUCCESS);
}
