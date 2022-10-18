#include <iostream>
#include <cmath>

void prime_finder()
{
	//int primes[50];
	for (int a = 1200; a < 1250; ++a)
	{
		int f = 2;
		bool factorfound = false;
		while (f < sqrt(a))
		{
			if (a % f == 0) factorfound = true;
			++f;
		}
		//if (!factorfound) primes[a - 1200] = a;
		if (!factorfound) std::cout << a << '\t';
	}
}

int main()
{
	prime_finder();
}
