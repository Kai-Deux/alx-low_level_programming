#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add - addition of parcial products
 * @p: parcial product
 * @mg: big malloc
 * @i: size of big malloc - 1
 * @tp: size of parcial product - 1
  */
void add(char *p, char *mg, int i, int tp)
{
	int pos = tp, a = 0, b = 0, car = 0, res = 0;
	int cont = tp, aux = 0;

	for (; cont >=  0; cont--, i--, pos--)
	{
		a = *(p + pos) - '0';
		b = *(mg + i) - '0';
		res = (a + b) + car;
		car = res / 10;
		res = (res % 10) + '0';
		*(mg + i) = res;
	}
	res = 0;
	for (aux = i - 1; aux >= 0; aux--)
	{
		a = *(mg + aux) - '0';
		a += a + car;
		car = a / 10;
		a = (a % 10) + '0';
		*(mg + aux) = a;
	}
}
/**
 * setiar - fill the pointer with 0
 * @s: pointer
 * @a: size of pointer
 */
void setiar(char *s, int a)
{
	int i;

	for (i = 0; i < a; i++)
		s[i] = '0';
}
/**
 * parcial - give the parcial malloc
 * @a: size one
 * Return: parcial malloc
 */
char *parcial(int a)
{
	int i;
	char *p;

	p = malloc(a);
	if (!p)
		return (NULL);
	for (i = 0; i < a; i++)
		p[i] = '0';
	return (p);
}
/**
 * grande - give big malloc
 * @a: size one
 * @b: size two
 * Return: malloc
 */
char *grande(int a, int b)
{
	int i;
	char *p;

	p = malloc(a + b);
	if (!p)
		return (NULL);
	for (i = 0; i < a + b; i++)
		p[i] = '0';
	return (p);
}
/**
 * tama - give the size
 * @s: string of numbers
 * Return: size
 */
int tama(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * Perror - print Error with putchar.
 * Return: Always 0.
 */
void Perror(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
/**
 * numero - check if strings have only numbers.
 * @s: string 1
 * @a: string 2
 * Return: Always 1 if not or 0 if only has number.
 */
void numero(char *s, char *a)
{
	int i = 0, aux = 0;

	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			aux = 1;
			break;
		}
		i++;
	}
	i = 0;
	while (a[i] != '\0')
	{
		if (!(a[i] >= '0' && a[i] <= '9'))
		{
			aux = 1;
			break;
		}
		i++;
	}
	if (aux == 1)
		Perror();
	if (*s == '0' || *a == '0')
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}
}
/**
 * impresion - print the pointer
 * @s: string.
 * @a: size of string
 */
void impresion(char *s, int a)
{
	int i;

	for (i = 0; i < a; i++)
	{
		if (!(s[0] == '0' && i == 0))
			_putchar(s[i]);
	}
	_putchar('\n');
}
/**
 * main - check the code for Holberton School students.
 * @argv: array of pointers store the arguments
 * @argc: quantity of arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int t1, t2, t3, a = 0, b = 0, j = 0, aux = 0, car, g, ind;
	char *mg, *p, *size1, *size2;

	if (argc != 3)
		Perror();
	else
	{ numero(argv[1], argv[2]);
		t1 = tama(argv[1]);
		t2 = tama(argv[2]);
		ind = t1 + t2;
		mg = grande(t1, t2);
		if (t1 >= t2)
		{ size1 = argv[1];
			size2 = argv[2];
			b = t1 - 1;
			a = t2 - 1;
			t3 = t1 + 1; }
		else
		{ size1 = argv[2];
			size2 = argv[1];
			b = t2 - 1;
			a = t1 - 1;
			t3 = t2 + 1; }
		g = b;
		p = parcial(t3);
		j = b + 1;
		for (; a >= 0; a--, ind--)
		{ car = 0;
			b = g;
			j = g + 1;
			setiar(p, t3);
			for (; b >= 0; b--, j--)
			{ aux = ((size2[a] - '0') * (size1[b] - '0'));
				aux = aux + car;
				p[j] = ((aux % 10) + '0');
				car = aux / 10;	}
			p[j] = (car + '0');
			add(p, mg, (ind - 1), (t3 - 1)); }
		impresion(mg, (t1 + t2)); }
	return (0);
}
