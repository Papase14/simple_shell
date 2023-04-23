#include "shell.h"

/**
 * get_line - Reads input from stream
 * @Stream: stream to read from
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: Number of bytes read
 */
char* get_line(FILE *stream)
{
	static size_t buffersize = MAX_LENGTH; /* Minimum size for a line buffer*/
	size_t this_char = 0;
	char *next_linebuffer;
	char *line = malloc(buffersize);
	int c;

	if (stream == NULL)
		return NULL;

	if (line == NULL)
		return NULL;

	do
	{
		c = fgetc(stream);
		if (this_char + 1 >= buffersize)
		{
			buffersize = 2 * buffersize;

			next_linebuffer = realloc (line, buffersize);
			if (next_linebuffer == NULL)
			{
				free(line);
				line = NULL;
				break;
			} line = next_linebuffer;
		}
		if (c == EOF || c == '\n')
		{
			c = 0;
		}

		line[this_char++] = c;
	} while (c);

	line[this_char - 1] = '\0';
	return (line);

}
