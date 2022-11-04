#include <iostream>
#include <vector>

enum class Codes
{
	error0,
	error1,
	error2,
	//...,
	errorN,
};

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

auto func()
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

int main()
{
	int j = 0;

	func();
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

	//may call next function further
}