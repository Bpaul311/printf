#include "main.h"
/**
 * converter - Converts a nber from an arbitrary base to @base
 *
 * @n:  An input nber in an arbitrary base.
 * @base: The target base for conversion.
 * @str: character pointer to conveted nber
 * @bf: the integer pointer to the size in memmory
 * @lc: checks if the base will be lowercase
 * Return: Nothing
 */
void converter(unsigned long int n,
			   unsigned int base, char *str, int *bf, int lc)
{
	char c = 'A';

	if (lc == 0)
		c = 'a';
	if (n >= base)
		converter(n / base, base, str, bf, lc);
	if (base < 10)
	{
		str[(*bf)++] = '0' + (n % base);
	}
	else
	{
		if ((n % base) > 9)
			str[(*bf)++] = c + ((n % base) - 10);
		else
			str[(*bf)++] = '0' + (n % base);
	}
}
/**
 * count_bits - counts the nber of characters needed in @base
 * @n: the nber to count bits need for
 * @base: the base of the result string
 * Return: size needed
 */
int count_bits(unsigned int n, unsigned int base)
{
	int count = 0;

	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
