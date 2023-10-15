#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

void print_str(char *arr)
{
    if (*arr)
    {
        while (arr != NULL && *arr != '\0')
        {
            write(1, arr++, sizeof(char));
        }
    }
}
/**
 * print_number - prints an integer using _printchar
 * @n: the integer to print
 */

void print_number(int n)
{
    unsigned int tmp = 1000000000;
    unsigned int n2, x, t2;

    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }
    n2 = n;
    x = n;

    while (tmp >= 10)
    {
        if (n2 >= tmp)
        {
            _putchar('0' + (n2 / tmp));
            t2 = tmp;

            while ((n2 % t2) / (t2 / 10) == 0 && n2 > 9)
            {
                if (t2 == 10)
                    break;
                _putchar('0');
                t2 = t2 / 10;
            }

            n2 %= tmp;
        }

        tmp = tmp / 10;
    }
    _putchar('0' + (x % 10));
}

int _printf(const char *format, ...)
{
    int num_args, i = 0;
    unsigned int unum;
    char c;
    char *str;
    int num, binary;
    size_t buff_size = 0;
    va_list args;

    va_start(args, format);
    num_args = strlen(format);
    for (i = 0; i < num_args; i++)
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
            case 'c':
                c = va_arg(args, int);
                write(1, &c, 1);
                buff_size++;
                break;
            case 's':
                str = va_arg(args, char *);
                print_str(str);
                buff_size++;
                break;
            case '%':
                c = '%';
                write(1, &c, 1);
                buff_size++;
                break;
            default:
            case 'd':
            case 'i':
                num = va_arg(args, int);
                print_number(num);
                break;
            case 'u':
                unum = va_arg(args, unsigned int);
                print_number(unum);
                break;
            case 'b':
                num = va_arg(args, unsigned int);
                binary = converter(num, 2);
                print_number(binary);
                break;
            }
        }
        else
        {
            c = format[i];
            write(1, &c, 1);
            buff_size++;
        }
    }
    return (buff_size);
}