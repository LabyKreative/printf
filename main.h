#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct buffer - buffer structure for our implimentation of printf
 * @buf: buffer to write characters
 * @tmpbuf: tmp buffer to write to before putting in buffer
 * @format: the string passed to our printf
 * @ap: the variadic address point
 * @bp: the current point in the buffer
 * @tp: the current point in the tmp buffer
 * @fp: the current point in the format
 * @printed: the number of chars printed from _write
 */
typedef struct buffer
{
	char *buf;
	char *tmpbuf;
	const char *format;
	va_list ap;
	int bp;
	int tp;
	int fp;
	unsigned int printed;
} buffer;

/**
 * struct tags - Format tags after %
 * @spec: the specifier
 * @length: the length
 * @prec: the precision
 * @width: the width
 * @flags: the flags
 */
typedef struct tags
{
	char spec;
	char length;
	int prec;
	int width;
	char flags[6];
} tags;

/**
 * struct parse_table - Table used for parsing the %s
 * @c: character found
 * @level: which level from 5 (specification) to 1 (flags)
 * @spec_func: function to put the matched specification into the buffer
 */
typedef struct parse_table
{
	char c;
	int level;
	void (*spec_func)();
} parse_table;

/* printf functions */
void _copy(buffer *);
int _printf(const char *format, ...);
void _parse(buffer *b_r);
void _init_tag(tags *t);
void _init_buffer(buffer *b_r, const char *format);
void _spec_c(buffer *b_r, tags *t);
void _spec_s(buffer *b_r, tags *t);
void _spec_nil(buffer *b_r);
void _spec_pct(buffer *b_r);
void _spec_p(buffer *b_r, tags *t);
void _spec_r(buffer *b_r, tags *t);
void _spec_S(buffer *b_r, tags *t);
void _spec_o(buffer *b_r, tags *t);
void _spec_u(buffer *b_r, tags *t);
void _spec_x(buffer *b_r, tags *t);
void _spec_X(buffer *b_r, tags *t);
void _spec_b(buffer *b_r, tags *t);
void _spec_d(buffer *b_r, tags *t);
void _spec_R(buffer *b_r, tags *t);
void _error_(void);
int __atoi(const char *s, int n);

/* _write_to_buffer functions */
void _write(buffer *b_r, char c);
void _write_str(buffer *b_r, char *s);
void _write_tmpbuf(buffer *b_r);
void _parse_tag(buffer *b_r, tags *t, parse_table *table);
int str_len(char *str);
void _revstr(char *s);
char *_str_whelp(tags *t, char *hold, int hold_len);
char *_to_hex_unreadable(char *hold);
void _to_rot13(char *s);

/* to string functions */
char *_int_to_str(long int n);
char *_int_to_hexstr(long int n);
char *_int_to_caphexstr(long int n);
char *_int_to_octstr(long int n);
char *_int_to_binstr(long int n);

/* unsigned to string functions */
char *_uint_to_str(unsigned long int n);
char *_uint_to_hexstr(unsigned long int n);
char *_uint_to_caphexstr(unsigned long int n);
char *_uint_to_octstr(unsigned long int n);
char *_uint_to_binstr(unsigned long int n);

/* printf_flag_helper functions */
int _isFlagMinus(tags *t);
int _isFlagPlus(tags *t);
int _isFlagSpace(tags *t);
int _isFlagHashtag(tags *t);
int _isFlagZero(tags *t);

/* parse helper functions */
void _found_spec(buffer *b_r, tags *t, parse_table *table, int i);
void _found_length(buffer *b_r, tags *t, parse_table *table, int i);
void _found_prec(buffer *b_r, tags *t, parse_table *table, int i);
void _found_width(buffer *b_r, tags *t);
void _found_flag(buffer *b_r, tags *t, parse_table *table, int i);

/*spec num helper function*/
void _spec_num_help(buffer *b_r, tags *t, char *num_str, int minus);
int num_len(int n);
void get_sign(tags *t, int minus, char *front);
char *check_prec(char *tmp_str, char *num_str, tags *t, int s_len);
void _out_of_time(char *buf_str, char *tmp_str, char *front, tags *t);

#endif
