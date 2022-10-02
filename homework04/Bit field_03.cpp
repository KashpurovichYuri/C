// mceconds

#include <iostream>

struct Time
{
	Time( unsigned int num
		, unsigned int month
		, unsigned int year
		, unsigned int hours
		, unsigned int ceconds
		, unsigned int mceconds)
	: number { num }
	, month { month }
	, year { year }
	, hours { hours }
	, ceconds { ceconds }
	, mceconds { mceconds }
	{

	}

	unsigned int number: 5;
	unsigned int month: 4;
	unsigned int year: 12;
	unsigned char : 0;
	unsigned int hours: 7;
	unsigned int ceconds: 7;
	unsigned int mceconds: 10;
};

int main()
{
	// current data and time: 02/10/2022, 17:07.066;

	Time cur_time { 2, 10, 2022, 17, 7, 66 };
	const int to_mceconds = 1000;
	std::cout << cur_time.number << "/" << cur_time.month << "/" << cur_time.year << ", "
		<< cur_time.hours << ":" << cur_time.ceconds + (float) cur_time.mceconds / to_mceconds << std::endl;
	// it is printing 2/10/2022, 17:7.066
	// There is problem with 0 ahead: 02, 07, but it can be solved
}
