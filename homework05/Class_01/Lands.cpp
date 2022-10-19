#include "Lands.hpp"
#include <iostream>
#include <iomanip>

void Lands::printPopDensity() const
{
	std::cout << std::setprecision(4);
	std::cout << "Population density, people/km: "
		<< static_cast<double>(population) * to_neccesary_unit / area << std::fixed << std::endl;
}

void Lands::printInform() const
{
	Lands::printCountry();
	Lands::printCapital();
	Lands::printOfLanguage();
	Lands::printNatCurrency();
	Lands::printArea();
	Lands::printPopulation();
	Lands::printPopDensity();
}
