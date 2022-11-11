#include <iostream>
#include <exception>
#include <vector>
#include <bitset>

void changeVector(std::vector<int>& v) try
{
	v.at(std::size(v)) = 0;
}
catch (const std::out_of_range& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return;
}

void memory() try
{
	int* array = new int[10000000000];
}
catch (const std::bad_alloc& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return;
}

void check(int sum) try
{
	if (sum < 0)
		throw std::runtime_error("invalid value of sum");
}
catch (const std::runtime_error& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return;
}

class Polymorph
{
	virtual void doSmth()
	{

	}
};

void printTypeID(Polymorph * ptr=nullptr) try
{
	std::cout << typeid(*ptr).name();
}
catch (const std::bad_typeid& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return;
}

void setBit(const std::string& str) try
{
	std::bitset<4>{ str };
}
catch (const std::invalid_argument& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return;
}

int main() try
{
	std::vector<int> vector { 0, 1, 2, 3, 4, 5 };
	changeVector(vector);

	memory();

	int sum = -1;
	check(sum);

	printTypeID();

	std::string str1 { "NO!" };
	setBit(str1);
}
catch (const std::exception& except)
{
	std::cerr << "exception caught: " << except.what() << std::endl;
	return 0;
}
catch(...)
{
	std::cerr << "there is an exception" << std::endl;
	return 0;
}
