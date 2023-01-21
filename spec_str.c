#include "main.h"

/**
 * _spec_s - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_s(buffer *b_r, tags *t)
{
	char *hold;
	char *b_str;
	int i, j, l, b_str_size, hold_len;
	/* get arg from va_arg and store */
	hold = va_arg(b_r->ap, char *);
	if (hold == NULL)
		hold = "(null)";
	i = l = 0;
	/*check the precision tag*/
	hold_len = str_len(hold);
	/* if prec is found, ignore width */
	if (t->prec != -1 && t->prec < hold_len)
		hold_len = t->prec;
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str = _str_whelp(t, hold, hold_len);
		b_str_size = t->width;
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = hold[i], i++;
	}
	for (j = 0; j < b_str_size; j++)
		_write(b_r, b_str[j]);
	free(b_str);
}
/**
 * _spec_S - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_S(buffer *b_r, tags *t)
{
	char *hold, *holds;
	char *b_str;
	int i, j, l, b_str_size, hold_len;
	/* get arg from va_arg and store */
	hold = va_arg(b_r->ap, char *);
	i = l = 0;
	holds = hold;
	holds = _to_hex_unreadable(hold);
	/*check the precision tag*/
	hold_len = str_len(holds);
	/* if prec is found, ignore width */
	if (t->prec != -1 && t->prec < hold_len)
		hold_len = t->prec;
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str = _str_whelp(t, holds, hold_len);
		b_str_size = t->width;
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = holds[i], i++;
	}
	for (j = 0; j < b_str_size; j++)
		_write(b_r, b_str[j]);
	free(b_str);
	free(holds);
}
/**
 * _str_whelp - sends va_arg with appropriate tags into buffer
 * @t: a pointer to the struct tags
 * @hold: string pulled from va_arg
 * @hold_len: length of hold after precision cut
 *
 * Return: Pointer to b_str
 */
char *_str_whelp(tags *t, char *hold, int hold_len)
{
	int i, b_str_size, minus, k, l;
	char *b_str;

	minus = i = k = l = 0;
	b_str_size = t->width;
	b_str = malloc((b_str_size) * sizeof(char *));
	/*if - flag is found */
	for (k = 0; t->flags[k] != '\0'; k++)
	{
		if (t->flags[k] == '-')
			minus = 1;
	}
	/*- flag found, hold left most */
	if (minus == 1)
	{
		while (i < hold_len)
			b_str[i] = hold[i], i++;
		while (i < b_str_size)
			b_str[i++] = ' ';
	}
	/* - flag not found, hold right most*/
	else
	{
		while (i < b_str_size - hold_len)
			b_str[i++] = ' ';
		while (i < b_str_size)
			b_str[i++] = hold[l++];
	}
	return (b_str);
}
/**
 * _to_hex_unreadable - sends va_arg with appropriate tags into buffer
 * @hold: string to convert
 *
 * Return: Pointer to edited string
 */
char *_to_hex_unreadable(char *hold)
{
	char *holdconv, *hexhold;
	int i, j;

	i = j = 0;
	holdconv = malloc(1024);
	while (hold[i] != '\0')
	{
		if (hold[i] >= 32 && hold[i] <= 126)
			holdconv[j++] = hold[i];
		else
		{
			holdconv[j++] = '\\';
			holdconv[j++] = 'x';
			hexhold = _int_to_caphexstr(hold[i]);
			if (hexhold[1] == '\0')
			{
				holdconv[j++] = '0';
				holdconv[j++] = hexhold[0];
			}
			else
			{
				holdconv[j++] = hexhold[0];
				holdconv[j++] = hexhold[1];
			}
			free(hexhold);
		}
		i++;
	}
	holdconv[j] = '\0';
	return (holdconv);
}
