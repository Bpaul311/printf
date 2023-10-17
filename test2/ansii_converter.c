#include "main.h"
/**
 *ascii_conveter - converts a character
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
		       if ((*arr > 0 && *arr < 32) || *arr > 127)
                        	*arr = x;
		       		
			       _putchar(*(arr++));
                        	buff_size++;
                }
        }
        return (buff_size);
}
