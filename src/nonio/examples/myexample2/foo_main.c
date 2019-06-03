
void foo();

int main()
{

	#pragma monitor start

	foo();

	#pragma monitor stop

	return 10;
}