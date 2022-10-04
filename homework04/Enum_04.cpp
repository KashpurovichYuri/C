#include <iostream>

int DaysInMonth(int num_of_month)
{

	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December,
	};

	switch (static_cast<Month>(num_of_month))
	{
		case Month::February:
			return 27;

		case Month::April:
		case Month::June:
		case Month::September:
		case Month::November:
			return 30;

		case Month::January:
		case Month::March:
		case Month::May:
		case Month::July:
		case Month::August:		
		case Month::October:
		case Month::December:
			return 31;

		default:
			return 0;
	}

}

int main()
{
	int num_of_month; // obviously name of month can be converted to integral value 0..12
	std::cin >> num_of_month;

	int ans { DaysInMonth(num_of_month) };
	if (ans != 27)
		std::cout << ans;
	else
	{
		std::cout << ans << " days at non bissextile year and " << ans + 1 << " days at bissextile";
	}
}