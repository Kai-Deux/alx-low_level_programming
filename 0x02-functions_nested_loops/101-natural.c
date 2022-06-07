#include <stdio.h>

 int main(void)
{
	int n = 0;
	int i;


	for (i=0; i < 1024; i++)
	{
		if (i % 3 == 0)
		n += i;
		

		if (i % 5 == 0)
		n += i;
	}

	printf("%i\n", n);

	return 0;
}
