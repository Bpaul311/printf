#include "main.h"
/**
 * converter - Converts a number from an arbitrary base to @base
 *
 * @num:  An input number in an arbitrary base.
 * @base: The target base for conversion.
 * Return: The converted number in @base
 */
void converter(unsigned int num, unsigned int base)
{
	if (num > (base - 1))

		converter(num / base, base);
	if (base < 10)
		putchar('0' + (num % base));
	else
		putchar('A' + (num % base) - 10);
	
}
