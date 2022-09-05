#include "main.h"

/**
 * _puts - writes the string s to stdout
 * 			and returns the string written
 * @s: The string to print
 * 
 * Return: On success 1.
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);
}
