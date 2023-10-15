#include "main.h"
int _binaryconv(int num)
{
	int div = num / 2;
	int rem, res = 0;
	int i = 1;

	while (div > 0)
	{
		rem = num % 2;
		num = div;
		div /= 2;
		rem = rem * i;
		i *= 10;
		res = res + rem;
	}
	rem = num % 2;
	num = div;
	div /= 2;
	rem = rem * i;
	i *= 10;
	res = res + rem;
	return (res);
}