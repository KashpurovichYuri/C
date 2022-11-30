#include <iostream>

template <int N>
struct fact
{
	static constexpr int n = N * fact<N - 1>::n;
};

template <>
struct fact<0>
{
	static constexpr int n = 1;
};

template <int K, int N>
struct BinCoef
{
	static constexpr int bincoef = fact<N>::n / (fact<K>::n * fact<N - K>::n);
};

int main()
{
	std::cout << BinCoef<2, 4>::bincoef << std::endl;
}