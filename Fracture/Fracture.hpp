#ifndef _FRACTURE_H_
#define _FRACTURE_H_

#include <ostream>
class Fraction
{
private:
	int numerator{ 0 };
	int denumerator{ 0 };
public:
	constexpr int gcd(int numerator, int denumerator);
	constexpr Fraction(int numerator = 0, int denumerator = 1);
	constexpr Fraction(double number = 0.0);
	constexpr int num() const  { return numerator; }
	constexpr int denum() const { return denumerator; }

	constexpr Fraction operator+(const Fraction& rhs) const;
	constexpr Fraction operator-(const Fraction& rhs) const;
	constexpr Fraction operator*(const Fraction& rhs) const;
	constexpr Fraction operator/(const Fraction& rhs) const;

	constexpr Fraction& operator=(const Fraction& rhs);
	constexpr Fraction& operator+=(const Fraction& rhs);
	constexpr Fraction& operator-=(const Fraction& rhs);
	constexpr Fraction& operator*=(const Fraction& rhs);
	constexpr Fraction& operator/=(const Fraction& rhs);

	constexpr Fraction operator++();
	constexpr Fraction operator--();
	constexpr Fraction operator++(int);
	constexpr Fraction operator--(int);

	constexpr auto operator<=>(const Fraction& rhs) const;

	constexpr bool operator==(const Fraction& rhs) const = default;
	constexpr bool operator!=(const Fraction& rhs) const = default;
	constexpr bool operator>=(const Fraction& rhs) const;
	constexpr bool operator>(const Fraction& rhs) const;
	constexpr bool operator<=(const Fraction& rhs) const;
	constexpr bool operator<(const Fraction& rhs) const;

	constexpr operator double() const { return (double)numerator / denumerator; } 

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f);


constexpr Fraction::Fraction(int numerator, int denumerator) :
	numerator(numerator),
	denumerator(denumerator)
{
	int greatestcd = gcd(numerator, denumerator);
	if (greatestcd == 1)
		return;
	else
	{
		this->numerator /= greatestcd;
		this->denumerator /= greatestcd;
	}
}

constexpr Fraction::Fraction(double number)
{
	int i = 0;
	while ((int)number != number) // until number == x.0
	{
		number *= 10;
		i++;
	}
	*this = Fraction((int)number, (int)pow(10, i));
}

constexpr int Fraction::gcd(int valA, int valB)
{
	int r{};
	while (valB != 0)
	{
		r = valA % valB;
		valA = valB;
		valB = r;
	}
	return valA;
}

constexpr Fraction Fraction::operator+(const Fraction& rhs) const
{
	return Fraction{ numerator * rhs.denumerator + rhs.numerator * denumerator, denumerator * rhs.denumerator };
}

constexpr Fraction Fraction::operator-(const Fraction& rhs) const
{
	return Fraction{ numerator * rhs.denumerator - rhs.numerator * denumerator, denumerator * rhs.denumerator };
}

constexpr Fraction Fraction::operator*(const Fraction& rhs) const
{
	return Fraction{ numerator * rhs.numerator, denumerator * rhs.denumerator, };
}

constexpr Fraction Fraction::operator/(const Fraction& rhs) const
{
	return Fraction{ numerator * rhs.denumerator, denumerator * rhs.numerator, };
}



constexpr Fraction& Fraction::operator=(const Fraction& rhs)
{
	numerator = rhs.numerator;
	denumerator = rhs.denumerator;
	return *this;
}

constexpr Fraction& Fraction::operator+=(const Fraction& rhs)
{
	*this = *this + rhs;
	return *this;
}

constexpr Fraction& Fraction::operator-=(const Fraction& rhs)
{
	*this = *this - rhs;
	return *this;
}

constexpr Fraction& Fraction::operator*=(const Fraction& rhs)
{
	*this = *this * rhs;
	return *this;
}

constexpr Fraction& Fraction::operator/=(const Fraction& rhs)
{
	*this = *this / rhs;
	return *this;
}



constexpr Fraction Fraction::operator++()
{
	numerator += denumerator;
	return *this;
}

constexpr Fraction Fraction::operator--()
{
	numerator -= denumerator;
	return *this;
}

constexpr Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	++* this;
	return temp;
}

constexpr Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	--* this;
	return temp;
}




constexpr auto Fraction::operator<=>(const Fraction& rhs) const
{
	if (*this == rhs)
		return 0;
	else if (*this < rhs)
		return -1;
	else
		return 1;	
}

constexpr bool Fraction::operator>=(const Fraction& rhs) const
{
	return numerator * rhs.denumerator >= rhs.numerator * denumerator;
}

constexpr bool Fraction::operator>(const Fraction& rhs) const
{
	return numerator * rhs.denumerator > rhs.numerator * denumerator;
}

constexpr bool Fraction::operator<=(const Fraction& rhs) const
{
	return !(*this > rhs);
}

constexpr bool Fraction::operator<(const Fraction& rhs) const
{
	return !(*this >= rhs);
}



std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	if (f.denum() == 1)
		return out << f.num();
	else
		return out << [&]() {return f.denum() < 0 ? -1 * f.num() : f.num();}() << "/" << abs(f.denum());
}

#endif // !_FRACTURE_H_