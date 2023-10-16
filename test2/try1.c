#include "main.h"
/**
 * print_str - prints a string
 * @arr: a character pointer to be printer
 * Return: size of the printed string
 */
int print_str(char *arr)
{
	size_t buff_size = 0;

	if (*arr)
	{
		while (arr != NULL && *arr != '\0')
		{
			write(1, arr++, sizeof(char));
			buff_size++;
		}
	}
	return (buff_size);
}
/**
 * _printf - format and print data
 * @format:  controls the output like printf.
 * Return: number of char printed
 */
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
				if (!c) /*c is null*/
					exit(1);
				write(1, &c, 1);
				buff_size++;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					exit(1);

				buff_size += print_str(str);
				break;
			case '%':
				_putchar(format[i]);
				buff_size++;
				break;
			case 'd':
			case 'i':
				num = va_arg(args, int);
				buff_size += print_number(num);
				break;
			case 'u':
				unum = (unsigned int)va_arg(args, unsigned int);
				print_number(unum);
				break;
			case 'b':
				num = va_arg(args, unsigned int);
				binary = converter(num, 2);
				print_number(binary);
				break;
			default:
				_putchar(format[--i]);
				_putchar(format[++i]);
				buff_size += 2;
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
