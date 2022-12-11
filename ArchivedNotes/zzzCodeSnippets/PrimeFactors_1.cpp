// Prime factors of a number N ------------------ Note that the number will be prime number if it has only one prime factor which is the number itself
// Exercise - Print all the prime numbers less than the number N

// Follow the usual prime factorization - dividing the number recursively with each prime number starting from 2 to extract their multiples
// Two challenges -
// [1] Computers are not aware of all the prime numbers starting from 2
// [2] What shall be the last number to divide with
//
// [1] Solving the challenge no. 1
// Instead of recursively dividing the number with all the prime numbers, 
// let's divide with 2 and then all the odd numbers since all the prime numbers except 2 are odd 
// This technique seems to have a risk of division with odd composites like 9, 15, .. etc which gets eliminated automatically
// since 9 = 3*3, 15 = 3*5 , .... etc these odd composites will never be assigned as divisor as all their primes factors will be extracted in the 
// earlier steps of recursive division   
//
// [2] Solving the challenge number no. 2
// Use the theorem - "Any composite number N, will have all it's prime factors less than or equal to SQRT(N) except one (which may or may not exist)"
// So, we will recursively divide the number N with odd numbers less than or equal to SQRT(N), note that N will also be updated in the expression SQRT(N)
// for optimization since after every division as after each division, we are finding the prime factors of the next number, this is not mandatory.
// After recursive division, there may be the last prime factor remaining as the quotient which is greater than the SQRT(N). If not, then the final 
// quotient will be 1. Note that the last quotient can not be a composite number as all the prime factors are extracted already in the previous step. 
// The prime factor will be greater than 1 and 2 as well because all the 2s are already extracted
// 


#include <iostream>
#include <cmath>
#include <vector>

int main()
{
	int number;
	std::cin >> number;

	std::vector<int> primeFactors;

	//[1] Extracting all 2's
	while (!(number % 2))
	{
		number /= 2;
		primeFactors.emplace_back(2);
	}

	//[2] Extracting all other prime factors (less than SQRT(N) one by one from the quotient from the previous step
	// Note here we are using odd numbers not the prime numbers, however it works because all the odd composites are extracted in this step
	// in the eary divisions by their primes.
	// For example- 3, 5, 7, 9 are odd and prime except the number 9 but the number 9 will never be used as 'i' as 9 will already be extracted 
	// out of the 'number' while divisions with 3. So, the composites as multiples will already be extracted in the early steps as the 'number' is 
	// updated to it's quotient after every divison
	for (int i = 3; i <= (int(std::sqrt(number)) + 1); i += 2)
	{
		while (!(number % i))
		{
			primeFactors.emplace_back(i);
			number /= i;
		}
	}

	//[3] Extracting the prime factor greater than SQRT(N)
	// Note that till step 2, all the prime factors which are less than SQRT(N) are extracted already
	// So, in this step, only the prime factor which is greater than SQRT(N) will be left
	// If there was no prime factor greater than SQRT(N), then the 'number' would have been reduced to 1
	// implying that all the prime factors are already extracted. However, if it a 'number' greater than 1,
	// it can only mean that it the last prime number. (it can't be the composite number as other prime factors are extracted in step 2.
	// We have used the condition comparing 2 not 1 as, the number can not be equal to 2 as all teh 2s are extracted in step 1.
	if (number > 2)
		primeFactors.emplace_back(number);

	std::cout << primeFactors.size() << "\n";
	for (const auto& factor : primeFactors)
	{
		std::cout << factor << " ";
	}

	return 0;
}
