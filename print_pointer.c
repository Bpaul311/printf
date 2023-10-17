#include "main.h"
/**
 * print_pointer - prints a pointer in hexadecimal
 * @ptr: accepts a void pointer
 * Return: nothing
 */
void print_pointer(void *ptr)
{
	char *s = malloc(sizeof(char) * 20);
	int buff = 0;
	intptr_t p = (intptr_t)ptr;

	if (s == NULL)
		return;
	s[0] = '0';
	s[1] = 'x';
	buff += 2;
	converter(p, 16, s, &buff, 0);
	buff += 2;
	s[buff] = '\0';
	print_str(s);
	free(s);
}
