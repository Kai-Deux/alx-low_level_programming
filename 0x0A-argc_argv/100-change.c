#include <stdio.h>
#include <stdlib.h>
/**
 * main - returns the min numbers of coins per given ammount of money.
 * @argc: argument count or size of arguments.
 * @argv: argument vector
 *
 * Return: 0 success 1 failure.
 */
int main(int argc, char **argv)
{
	int coins, i, ammount;
	int value[5] = {25, 10, 5, 2, 1};

	coins = 0;
	ammount = atoi(argv[argc - 1]);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else if (ammount <= 0)
	{
		printf("0\n");
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			if (value[i] <= ammount)
			{
				coins = coins + (ammount / value[i]);
				ammount = ammount - (ammount / value[i]) * value[i];
				if (ammount == 0)
				{
					printf("%d\n", coins);
					break;
				}
			}
		}
	}
	return (0);
}
