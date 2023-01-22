#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int n = _printf("%u", 2.35);

	printf("\nn = %d \n", n);
	return (0);
}
