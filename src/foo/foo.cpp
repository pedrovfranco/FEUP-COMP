#include <iostream>


int main()
{
	int count = 0;

	for (int i = 0; i < 100; ++i)
	{
		count += i;
	}

	std::cout << "Result = " << count << "\n";
	return 0;
}