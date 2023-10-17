#include <stdio.h>
#include <limits.h>
#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0 but sometimes not
 *
 */
int main(void)
{
        int num = 42;
    int *ptr = &num;

    printf("Address of pointer: ");
    print_custom_pointer(ptr);
    printf("address using printf is %p", ptr);
    printf("\n");

    return (0);
}
