#include <stdlib.h>
#include "main.h"
#include <stdio.h>


/**
 * _strlen - size of string
 * @s: string to measure
 * Return: size of string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		++i;
	return (i);
}

/**
 * checkarg - checks arguments only composed of digits
 * @s: string to check
 * Return: -1 if False, number as string stripped of 0 otherwise;
 */
char *checkarg(char *s)
{
	int i, count, stop;

	i = 0;
	stop = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) < '0' || *(s + i) > '9')
			return (NULL);

		if (stop == 0 && *(s + i) == '0')
			++count;
		if (*(s + i) != '0')
			stop = 1;
		i++;
	}
	return (s + count);
}

/**
 * makesecond - create new string, by multiplying values of src by c
 * @src: string
 * @l1: length of src
 * @c: multiplier
 * @zero: number of 0 to insert in string at the end
 * Return: pointer to new string, NULL if fails
 */
char *makesecond(char *src, int l1,  char c, int zero)
{
	int  j, l, retenue, prod;
	char *second;

	l = l1 + 2 + zero; /*retenue + \0 + nb zeros*/
	second = malloc(l * sizeof(char));
	if (second == NULL)
		return (NULL);
	second[l - 1] = '\0';
	while (zero > 0)
		second[l - 1 - zero--] = '0';
	j = l1;
	retenue = 0;
	while (j > 0)
	{
		prod = (src[j - 1] - '0') * (c - '0') + retenue;
		second[j] = prod % 10 + '0';
		retenue = prod / 10;
		j--;
	}
	if (retenue > 0)
		second[j] = retenue + '0';
	else
		second[j] = '0';
	return (second);
}

/**
 * _calloc - allocates memory for an array, initializes values to '0'
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to array if success, or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *p;
	char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	s = p;
	i = 0;
	while (i < nmemb)
		*(s + i++) = '0';

	return (p);
}



/**
 * infinite_add - add two numbers given as strings
 * @n1: this sring is a number
 * @n2: this string is a number
 * @r: buffer to put result
 * @size_r: size of buffer
 * Return:pointer to buffer with result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, retenue, sum;

	l1 = _strlen(n1);
	l2 = _strlen(n2);
	*(r + size_r - 1) = '\0';
	size_r--;
	if (l1 > size_r || l2 > size_r || size_r == 0)
		return (0);
	if (l1 == size_r && l2 == size_r && (*n1 - '0' + *n2 - '0') > 9)
		return (0);

	retenue = 0;
	while (size_r > 0 && (l1 > 0 || l2 > 0))
	{
		if (l1 <= 0)
			sum =  *(n2 + l2 - 1) - '0' + retenue;
		else if (l2 <= 0)
			sum  = *(n1 + l1 - 1) - '0' + retenue;
		else
			sum = *(n1 + l1 - 1) - '0' + *(n2 + l2 - 1) - '0' + retenue;
		retenue = sum / 10;
		*(r + size_r - 1) = sum % 10 + '0';
		l1--;
		l2--;
		size_r--;
	}
	if (retenue != 0 && size_r > 0)
	{
		*(r + size_r - 1) = retenue + '0';
	}
	return (r);
}


/**
 * _mul - multiply 2 strings made of digits
 * @s1:first string
 * @s2:second string
 * Return: product or NULL
 */
char *_mul(char *s1, char *s2)
{

	int l1, l2, i;
	char *first, *second, *third;

	l1 = _strlen(s1);
	l2 = _strlen(s2);

/*loop through 2nd string, produce a new line and add the first and new line*/
	first = makesecond(s1, l1, s2[l2 - 1], 0);
	if (first == NULL)
		return (NULL);
	if (l2 == 1)
		return (first);
	i = 1;
	while (i < l2)
	{
/*make second line*/
		second = makesecond(s1, l1, s2[l2 - i - 1], i);
		if (second == NULL)
		{
			free(first);
			return (NULL);
		}
		third = _calloc((l1 + 2 + i + 1), sizeof(char));
		if (third == NULL)
		{
			free(second);
			free(first);
			return (NULL);
		}
		third = infinite_add(second, first, third, l1 + 2 + i + 1);
		free(second);
		free(first);
		first = third;
		++i;
	}
	return (third);
}


/**
 * main - multiply 2 numbers
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *mul, *n1, *n2;

	if (argc != 3)
	{
		puts("Error");
		exit(98);
	}
	n1 = checkarg(argv[1]);
	n2 = checkarg(argv[2]);
	if (n1 == NULL || n2 == NULL)
	{
		puts("Error");
		exit(98);
	}

	if (*n1 == '\0' || *n2 == '\0')
	{
		printf("0\n");
		return (0);
	}
	else
	{
		mul = _mul(n1, n2);
		if (mul == NULL)
		{
			puts("merde");
			return (0);
		}
	}

	printf("%s\n", checkarg(mul));
	free(mul);
	return (0);
}
