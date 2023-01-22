#include "main.h"

/**
 * _uint_to_str - convert an int into it's absolute value string
 * @n: number to convert
 *
 * Return: string to string'ed number
 */
char *_uint_to_str(unsigned long int n)
{
	char *s;
	unsigned int i;

	i = 0;
	s = malloc(21 * sizeof(char));

	if (n == 0)
		s[i] = '0';
	while (n != 0)
	{

		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
/**
 * _uint_to_hexstr - convert a long int into a hex string
 * @n: int to convert to hex
 *
 * Return: string to string'ed number
 */
char *_uint_to_hexstr(unsigned long int n)
{
	char *s;
	unsigned int tmp, i;

	i = 0;
	s = malloc(21 * sizeof(char));

	while (n != 0)
	{
		tmp = n % 16;
		/* convert int to char */
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		s[i++] = tmp;
		n /= 16;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
/**
 * _uint_to_caphexstr - convert a long int into a hex string
 * @n: int to convert to hex
 *
 * Return: string to string'ed number
 */
char *_uint_to_caphexstr(unsigned long int n)
{
	char *s;
	unsigned int tmp, i;

	i = 0;
	s = malloc(21 * sizeof(char));

	while (n != 0)
	{
		tmp = n % 16;
		/* convert int to char */
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'A' - 10;
		s[i++] = tmp;
		n /= 16;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
/**
 * _uint_to_octstr - convert a long int into a oct string
 * @n: int to convert to hex
 *
 * Return: string to string'ed number
 */
char *_uint_to_octstr(unsigned long int n)
{
	char *s;
	unsigned int tmp, i;

	i = 0;
	s = malloc(30 * sizeof(char));

	while (n != 0)
	{
		tmp = n % 8;
		/* convert int to char */
		if (tmp < 8)
			tmp += '0';
		s[i++] = tmp;
		n /= 8;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
/**
 * _uint_to_binstr - convert a long int into a bin string
 * @n: int to convert to hex
 *
 * Return: string to string'ed number
 */
char *_uint_to_binstr(unsigned long int n)
{
	char *s;
	unsigned int tmp, i;

	i = 0;
	s = malloc(65 * sizeof(char));

	while (n != 0)
	{
		tmp = n % 2;
		/* convert int to char */
		if (tmp < 2)
			tmp += '0';
		s[i++] = tmp;
		n /= 2;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
