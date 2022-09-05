#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * 			  and returns the character written
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (fwrite(&c, 1, 1, stdout));
}
