#include "Fraction.hpp"
#include <iostream>
#include <cstdlib>

Fraction::Fraction(int n, int d): nominator { n }, denominator { d }
{
	reduction();
}

void Fraction::reduction()
{
	if (denominator < 0)
	{
		nominator = -nominator;
		denominator = -denominator;
	}

	if (nominator != 0)
		while (nominator % 2 == 0 && denominator % 2 == 0)
		{
			nominator /= 2;
			denominator /= 2;
		}
	else
		denominator = 1;

	int min = (abs(nominator) < denominator ? abs(nominator) : denominator);
	if (nominator != 0)
		for (int i = 3; i <= min; i+=2)
		{
			if (nominator % i == 0 && denominator % i == 0)
			{
				std::cout << min << std::endl;
				nominator /= i;
				denominator /= i;
			}
		}
	else
		denominator = 1;
}

Fraction& Fraction::operator+= (const Fraction& frac)
{
	nominator = nominator * frac.GetDenominator() + frac.GetNominator() * denominator;
	denominator = denominator * frac.GetDenominator();
	reduction();

	return *this;
}

Fraction& Fraction::operator-= (const Fraction& frac)
{
	nominator = nominator * frac.GetDenominator() - frac.GetNominator() * denominator;
	denominator = denominator * frac.GetDenominator();
	reduction();

	return *this;
}

Fraction& Fraction::operator*= (const Fraction& frac)
{
	nominator = nominator * frac.GetNominator();
	denominator = denominator * frac.GetDenominator();
	reduction();

	return *this;
}

Fraction& Fraction::operator/= (const Fraction& frac)
{
	nominator = nominator * frac.GetDenominator();
	denominator = denominator * frac.GetNominator();
	reduction();

	return *this;
}

Fraction& Fraction::operator++ ()
{
	nominator += denominator;

	return *this;
}

Fraction& Fraction::operator-- ()
{
	nominator -= denominator;

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

int Fraction::GetNominator() const
{
	return nominator;
}

int Fraction::GetDenominator() const
{
	return denominator;
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
