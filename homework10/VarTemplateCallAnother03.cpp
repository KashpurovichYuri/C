#include <iostream>

void func(int a, int b)
{
	std::cout << a << ", " << b << std::endl;
}

template <typename callable, typename... Types>
auto AutoCall(callable obj, Types... args)
{
	obj(args...);
}

int main()
{
	AutoCall(func, 5, 10);
}