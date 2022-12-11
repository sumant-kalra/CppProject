// Print all the prime numbers less or equal to the number 

#include <iostream>
#include <vector>
#include <cmath>

void printPrimes(int number);
bool isPrime(int n);

int main()
{
	// [1] Taking the number as input
	int number;
	std::cin >> number; /// refering to the original 'number' as N in the comments

	// [2] Print prime numbers less than or equal to the number
	printPrimes(number);

	return 0;
}

void printPrimes(int number)
{
	if (number == 1)
	{
		std::cout << "Enter a number greater than 1\n";
		return;
	}
	else
	{
		std::vector<int> primes;
		for (int i = 2; i <= number; ++i)
		{
			if(isPrime(i))
				primes.emplace_back(i);
		}

		std::cout << "Count: " << primes.size() << "\n";
		for (const auto& num : primes)
			std::cout << num << " ";
		std::cout << "\n";
	}
}

#if 0
// With this function, the algorithm has the TimeComplexity equal to O(N^2)
bool isPrime(int n)
{
	if (n == 2)
		return true;
	else
	{
		for (int j = 2; j < n; ++j)
		{
			if (!(n % j))
				return false;
		}
		return true;
	}
}
#endif

// With this function, the algorithm has the TimeComplexity equal to O(N^(3/2))
bool isPrime(int n)
{
	if (n == 2)
		return true;
	else
	{
		// As per the theorem, if the number does not have a prime factor which is <= SQRT(number) then the number is a prime number
		for (int j = 2; j <= std::sqrt(n); ++j)
		{
			if (!(n % j))
				return false;
		}
		return true;
	}
}
