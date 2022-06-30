#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *mul - a function to multiply arguments
 *@argv: accepts argument and builds an array
 *@argc: counts the arguments
 *Return: returns
 */

int mul(int argc, unsigned int *argv)
{
if (argc > 2)
printf("Error\n");
exit(98);

if (argv[0]/10 != 0 || argv[1]/10 != 0)
printf("Error\n");
exit(98);

int ans = argv[0] * argv[1];
printf(ans);

return (0);
}
