#include "main.h"

/**
 * _found_spec - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void _found_spec(buffer *b_r, tags *t, parse_table *table, int i)
{
	t->spec = table[i].c;
	b_r->tmpbuf[b_r->tp++] = table[i].c;
	b_r->fp++;
}
/**
 * _found_length - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void _found_length(buffer *b_r, tags *t, parse_table *table, int i)
{
	t->length = table[i].c;
	b_r->tmpbuf[b_r->tp++] = table[i].c;
	b_r->fp++;
}
/**
 * _found_prec - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void _found_prec(buffer *b_r, tags *t, parse_table *table, int i)
{
	int tmp, j, len;
	char *s;

	b_r->fp++;
	b_r->tmpbuf[b_r->tp++] = table[i].c;
	tmp = t->prec = __atoi(b_r->format, b_r->fp);
	/* must include i to s here to put in t->scanned */
	s = _int_to_str(tmp);
	len = str_len(s);
	for (j = 0; j < len; j++)
		b_r->tmpbuf[b_r->tp++] = s[j];
	while (tmp)
	{
		tmp /= 10;
		b_r->fp++;
	}
	free(s);
}
/**
 * _found_width - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 */
void _found_width(buffer *b_r, tags *t)
{
	int tmp, j, len;
	char *s;

	tmp = t->width = __atoi(b_r->format, b_r->fp);
	/* must include i to s here to put in t->scanned */
	s = _int_to_str(tmp);
	len = str_len(s);
	for (j = 0; j < len; j++)
		b_r->tmpbuf[b_r->tp++] = s[j];
	while (tmp)
	{
		tmp /= 10;
		b_r->fp++;
	}
	free(s);
}
/**
 * _found_flag - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void _found_flag(buffer *b_r, tags *t, parse_table *table, int i)
{
	int j;

	b_r->tmpbuf[b_r->tp++] = table[i].c;
	j = 0;
	while (1)
	{
		if (table[i].c == '0')
		{
			if (t->flags[j] == '1')
				break;
		}
		else
		{
			if (t->flags[j] == table[i].c)
				break;
		}
		if (t->flags[j] == '\0')
		{
			if (table[i].c == '0')
				t->flags[j] = '1';
			else
				t->flags[j] = table[i].c;
			break;
		}
		j++;
	}
		b_r->fp++;
}
