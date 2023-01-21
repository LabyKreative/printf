#include "main.h"

/**
 * _spec_nil - sends t.scanned into buffer
 * @b_r: a pointer to the buffer
 */

void _spec_nil(buffer *b_r)
{
	int i;

	/* if we started parsing but found end of format, print nothing */
	if (b_r->format[b_r->fp] != '\0')
	{
		for (i = 0; i < b_r->tp; i++)
			_write(b_r, b_r->tmpbuf[i]);
	}
	b_r->tp = 0;
}
