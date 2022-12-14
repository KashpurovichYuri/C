// Does arguments in constructor use too much memory? Can we use pass by reference?
// If user will use some sequence of char, cycle in this program will be endless. Why?

#include <iostream>
#include <string>
#include <iomanip>

struct Lands
{
	using square_km2 = int;
	using thousands_of_people = int;

	Lands() = default;

	Lands(int area
		, int population
		, const std::string& national_currency1
		, const std::string& official_language
		, const std::string& capital
		, const std::string& country)
		: area { area }
		, population { population }
		, national_currency { national_currency1 }
		, official_language { official_language }
		, capital { capital }
		, country { country }
	{

	}

	void printCountry() const
	{
		std::cout << "Country: " << country << std::endl;
	}

	void printCapital() const
	{
		std::cout << "Capital: " << capital << std::endl;
	}

	void printOfLanguage() const
	{
		std::cout << "Official language: " << official_language << std::endl;
	}

	void printNatCurrency() const
	{
		std::cout << "National currency: " << national_currency << std::endl;
	}

	void printArea() const
	{
		std::cout << "Area, km2: " << area << std::endl;
	}

	void printPopulation() const
	{
		std::cout << "Population, thousands of people: " << population << std::endl;
	}

	void printPopDensity() const
	{
		static const auto to_neccesary_unit = 1000;
		std::cout << std::setprecision(4);
		std::cout << "Population density, people/km: "
			<< static_cast<float>(population) * to_neccesary_unit / area << std::fixed << std::endl;
	}

	void printInform() const
	{
		printCountry();
		printCapital();
		printOfLanguage();
		printNatCurrency();
		printArea();
		printPopulation();
		printPopDensity();
	}

	~Lands() = default;

	square_km2 area;
	thousands_of_people population;
	std::string national_currency;
	std::string official_language;
	std::string capital;
	std::string country;

};

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
