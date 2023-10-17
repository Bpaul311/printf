#include "main.h"
int main(void)
{
    int a = (unsigned int)INT_MAX * 2;
    unsigned int ui = (unsigned int)INT_MAX * 2;

    (void)ui;
    (void)a;
    printf("%u\n", a);
    _printf("%u\n", a);
    printf("%o\n", a);
    _printf("%o\n", a);
    printf("%x\n", a);
    _printf("%x\n", a);
    printf("%X\n", a);
    _printf("%X\n", a);
    printf("%p\n", &a);
    _printf("%p\n", &a);
    _printf("%p\n", a);

    return (0);
}
