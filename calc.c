#include "main.h"

/**
 * __atoi - take string, and find number the starts at point n
 * @s: string to read
 * @n: position to begin reading number
 *
 * Return: Number parsed
 */
int __atoi(const char *s, int n)
{
	int number, i;

	i = number = 0;
	while (s[n + i] <= '9' && s[n + i] >= '0')
	{
		if (i > 0)
			number *= 10;
		number += s[n + i] - '0';
		i++;
	}
	return (number);
}

/**
 * str_len - find the str len
 * @str: a pointer to a str
 *
 * Return: length of string
 */
int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _revstr - find the str len
 * @s: a pointer to a str
 *
 * Return: length of string
 */
void _revstr(char *s)
{
	int len, i;
	char tmp;

	i = 0;
	len = str_len(s) - 1;
	while (i <= len / 2)
	{
		tmp = s[len - i];
		s[len - i] = s[i];
		s[i++] = tmp;
	}
}
