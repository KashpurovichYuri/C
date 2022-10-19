#include "Lands.hpp"
#include <iostream>
#include <string>

int main()
{
	Lands japan {377976, 126150, "Yena", "Japanese", "Tokyo", "Japan"};

	std::cout << "Hello! Today you can know something about Japan." << std::endl;
	std::cout << 
		"Just type 0 if you want to know general info about Japan, 1 - its capital, 2 - official language, 3 - national currency, 4 - area, 5 - population, 6 - population density, anything other number - exit program"
			<< std::endl;

	int info;
	std::cin >> info;
	while(info >= 0 && info <= 6)
	{
		switch (info)
		{
			case 0:
				japan.printInform();
				break;
			case 1:
				japan.printCapital();
				break;
			case 2:
				japan.printOfLanguage();
				break;
			case 3:
				japan.printNatCurrency();
				break;
			case 4:
				japan.printArea();
				break;
			case 5:
				japan.printPopulation();
				break;
			case 6:
				japan.printPopDensity();
				break;
		}
		
		std::cin >> info;
	}

	std::cout << "Goodbye" << std::endl;
}
