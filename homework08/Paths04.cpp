#include <iostream>

String evaluate_salary_and_return_name(Employee e)
{
	if (e.title() == "CEO" || e.salary() > 100000)
	{
		std::cout << e.name() << " " << e.surname() << " is overpaid.\n";
	}
	else
	{
		std::cout << e.name() << " is not overpaid.\n";
	}

	return e.name() + " " + e.surname();
}

/* 
	Normal execution paths:
	+2 because we have if-else consrtuction and just one return	
*/

/*
	Execution paths with exceptions:
	+3 if e.title(), or e.salary(), or they both generate exceptions (if value of the logic expression if fully estimated)
	+3 if e.name() or e.surname() or they both generate exceptions in if-branch of code
	+1 if e.name() generates exceptions in else-branch of code
	+0 if e.name() generates exceptions in if-branch of code or else-branch of code or does not generate it
	+0 if e.surname() generates exceptions earlier or not
*/

//  Number of execution paths: 9.