#include "main.h"
/**
 * print_number - prints an integer using _putchar
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
