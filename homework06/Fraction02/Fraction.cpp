#include "Fraction.hpp"
#include <iostream>
#include <cstdlib>
#include <numeric>

namespace frn
{
	Fraction::Fraction(int n, int d): nominator { n }, denominator { d }
	{
		if (d == 0)
			std::cout << "Check denominator: zero 0 division" << std::endl;

		sign();
		reduction();
	}

	void Fraction::sign()
	{
		if (denominator == 0)
			nominator = 0;
		else if (nominator == 0)
			denominator = 1;
		else if (denominator < 0)
		{
			nominator = -nominator;
			denominator = -denominator;
		}
	}

	void Fraction::reduction()
	{	
		int gcd { std::gcd(nominator, denominator) };
		nominator /= gcd;
		denominator /= gcd;
	}

	Fraction& Fraction::operator+= (const Fraction& frac)
	{
		nominator = nominator * frac.GetDenominator() + frac.GetNominator() * denominator;
		denominator = denominator * frac.GetDenominator();
		sign();
		reduction();

		return *this;
	}

	Fraction& Fraction::operator-= (const Fraction& frac)
	{
		nominator = nominator * frac.GetDenominator() - frac.GetNominator() * denominator;
		denominator = denominator * frac.GetDenominator();
		sign();
		reduction();

		return *this;
	}

	Fraction& Fraction::operator*= (const Fraction& frac)
	{
		nominator = nominator * frac.GetNominator();
		denominator = denominator * frac.GetDenominator();
		sign();
		reduction();

		return *this;
	}

	Fraction& Fraction::operator/= (const Fraction& frac)
	{
		nominator = nominator * frac.GetDenominator();
		denominator = denominator * frac.GetNominator();
		sign();
		reduction();

		return *this;
	}

	Fraction& Fraction::operator++ ()
	{
		nominator += denominator;
		sign();

		return *this;
	}

	Fraction& Fraction::operator-- ()
	{
		nominator -= denominator;
		sign();

		return *this;
	}

	Fraction Fraction::operator++ (int)
	{
		Fraction frac { *this };

		++(*this);

		return frac;
	}

	Fraction Fraction::operator-- (int)
	{
		Fraction frac { *this };

		--(*this);

		return frac;
	}

	Fraction::operator double() const
	{ 
		return static_cast<double>(nominator) / static_cast<double>(denominator);
	}

	std::ostream& operator<< (std::ostream& stream, const Fraction& frac)
	{
		stream << frac.nominator << "/" << frac.denominator;
		return stream;
	}

	std::istream& operator>> (std::istream& stream, Fraction& frac)
	{
		stream >> frac.nominator;
		stream >> frac.denominator;
		if (frac.denominator == 0)
			std::cout << "Check denominator: zero 0 division" << std::endl;

		frac.sign();
		frac.reduction();

		return stream;
	}

	bool operator== (const Fraction& lhs, const Fraction& rhs)
	{
		return (lhs.nominator == rhs.nominator && lhs.denominator == rhs.denominator);
	}

	bool operator!= (const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator> (const Fraction& lhs, const Fraction& rhs)
	{
		return ((lhs - rhs).nominator > 0);
	}

	bool operator< (const Fraction& lhs, const Fraction& rhs)
	{
		return (operator>(rhs, lhs));
	}

	bool operator>= (const Fraction& lhs, const Fraction& rhs)
	{
		return !(operator<(lhs, rhs));
	}

	bool operator<= (const Fraction& lhs, const Fraction& rhs)
	{
		return !(operator>(lhs, rhs));
	}

	Fraction operator+ (const Fraction& frac1, const Fraction& frac2)
	{
		return Fraction(frac1) += frac2;
	}

	Fraction operator- (const Fraction& frac1, const Fraction& frac2)
	{
		return Fraction(frac1) -= frac2;
	}

	Fraction operator* (const Fraction& frac1, const Fraction& frac2)
	{
		return Fraction(frac1) *= frac2;
	}

	Fraction operator/ (const Fraction& frac1, const Fraction& frac2)
	{
		return Fraction(frac1) /= frac2;
	}

}
