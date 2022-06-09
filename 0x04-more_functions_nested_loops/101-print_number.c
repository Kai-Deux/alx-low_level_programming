#include "main.h"
/**
 * print_number - print an int numbers.
 * @n: number tested
 * Return: Always 0.
 */
void print_number(int n)
{
	int i, j, digit, digits, power;
	unsigned int temp, numchar, number;

	digit = 0;
	if (n < 0)
	{
		_putchar('-');
		temp = -n;
	}
	else
	{
		temp = n;
	}

	number = temp;

	while (number >= 10)
	{
		number = number / 10;
		digit++;
	}
	digits = digit + 1;
	power = 1;
	i = 1;

	while (i < digits)
	{
		power = power * 10;
		i++;
	}
	j = power;
	while (j >= 1)
	{
		numchar = (temp / j) % 10;
		_putchar(numchar + '0');
		j = j / 10;
	}
}
