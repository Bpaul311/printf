#include "main.h"
/**
 * converter - Converts a number from an arbitrary base to @base
 *
 * @num:  An input number in an arbitrary base.
 * @base: The target base for conversion.
 * Return: The converted number in @base
 */
unsigned int converter(unsigned int num, int base)
{
	unsigned int div = num / base;
	unsigned int res = 0, rem;
	unsigned int i = 1;

	while (div > 0)
	{
		rem = num % base;
		num = div;
		div /= base;
		rem = rem * i;
		i *= 10;
		res = res + rem;
	}
	rem = num % base;
	num = div;
	div /= base;
	rem = rem * i;
	i *= 10;
	res = res + rem;
	return (res);
}
