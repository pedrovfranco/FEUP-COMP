#include <stdio.h>

#include "simple2.c"


int sum2()
{
	int i, max = 100, sum = 0;
	for (i = 0; i < max; i++)
	{
		sum += sumShift(i);
	}

	return sum;
}

int sum()
{
	int i, max = 100, sum = 0;
	for (i = 0; i < max; i++)
	{
		sum += sum2();
	}

	return sum;
}


int main()
{

	int ret = sum();

	printf("Result = %i\n", ret);
	
	return 0;
}