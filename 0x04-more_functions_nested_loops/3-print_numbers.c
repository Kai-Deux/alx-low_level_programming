#include "main.h"

/**
 * print_numbers - entry point
 *
 * Description: Prints the numbers with _putchar
 *
 * Return: void
 */

void print_numbers(void)
{
	int number;

	for (number = '0'; number <= '9'; number++)
	{
		_putchar(number);
	}
	_putchar('\n');
}
