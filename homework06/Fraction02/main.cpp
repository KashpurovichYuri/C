#include "Fraction.hpp"
#include <iostream>

int main()
{
	frn::Fraction frac1 { 1, 2 };
	frn::Fraction frac2 { -5, -9 };

	std::cout << frac2 << std::endl;
	std::cout << (frac1 + frac2) << ", " << (frac1 / frac2) << std::endl;

	frn::Fraction frac3, frac4 { -7 };
	std::cout << frac3 << ", " << frac4 << ", " << (frac1 != frac3) << std::endl;

	frn::Fraction frac5;
	std::cin >> frac5;
	std::cout << (frac1 > frac5) << std::endl;
	std::cout << static_cast<double>(frac5) << std::endl;

	frn::Fraction frac6 { frac1 };
	std::cout << static_cast<double>(frac1) << std::endl;

	std::cout << (frac1 + 1.0) << std::endl;
	std::cout << (frac1 + 1) << std::endl;
	std::cout << (frac1 < 1.0) << std::endl;
	std::cout << (static_cast<double>(frac1) < 1) << std::endl;
}