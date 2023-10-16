#ifndef MAIN_H
#define MAIN_H

/*common library*/
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
/*function prototypes*/

int _putchar(char c);
int _printf(const char *format, ...);
unsigned int converter(unsigned int num, int base);
int print_number(int n);
int print_str(char *arr);

#endif /*MAIN_H*/
