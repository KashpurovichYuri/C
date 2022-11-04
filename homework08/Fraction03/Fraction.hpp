#pragma once

#include <iostream>
#include <exception>
#include <string>

namespace frn
{
	class Fraction;
}

class frn::Fraction
{
public:

	Fraction(int n=0, int d=1);

	Fraction(const Fraction& frac) = default;

	Fraction(Fraction&& frac) = default;

	~Fraction() = default;

	Fraction& operator= (const Fraction& frac) = default;

	Fraction& operator= (Fraction&& frac) = default;

	Fraction& operator+= (const Fraction& frac);
	Fraction& operator-= (const Fraction& frac);
	Fraction& operator*= (const Fraction& frac);
	Fraction& operator/= (const Fraction& frac);
	Fraction& operator++ ();
	Fraction& operator-- ();
	Fraction operator++ (int);
	Fraction operator-- (int);

	explicit operator double() const;

	friend std::ostream& operator<< (std::ostream& stream, const Fraction& frac);
	friend std::istream& operator>> (std::istream& stream, Fraction& frac);
	friend bool operator== (const Fraction& lhs, const Fraction& rhs);
	friend bool operator!= (const Fraction& lhs, const Fraction& rhs);
	friend bool operator> (const Fraction& lhs, const Fraction& rhs);
	friend bool operator< (const Fraction& lhs, const Fraction& rhs);
	friend bool operator>= (const Fraction& lhs, const Fraction& rhs);
	friend bool operator<= (const Fraction& lhs, const Fraction& rhs);

	auto GetNominator() const
	{
		return nominator;
	}

	auto GetDenominator() const
	{
		return denominator;
	}

	class FractionError;
	
private:
	void sign();
	void reduction();

	int nominator;
	int denominator;
};

class frn::Fraction::FractionError: public std::exception
{
public:

	FractionError() = default;

	explicit FractionError(const char* strerr);

	virtual const char* what() const noexcept override;

private:
	const char* what_arg;
};

namespace frn
{
	Fraction operator+ (const Fraction& frac1, const Fraction& frac2);
	Fraction operator- (const Fraction& frac1, const Fraction& frac2);
	Fraction operator* (const Fraction& frac1, const Fraction& frac2);
	Fraction operator/ (const Fraction& frac1, const Fraction& frac2);
}
