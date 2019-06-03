void foo()
{
	int i,j, sum = 0, max = 1000;

	for (i = 0; i < max; ++i)
	{
		for (j = i+1; j < max; ++j)
		{
			sum++;
		}
	}
}