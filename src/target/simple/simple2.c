#include <stdio.h>

int sumShift(int max)
{
	int i, sum = 0;
	for (i = 0; i < max; i++)
	{
		if (i % 2 == 0)
			sum += i;
		else
			sum = sum << 7;
	}

	// printf("Sum = %i\n", sum);

	return sum;
}
