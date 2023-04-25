#include "shell.h"

/**
 * get_line - Reads input from stream
 * @stream: stream to read from
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: Number of bytes read
 */
char *get_line(FILE *stream)
{
	static size_t buffersize = MAX_LENGTH; /* Minimum size for a line buffer*/
	size_t this_char = 0;
	char *next_linebuffer;
	char *line = malloc(buffersize);
	int c;

	if (stream == NULL)
	{
		return (NULL);
	}
	if (line == NULL)
	{
		return (NULL);
	}

	do {
		c = fgetc(stream);
		if (this_char + 1 >= buffersize)
		{
			buffersize = 2 * buffersize;

			next_linebuffer = realloc(line, buffersize);
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

/**
 * *_strspn - gets the length of a prefix substring
 * @s: string to evaluate
 * @accept: string containing the list of characters to match in s
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, f = 0, flag;

	for (i = 0; s[i] != '\0'; i++)
	{
		flag = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				f++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return (f);
		}
	}
	return (0);
}

/**
  * _strcspn - Find the positing where the delim is found in the string.
  * @s: String.
  * @delim: Delimiter.
  * Return: the position in the string.
  */
int _strcspn(char *s, const char *delim)
{
	int counter = 0, i;

	while (*s)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				return (counter);
		}
		counter++;
		s++;
	}
	return (counter);
}
