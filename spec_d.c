#include "main.h"

/**
* _spec_d - sends va-arg with appropriat tags into buffer
* @b_r: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/

void _spec_d(buffer *b_r, tags *t)
{
	int ten_power, n_hold, minus, i;
	char *num_str;

	n_hold = va_arg(b_r->ap, int);
	minus = i = 0;
	ten_power = -1;
	if (n_hold >= 0)
		n_hold *= -1;
	else
	{
		minus = 1;
	}
	num_str = malloc(1024);
	while (num_len(ten_power) < num_len(n_hold))
	{
		ten_power *= 10;
	}
	while (ten_power < -1)
	{
		num_str[i] = ((n_hold / ten_power) % 10 + '0');
		ten_power /= 10;
		i++;
	}
	num_str[i] =  (-1 * (n_hold % 10 - '0'));
	num_str[i + 1] = '\0';
	_spec_num_help(b_r, t, num_str, minus);
	free(num_str);
}

/**
 * num_len - length of the number
 * @n: some number
 *
 * Return: the length of the number
 */

int num_len(int n)
{
	int num_len;

	num_len = 1;
	while (n <= -10)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}
