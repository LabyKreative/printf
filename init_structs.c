#include "main.h"

/**
 * _init_tag - Initialize tag for parsing
 * @t: tags stuct to fill in with tags
 */
void _init_tag(tags *t)
{
	/* Initialize tag to default values*/
	t->spec = '\0';
	t->length = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0'; t->flags[5] = '\0';
}

/**
 * _init_buffer - Initialize the buffer structure
 * @b_r: copy of the buffer address
 * @format: copy of the format we will be parsing into buffer
 */
void _init_buffer(buffer *b_r, const char *format)
{
	b_r->format = format;
	b_r->buf = malloc(1024);
	b_r->tmpbuf = malloc(512);
	b_r->fp = 0;
	b_r->bp = 0;
	b_r->tp = 0;
	b_r->printed = 0;
}
