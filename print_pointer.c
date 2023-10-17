#include "main.h"
/**
 * print_pointer - prints a pointer in hexadecimal
 * @ptr: accepts a void pointer
 * Return: nothing
 */
void print_pointer(void *ptr)
{
	char *s = malloc(sizeof(char) * 24);
	unsigned long  p = (unsigned long)ptr;
	int i;
	char hexs[] = "0123456789abcdef";

	if (s == NULL)
		return;
	s[0] = '0';
	s[1] = 'x';
	for (i = 15 ; i >= 2; i--)
	{	
		s[i] = hexs[p & 0xF];
		p >>= 4;
	}
	s[16] = '\0';
	for (i = 0; s[i]; i++)
		_putchar(s[i]);

	free(s);
}
