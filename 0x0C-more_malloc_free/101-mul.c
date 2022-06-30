#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
/**
 * _strlen - strlen custom function
 * @str: string
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i++);
}
/**
 * check - check if strign has only numbers
 * @str: string
 * Return: 98 if it fails 0 if it isnt
 */
int check(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (98);
	}
	return (0);
}
/**
 * err - display error
 * Return: just print
 */
void err(void)
{
	char *error = "Error";
	int i;

	for (i = 0; error[i] != '\0'; i++)
		_putchar(error[i]);
	_putchar('\n');
}
/**
 * main - Store the arguments
 *
 * @argc: number of arguments
 * @argv: value of arguments
 *
 * Return: Display number of arguments
 */
int main(int argc, char *argv[])
{
	int a[10000], b[10000];
	int ans[10000] = {0};
	int i, j, tmp;
	char *s1, *s2;
	int l1;
	int l2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		if (check(s1) == 98)
		{
			err();
			exit(98);
		}
		if (check(s2) == 98)
		{
			err();
			exit(98);
		}
		l1 = _strlen(s1);
		l2 = _strlen(s2);
		for (i = l1 - 1, j = 0; i >= 0; i--, j++)
			a[j] = s1[i] - '0';
		for (i = l2 - 1, j = 0; i >= 0; i--, j++)
			b[j] = s2[i] - '0';
		for (i = 0; i < l2; i++)
		{
			for (j = 0; j < l1; j++)
				ans[i + j] += b[i] * a[j];
		}
		for (i = 0; i < l1 + l2; i++)
		{
			tmp = ans[i] / 10;
			ans[i] = ans[i] % 10;
			ans[i + 1] = ans[i + 1] + tmp;
		}
		for (i = l1 + l2; i >= 0; i--)
		{
			if (ans[i] > 0)
				break;
		}
		if (i == -1)
			_putchar(ans[0] + 48);
		for (; i >= 0; i--)
			_putchar(ans[i] + 48);
		_putchar('\n');
		return (0);
	}
	err();
	exit(98);
}
