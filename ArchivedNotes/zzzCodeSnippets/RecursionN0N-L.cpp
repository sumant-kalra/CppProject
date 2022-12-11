#include <iostream>

void functionRecursive(int n)
{
	static int originalInput = n;
	static bool isDecreasing = 1;

	if (n == 0)
		isDecreasing = 0;

	std::cout << n << " ";

	if (isDecreasing)
		--n;
	else
	{
		if (n == originalInput)
			return;
		++n;
	}

	functionRecursive(n);	
}

int main()
{
	int n = 10;
	functionRecursive(n);

	return 0;
}