#include "main.h"
/**
 * converter - Converts a number from an arbitrary base to @base
 *
 * @num:  An input number in an arbitrary base.
 * @base: The target base for conversion.
 * @str : character pointer to conveted number
 * @buff : the integer pointer to the size in memmory
 * Return: Nothing
 */
void converter(unsigned int num, unsigned int base, char *str, int *buff)
{
	if (num > (base - 1))
		converter(num / base, base, str, buff);
	if (base < 10)
	{
		str[(*buff)++] = '0' + (num % base);
	}
}
