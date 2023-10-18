#include "main.h"
/**
 * print_str - prints a string
 * @arr: a character pointer to be printer
 * Return: size of the printed string
 */
int print_str(char *arr)
{
	int buff_size = 0;

	if (*arr)
	{
		while (arr != NULL && *arr != '\0')
		{
			_putchar(*(arr++));
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
	unsigned int unum, base = 2;
	size_t ulnum;
	char c;
	char *str;
	void *ptr;
	char *binary;
	int buff_size = 0;
	int buff = 0, num;
	va_list args;

	va_start(args, format);
	num_args = _strlen(format);
	for (i = 0; i < num_args; i++)
	{
		binary = malloc(sizeof(char) * 100);
		buff = 0;
		if (binary == NULL)
			return (-1);
		if (format == 0 || format == NULL)
		{
			free(binary);
			va_end(args);
			return (-1);
		}

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

				if (str == NULL || !str)
					buff_size += print_str("(null)");
				else
					buff_size += print_str(str);
				break;
			case 'S':
				str = va_arg(args, char *);
				if (str == NULL || !str)
					buff_size += print_str_asciivalid("(null)");
				else
					buff_size += print_str_asciivalid(str);
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
				ulnum = va_arg(args, size_t);
				buff_size += print_lnumber(ulnum);
				break;
			case '#':
				switch (format[++i])
				{
				case 'o':
					base = 8;
					ulnum = va_arg(args, unsigned int);
					if (ulnum > 0)
					{
						_putchar('0');
						buff_size++;
					}
					converter(ulnum, 8, binary, &buff, 1);
					binary[buff] = '\0';
					buff_size += print_str(binary);
					break;

				case 'x':
					base = 16;
					ulnum = va_arg(args, size_t);
					if (ulnum > 0)
					{
						_putchar('0');
						_putchar('x');
						buff_size += 2;
					}
					converter(ulnum, base, binary, &buff, 0);
					binary[buff] = '\0';
					buff_size += print_str(binary);
					break;
				case 'X':
					base = 16;
					ulnum = va_arg(args, size_t);
					if (ulnum > 0)
					{
						_putchar('0');
						_putchar('X');
						buff_size += 2;
					}
					converter(ulnum, base, binary, &buff, 1);
					binary[buff] = '\0';
					buff_size += print_str(binary);
					break;
				default:
					ulnum = va_arg(args, size_t);
					break;
				}
				break;
			case 'o':
				base = 8;
				ulnum = va_arg(args, unsigned int);
				converter(ulnum, 8, binary, &buff, 1);
				binary[buff] = '\0';
				buff_size += print_str(binary);
				break;
			case 'x':
				base = 16;
				ulnum = va_arg(args, size_t);
				converter(ulnum, base, binary, &buff, 0);
				binary[buff] = '\0';
				buff_size += print_str(binary);
				break;
			case 'X':
				base = 16;
				ulnum = va_arg(args, size_t);
				converter(ulnum, base, binary, &buff, 1);
				binary[buff] = '\0';
				buff_size += print_str(binary);
				break;
			case 'b':
				base = 2;
				unum = va_arg(args, size_t);
				converter(unum, base, binary, &buff, 1);
				binary[buff] = '\0';
				buff_size += print_str(binary);

				break;
			case '\0':
				buff_size = -1;
				break;
			case ' ':
				/*handle spaces*/
				if (format[++i] == 'd' || format[++i] == 'i')
				{
					num = va_arg(args, int);
					if (num >= 0)
					{
						_putchar(' ');
						buff_size++;
					}

					buff_size += print_number(num);
				}
				break;
			case '+':
				if (format[++i] == 'd' || format[++i] == 'i')
				{

					num = va_arg(args, int);
					if (num >= 0)
					{
						_putchar('+');
						buff_size++;
					}

					buff_size += print_number(num);
				}
				break;

			case 'p':
				ptr = va_arg(args, void *);
				if (ptr == NULL)
				{
					buff_size += print_str("(nil)");
					break;
				}
				print_pointer(ptr);
				buff_size += 14;
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
			_putchar(format[i]);
			buff_size++;
		}
		free(binary);
	}
	va_end(args);

	return (buff_size);
}
