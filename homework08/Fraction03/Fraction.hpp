#pragma once

#include <iostream>
#include <exception>
#include <string>

namespace frn
{
	class Fraction
	{
	public:

		Fraction(int n=0, int d=1);

		Fraction(const Fraction& frac) noexcept = default;

		Fraction(Fraction&& frac) noexcept = default;

		~Fraction() noexcept = default;

		Fraction& operator= (const Fraction& frac) noexcept = default;

		Fraction& operator= (Fraction&& frac) noexcept = default;

		Fraction& operator+= (const Fraction& frac);
		Fraction& operator-= (const Fraction& frac);
		Fraction& operator*= (const Fraction& frac);
		Fraction& operator/= (const Fraction& frac);
		Fraction& operator++ () noexcept;
		Fraction& operator-- () noexcept;
		Fraction operator++ (int) noexcept;
		Fraction operator-- (int) noexcept;

		explicit operator double() const noexcept;

		friend std::ostream& operator<< (std::ostream& stream, const Fraction& frac) noexcept;
		friend std::istream& operator>> (std::istream& stream, Fraction& frac);
		friend bool operator== (const Fraction& lhs, const Fraction& rhs);
		friend bool operator!= (const Fraction& lhs, const Fraction& rhs);
		friend bool operator> (const Fraction& lhs, const Fraction& rhs);
		friend bool operator< (const Fraction& lhs, const Fraction& rhs);
		friend bool operator>= (const Fraction& lhs, const Fraction& rhs);
		friend bool operator<= (const Fraction& lhs, const Fraction& rhs);

		auto GetNominator() const noexcept
		{
			return nominator;
		}

		auto GetDenominator() const noexcept
		{
			return denominator;
		}

		class FractionError;
		
	private:
		void sign();
		void reduction() noexcept;

		int nominator;
		int denominator;
	};
}
class frn::Fraction::FractionError: public std::exception
{
public:

	FractionError() noexcept = default;

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
