#include "shell.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string followed by newline
 * @str: pointer to string
 *
 * Return: void.
 */
void _puts(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		i++;
		str++;
	}
}

/**
 * _atoi - converts a string to an integer.
 * @s: pointer to string.
 *
 * Return: integer gotten.
 */
int _atoi(char *s)
{
	int index, ind2;
	unsigned int res;
	int sign = 1;
	char now;

	index = 0;
	res = 0;
	while (*(s + index) != '\0')
	{
		now = *(s + index);
		if (now == '-')
		{
			sign *= -1;
		}
		if (now >= '0' && now <= '9')
		{
			ind2 = index;
			while (*(s + ind2) > 47 && *(s + ind2) < 58)
			{
				res = (res * 10) + *(s + ind2) - '0';
				ind2++;
			}
			break;
		}
		index++;
	}
	if (sign < 0)
		res *= sign;
	return (res);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 is strings are equal else, defference between strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, R;

	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	R = s1[i] - s2[i];
	return (R);
}

/**
  * _strncmp - String comaprison.
  * @s1: string 1
  * @s2: string 2
  * @n: number of bytes
  * Return: 0 if equal diff if different.
  */
int _strncmp(const char *s1, const char *s2, int n)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	int n4;

	if (n >= 4)
	{
		n4 = n >> 2;
		do {
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
		} while (--n4 > 0);
		n &= 3;
	}
	while (n > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}