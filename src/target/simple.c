
int sum2()
{
	int i, max = 100, sum = 0;
	for (i = 0; i < max; i++)
	{
		sum += i;
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

	sum();
	
	return 0;
}