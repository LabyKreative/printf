#include "main.h"
/**
 * _printf - Recreate stdio.h's printf
 * @format: Formatted string to write to stdout
 *
 * Return: Number of chars written
 */
int _printf(const char *format, ...)
{
	/* Create buffer structure b_r and initialise */
	buffer b_r;

	_init_buffer(&b_r, format);
	va_start(b_r.ap, format);

	/* Main loop to create buffer from format string */
	while (b_r.format[b_r.fp] != '\0')
	{
		_copy(&b_r);
		if (b_r.format[b_r.fp] != '\0')
			_parse(&b_r);
	}

	/* Write remaining buffer to stdout */
	if (b_r.bp > 0)
		write(1, b_r.buf, b_r.bp);
	b_r.printed += b_r.bp;

	va_end(b_r.ap);
	free(b_r.buf);
	free(b_r.tmpbuf);
	return (b_r.printed);
}
/**
 * _copy - directly copy from format to buffer
 * @b_r: the buffer structure
 */
void _copy(buffer *b_r)
{
	while (b_r->format[b_r->fp] != '%' && b_r->format[b_r->fp] != '\0')
		_write(b_r, b_r->format[b_r->fp++]);

}
/**
 * _parse - take string from % and parse tags into correct string for buffer
 * @b_r: the buffer structure
 */
void _parse(buffer *b_r)
{
	int i;
	tags t;
	parse_table table[] = {
	{'d', 5, _spec_d}, {'i', 5, _spec_d}, {'c', 5, _spec_c},
	{'s', 5, _spec_s}, {'u', 5, _spec_u}, {'o', 5, _spec_o},
	{'x', 5, _spec_x}, {'X', 5, _spec_X}, {'b', 5, _spec_b},
	{'S', 5, _spec_S}, {'p', 5, _spec_p}, {'R', 5, _spec_R},
	{'r', 5, _spec_r}, {'%', 5, _spec_pct},
	/* no specifier found */ {'\0', 5, _spec_nil},

	{'h', 4, error}, {'l', 4, error},
	{'.', 3, error},
	{'1', 2, error}, {'2', 2, error}, {'3', 2, error},
	{'4', 2, error}, {'5', 2, error}, {'6', 2, error},
	{'7', 2, error}, {'8', 2, error}, {'9', 2, error},
	{'-', 1, error}, {'+', 1, error}, {' ', 1, error},
	{'#', 1, error}, {'0', 1, error},
	/* End of Table */ {'\0', -1, error}
	};

	/* We only parse at %! */
	if (b_r->format[b_r->fp] != '%')
		write(1, "Error: Parsing when not at '%'\n", 31);
	b_r->tp = 0;
	b_r->tmpbuf[b_r->tp++] = '%';
	b_r->fp++;

	_init_tag(&t);
	_parse_tag(b_r, &t, table);

	/* Call the specifier function matching the specifier found */
	i = 0;
	while (table[i].level == 5)
	{
		if (table[i].c == t.spec)
			table[i].spec_func(b_r, &t);
		i++;
	}
	i = 0;
}
/**
 * _parse_tag - Build out the tags struct with tags found
 * @b_r: the buffer structure
 * @table: Parsing table to read the '%_' from format
 * @t: tags to send to our specifier function
 */
void _parse_tag(buffer *b_r, tags *t, parse_table *table)
{
	int depth, i, j;

	depth = i = j = 0;
	while (table[i].level > depth || table[i].level == 1)
	{
		if (table[i].c == b_r->format[b_r->fp])
		{
			depth = table[i].level;
			if (depth == 5)
				_found_spec(b_r, t, table, i);
			else if (depth == 4)
				_found_length(b_r, t, table, i);
			else if (depth == 3)
				_found_prec(b_r, t, table, i);
			else if (depth == 2)
				_found_width(b_r, t);
			else if (depth == 1)
				_found_flag(b_r, t, table, i);
			i = -1;
		}
		i++;
	}
}
