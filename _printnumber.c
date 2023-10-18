#include "main.h"
/**
 * print_number - prints an integer using _putchar
 * @n: the integer to print
 * Return: size of the number printed
 */

int print_number(int n)
{
	unsigned int tmp = 1000000000;
	unsigned int n2, x, t2;
	int buff_size = 0;

	if (n < 0)
	{
		_putchar('-');
		buff_size++;
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
			buff_size++;

			while ((n2 % t2) / (t2 / 10) == 0 && n2 > 9)
			{
				if (t2 == 10)
					break;
				_putchar('0');
				buff_size++;
				t2 = t2 / 10;
			}

			n2 %= tmp;
		}

		tmp = tmp / 10;
	}
	_putchar('0' + (x % 10));
	buff_size++;
	return (buff_size);
}
