#pragma once

#include <iostream>

class Fraction;
Fraction operator+ (const Fraction& frac1, const Fraction& frac2);
Fraction operator- (const Fraction& frac1, const Fraction& frac2);
Fraction operator* (const Fraction& frac1, const Fraction& frac2);
Fraction operator/ (const Fraction& frac1, const Fraction& frac2);

class Fraction
{
public:

	explicit Fraction(int n=0, int d=1);

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

	operator double() const;

	friend std::ostream& operator<< (std::ostream& stream, const Fraction& frac);
	friend std::istream& operator>> (std::istream& stream, Fraction& frac);
	friend bool operator== (const Fraction& lhs, const Fraction& rhs);
	friend bool operator!= (const Fraction& lhs, const Fraction& rhs);
	friend bool operator> (const Fraction& lhs, const Fraction& rhs);
	friend bool operator< (const Fraction& lhs, const Fraction& rhs);
	friend bool operator>= (const Fraction& lhs, const Fraction& rhs);
	friend bool operator<= (const Fraction& lhs, const Fraction& rhs);

	int GetNominator() const;
	int GetDenominator() const;

private:
	void reduction();

	int nominator;
	int denominator;
};
