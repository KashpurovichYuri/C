#include <iostream>

class EnergyJoules
{
	public:
		EnergyJoules(double value=0) : joules{ value }
		{

		}

		~EnergyJoules() = default;

		double GetJoules() const
		{
			return joules;
		}

		double GetErgs() const
		{
			return joules * joules_to_ergs;
		}

		double GetEVs() const
		{
			return joules * joules_to_eVs;
		}

		void ReadJoules(double value)
		{
			joules = value;
		}

		void ReadErgs(double value)
		{
			joules = value / joules_to_ergs;
		}

		void ReadEVs(double value)
		{
			joules = value / joules_to_eVs;
		}

	private:
		double joules;
		static constexpr auto joules_to_ergs { 1e+7 };
		static constexpr auto joules_to_eVs { 6.25e+18 };
};

int main()
{
	EnergyJoules energy;
	energy.ReadJoules(10);
	std::cout << energy.GetJoules() << ", " << energy.GetErgs() << ", " << energy.GetEVs() << std::endl;
	energy.ReadEVs(100);
	std::cout << energy.GetJoules() << ", " << energy.GetErgs() << ", " << energy.GetEVs() << std::endl;
	energy.ReadErgs(1000);
	std::cout << energy.GetJoules() << ", " << energy.GetErgs() << ", " << energy.GetEVs() << std::endl;
}
