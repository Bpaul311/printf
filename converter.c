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
void converter(int num, int base, char *output,int *buffsize) {
    if (num >= base) {
        converter(num / base, base, output, buffsize);
    }
    if (base < 10) {
        output[(*buffsize)++] = '0' + (num % base);
    } else {
        if (  (num % base) > 9)
        output[(*buffsize)++] = 'A' + ((num % base) - 10);
        else
        output[(*buffsize)++] = '0' + (num % base);
    }
}
