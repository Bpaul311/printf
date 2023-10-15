#include <stdio.h>
#include <limits.h>
#include "main.h"
<<<<<<< HEAD
/**
 * main - Entry point
 *
 * Return: Always 0 but sometimes not
 *
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("%b\n", 98);
	return (0);
=======
    /**
     * main - Entry point
     *
     * Return: Always 0 but sometimes not
     *
     */
    int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    len = _printf("");
    len2 = printf(" ");
    ui = (unsigned int)INT_MAX + 1024;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("%b\n", 98);
    return (0);
>>>>>>> e2348da465b973a044586244a150eed55a494eb1
}
