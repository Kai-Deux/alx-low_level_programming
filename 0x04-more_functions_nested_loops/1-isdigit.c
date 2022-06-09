#include "main.h"

/**
 * _isdigit - input
 *
 * Description: define if a character is a number
 * @c: charater
 * Return: 1 yes 0 no
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
