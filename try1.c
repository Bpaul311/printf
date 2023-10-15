#include "main.h"
/*
 * printstr - prints a string
 * arr: a character pointer to be printer
 * Return : NOthing
 */
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
    if (format == NULL)
        exit(1);
    num_args = strlen(format);
    if (format == NULL || num_args == 0)
        return (1);
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
    va_end(args);
    return (buff_size);
}
