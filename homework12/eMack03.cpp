#include <iostream>

constexpr int fact(int N)
{
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

constexpr double exp(int N)
{
	if (N == 0)
		return 1;
	else
		return 1 / static_cast<double>(fact(N)) + exp(N - 1);
}

int main()
{
	std::cout << exp(10) << std::endl; // 2.71828
}