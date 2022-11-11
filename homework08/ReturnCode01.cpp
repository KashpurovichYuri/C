#include <iostream>
#include <vector>
#include <variant>

enum class Codes
{
	error0,
	error1,
	error2,
	//...,
	errorN,
};

// first way
struct Error
{
	std::vector<int> num_of_call { -1 };
	std::vector<Codes> v_of_errors { Codes::error0 };
};

Error g_error;

void handle(const Codes& error)
{
	g_error.v_of_errors.push_back(error);
	g_error.num_of_call.push_back(g_error.num_of_call[std::size(g_error.num_of_call) - 1] + 1);
}

auto func1()
{
	//do something
	if (condition1)
	{
		handle(Codes::error1);
		return;
	}

	//do something
	if (condition2)
	{
		handle(Codes::error2);
		return;
	}

	//...

	//do something
	if (conditionN)
	{
		handle(Codes::errorN);
		return;
	}

	//before possible ending return
	handle(Codes::error0);

	//possible return
}

//second way
std::variant<return_type, Codes> func2() //return type is any type, for example int or std::vector<int>
{
	//do something
	if (condition1)
		return Codes::error0;

	//do something
	if (condition2)
		return Codes::error1;

	//...

	//do something
	if (conditionN)
		return Codes::errorN;

	//before possible ending return

	//possible return	
}

int main()
{
	//first way
	int j = 0;

	func1();
	switch (g_error.v_of_errors[j]) // special function handlefunc() may be realised to handle return code
	{
		case Codes::error0:
			std::cout << "no error" << std::endl;
			break;
		case Codes::error1:
			std::cout << "error1 when call number is " << g_error.num_of_call[j] << std::endl;
			//make error handling
			break;
		case Codes::error2:
			std::cout << "error2 when call number is " << g_error.num_of_call[j] << std::endl;
			//make error handling
			break;
		// ...
		case Codes::errorN:
			std::cout << "errorN when call number is " << g_error.num_of_call[j] << std::endl;
			//make error handling
			break;
	}

	++j;

	//second way
	auto res2 = func2();
	if (std::holds_alternative<return_type>(res2))
		std::cout << std::get<return_type>(res2) << "n";
	else
		switch (std::get<Codes>(res2)) // special function handlefunc() may be realised to handle return code
		{
			case Codes::error0:
				std::cout << "no error" << std::endl;
				break;
			case Codes::error1:
				std::cout << "error1 when call number is " << g_error.num_of_call[j] << std::endl;
				//make error handling
				break;
			case Codes::error2:
				std::cout << "error2 when call number is " << g_error.num_of_call[j] << std::endl;
				//make error handling
				break;
			// ...
			case Codes::errorN:
				std::cout << "errorN when call number is " << g_error.num_of_call[j] << std::endl;
				//make error handling
				break;
		}

}