#include <iostream>

int DaysInMonth(int r_month)
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

	switch (static_cast<Month>(r_month))
	{
		case Month::January:
			return 31;
		case Month::February:
			return 27;
		case Month::March:
			return 30;
		case Month::April:
			return 30;
		case Month::May:
			return 31;
		case Month::June:
			return 30;
		case Month::July:
			return 31;
		case Month::August:
			return 31;
		case Month::September:
			return 30;
		case Month::October:
			return 31;
		case Month::November:
			return 30;
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