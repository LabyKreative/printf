#include "main.h"
#include <stdio.h>

/**
 * _spec_p - sends va_arg with appropirate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */

void _spec_p(buffer *b_r, tags __attribute__((unused))(*t))
{
	size_t hold;
	char *s;
	int i;

	s = va_arg(b_r->ap, void *);

	if (s == NULL)
	{
		s = "(nil)";
		for (i = 0; s[i] != '\0'; i++)
			_write(b_r, s[i]);
	}
	else
	{
		hold = (size_t)s;
		s = _uint_to_hexstr(hold);

		_write(b_r, '0');
		_write(b_r, 'x');

		for (i = 0; s[i] != '\0'; i++)
			_write(b_r, s[i]);
		free(s);
	}
}
