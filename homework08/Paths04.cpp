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
	+1 e.title() == "CEO" and operator|| is not overloaded (although if it is overloaded then both logical expressions will be evaluated)
	+1 e.title() != "CEO" and e.salary() > 100000
	+1 e.title() != "CEO" and e.salary() < 100000	
*/

/*
	Execution paths with exceptions:
	+1 if copy constructor is called if e is copying in function (Employee e)
	+2 if e.title() or e.salary() generate exceptions in logic expression
	+3 if operator==, or operator>, or operator|| generate exceptions in logic expression
	+2 if there will be implicit casting of literals "CEO" or 100000
	+4 if one of operator<< generates exception in if-branch
	+2 if e.name() or e.surname() generate exceptions in if-branch
	+2 if one of operator<< generates exception in else-branch
	+1 if e.name() generates exception in else-branch
	+2 if e.name() or e.surname() generate exceptions in return
	+2 if operator+ generates exception in return
	+1 if there will be implicit casting of literal " " in return

	+1 if destructor generates exception (but programmer usually shouldn't allow it!)
	Сombinatorial variants are not interesting
*/

//  Number of execution paths: 25 + 1.