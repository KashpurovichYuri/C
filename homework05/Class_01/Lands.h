#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Lands
{
	using square_km2 = int;
	using thousands_of_people = int;

public:

	Lands() = default;

	Lands(int area
		, int population
		, const std::string& national_currency
		, const std::string& official_language
		, const std::string& capital
		, const std::string& country)
		: area { area }
		, population { population }
		, national_currency { national_currency }
		, official_language { official_language }
		, capital { capital }
		, country { country }
	{

	}

	~Lands() = default;

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

	void printPopDensity() const;
	void printInform() const;

private:
	static constexpr auto to_neccesary_unit { 1000 };
	square_km2 area;
	thousands_of_people population;
	std::string national_currency;
	std::string official_language;
	std::string capital;
	std::string country;
};
