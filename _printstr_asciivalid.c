#include "main.h"
/**
 * print_str_asciivalid - prints a string
 * @arr: a character pointer to be printer
 * Return: size of the printed string
 */
int print_str_asciivalid(char *arr)
{
	int buff_size = 0;
	char *res;
	int buff = 0;

	if (*arr)
	{
		while (arr != NULL && *arr != '\0')
		{
			if ((*arr < 32 && *arr > 0) || (*arr >= 127))
			{
				res = malloc(sizeof(char) * 3);
				buff = 0;

				if (res == NULL)
					return (0);
				_putchar('\\');
				_putchar('x');
				converter(*arr, 16, res, &buff, 1);
				if (*arr < 16)
				{
					res[1] = res[0];
					res[0] = '0';
					buff++;
				}
				res[buff] = '\0';
				print_str(res);
				free(res);
				arr++;
				buff_size += 4;
			}
			else
			{
				_putchar(*(arr++));
				buff_size++;
			}
		}
	}
	return (buff_size);
}
