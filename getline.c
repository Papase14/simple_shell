#include "shell.h"

/**
 * getline - Reads input from stream
 * @Stream: stream to read from
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: Number of bytes read
 */
char *getline(FILE *stream)
{
	static ssize_t buffersize = 120; /* Minimum size for a line buffer*/
	size_t this_char = 0;

	if (stream == NULL)
		return NULL;

	char *line = malloc(buffersize);

	if (line == NULL)
		return NULL;

	int c;

	do
	{
		c = fgetc(stream);

			if (this_char + 1 >= buffersize)
			{
				buffersize = 2 * buffersize;

				char *next_linebuffer;
				next_linebuffer = realloc (line, buffersize);
				if (next_linebuffer == NULL)
				{
					free(line);
					line = NULL;
					break;
				}

				line = next_linebuffer;
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
