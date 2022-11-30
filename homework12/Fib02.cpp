#include <iostream>

template <int N>
struct Fib
{
	static constexpr int fib = Fib<N-1>::fib + Fib<N-2>::fib;
};

template <>
struct Fib<0>
{
	static constexpr int fib = 0;
};

template <>
struct Fib<1>
{
	static constexpr int fib = 1;
};

int main()
{
	std::cout << Fib<15>::fib << std::endl; // 610
}