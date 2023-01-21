#include "main.h"

/**
 * _spec_r - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_r(buffer *b_r, tags *t)
{
	char *hold, *holdr;
	char *b_str;
	int i, j, l, b_str_size, hold_len;

	hold = va_arg(b_r->ap, char *);
	if (hold == NULL)
	{
		hold = "(null)";
		for (j = 0; j < 6; j++)
			_write(b_r, hold[j]);
	}
	else
	{
		i = l = 0, holdr = malloc(1024);
		while (hold[i] != '\0')
			holdr[i] = hold[i], i++;
		holdr[i] = '\0';
		_revstr(holdr);
		i = 0;
		hold_len = str_len(holdr);
		if (t->prec != -1 && t->prec < hold_len)
			hold_len = t->prec;
		if (t->width > hold_len)
		{
			b_str = _str_whelp(t, holdr, hold_len);
			b_str_size = t->width;
		}
		else
		{
			b_str_size = hold_len;
			b_str = malloc(b_str_size * sizeof(char));
			while (i < b_str_size)
				b_str[i] = holdr[i], i++;
		}
		for (j = 0; j < b_str_size; j++)
			_write(b_r, b_str[j]);
		free(b_str);
		free(holdr);
	}
}
/**
 * _spec_R - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_R(buffer *b_r, tags *t)
{
	char *hold, *holdr;
	char *b_str;
	int i, j, l, b_str_size, hold_len;

	hold = va_arg(b_r->ap, char *);
	if (hold == NULL)
	{
		hold = "(null)";
		for (j = 0; j < 6; j++)
		_write(b_r, hold[j]);
	}
	else
	{
		i = l = 0, holdr = malloc(1024);
		while (hold[i] != '\0')
			holdr[i] = hold[i], i++;
		holdr[i] = '\0';
		_to_rot13(holdr);
		i = 0;
		hold_len = str_len(holdr);
		if (t->prec != -1 && t->prec < hold_len)
			hold_len = t->prec;
		if (t->width > hold_len)
		{
			b_str = _str_whelp(t, holdr, hold_len);
			b_str_size = t->width;
		}
		else
		{
			b_str_size = hold_len;
			b_str = malloc(b_str_size * sizeof(char));
			while (i < b_str_size)
				b_str[i] = holdr[i], i++;
		}
		for (j = 0; j < b_str_size; j++)
			_write(b_r, b_str[j]);
		free(b_str);
		free(holdr);
	}
}
/**
 * _to_rot13 - rot13s given string
 * @s: string to rot13
 */
void _to_rot13(char *s)
{
	char key[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char kvalue[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, check;

	i = 0;
	while (s[i] != '\0')
	{
		check = 0;
		j = 0;
		while (key[j] != '\0')
		{
			if (key[j] == s[i] && check != 1)
			{
				s[i] = kvalue[j];
				check = 1;
			}
			j++;
		}
		i++;
	}
}
