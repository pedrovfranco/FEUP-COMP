#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream ifs("flags.txt");
	vector<string> flags;
	string line, cell;

	while (getline(ifs, line, ' '))
	{
		flags.push_back(line);


		getline(ifs, line, '\n');
	}

	for (int i = 0; i < flags.size(); i++)
	{
		cout << flags[i] << " ";
	}

	return 0;
}