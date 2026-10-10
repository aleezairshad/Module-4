#include "RationalNumber.h"
#include <iostream>

using namespace std;
// precondition: none
// postcondition: initializes the numerator and denominator to 0 and 1 respectively
RationalNumber::RationalNumber()
{
	numerator = 0;
	denominator = 1;
}
// precondition: other is a valid RationalNumber object
// postcondition: initializes the numerator and denominator to the values of the other RationalNumber object
RationalNumber::RationalNumber(const RationalNumber& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}
// precondition: num and denom are valid integers
// postcondition: initializes the numerator and denominator to the given values
//Thanh modified this
//I don't want this constructor to do the validation
RationalNumber::RationalNumber(int num, int denom)
{
	numerator = num;
	denominator = denom;

	//denominator = (denom == 0) ? 1 : denom; // Prevent division by zero
}


//precondition: a and b are valid integers
//postcondition: returns the greatest common divisor of a and b using the Euclidean algorithm
int RationalNumber::gcd(int a, int b) const
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//precondition: none
//postcondition: normalizes the rational number by ensuring the denominator is positive and reducing the fraction to its simplest form
void RationalNumber::normalize()
{
	//Thanh modified this
	/*
	if (denominator == 0)
	{
		denominator = 1;
	}
	*/
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	int divisor = gcd(numerator, denominator);
	if (divisor != 0)
	{
		numerator /= divisor;
		denominator /= divisor;
	}
}
//precondition: num is a valid integer
//postcondition: sets the numerator to the given value
void RationalNumber::setNumerator(int num)
{
	numerator = num;
}
//precondition: denom is a valid integer
//postcondition: sets the denominator to the given value
//Thanh modified this
//I don't want setter and getter to modify or do validation
void RationalNumber::setDenominator(int denom)
{
	denominator = denom;
	//denominator = (denom == 0) ? 1 : denom; // Prevent division by zero
}
//precondition: none
//postcondition: returns the numerator of the rational number
int RationalNumber::getNumerator() const
{
	return numerator;
}
//precondition: none
//postcondition: returns the denominator of the rational number
int RationalNumber::getDenominator() const
{
	return denominator;
}
//precondition: none
//postcondition: displays the rational number in the form of "numerator/denominator"
/*
void RationalNumber::display() const
{
	cout << numerator << "/" << denominator;
}
*/
//precondition: none
//postcondition: negates the rational number by changing the sign of the numerator or denominator
void RationalNumber::negate()
{
	//Thanh added this
	if (denominator < 0 && numerator > 0) //fix negate error
	{
		denominator = -denominator;
	}
	else
	{
		numerator = -numerator;
	}
}
//precondition: other is a valid RationalNumber object
//postcondition: returns the sum of the current rational number and the other rational number
RationalNumber RationalNumber::operator+(const RationalNumber& other) const
{
	//Thanh added this part
	//This if statement is to return a RationalNumber object later shows undefined by operator<<
	//because one of the denominator is 0
	if (denominator == 0 || other.denominator == 0)
	{
		return RationalNumber(0, 0);
	}
	//end of adding
	int num = (numerator * other.denominator) + (other.numerator * denominator); // Cross-multiply to get a common denominator
	int denom = denominator * other.denominator; // Multiply the denominators to get the new denominator
	RationalNumber result(num, denom);
	result.normalize(); //Thanh "un-commented" this, it should normalize
	return result;
}
//precondition: other is a valid RationalNumber object
//postcondition: returns the difference of the current rational number and the other rational number
RationalNumber RationalNumber::operator-(const RationalNumber& other) const
{
	//Thanh added this part
	if (denominator == 0 || other.denominator == 0)
	{
		return RationalNumber(0, 0);
	}
	//end of adding
	int num = (numerator * other.denominator) - (other.numerator * denominator); // Cross-multiply to get a common denominator
	int denom = denominator * other.denominator; // Multiply the denominators to get the new denominator
	RationalNumber result(num, denom);
	result.normalize();
	return result;
}
//precondition: other is a valid RationalNumber object
//postcondition: returns the product of the current rational number and the other rational number
RationalNumber RationalNumber::operator*(const RationalNumber& other) const
{
	//Thanh added this part
	if (denominator == 0 || other.denominator == 0)
	{
		return RationalNumber(0, 0);
	}
	//end of adding
	int num = numerator * other.numerator; // Multiply the numerators
	int denom = denominator * other.denominator; // Multiply the denominators
	RationalNumber result(num, denom);
	result.normalize();
	return result;
}
//precondition: other is a valid RationalNumber object
//postcondition: returns the quotient of the current rational number and the other rational number
RationalNumber RationalNumber::operator/(const RationalNumber& other) const
{
	//Thanh added this part
	//For division, I need to validate the numerator too
	if (denominator == 0 || other.denominator == 0 || other.numerator == 0)
	{
		return RationalNumber(0, 0);
	}
	//end of adding
	int num = numerator * other.denominator; // Multiply the numerator by the reciprocal of the other fraction
	int denom = denominator * other.numerator; // Multiply the denominator by the reciprocal of the other fraction
	RationalNumber result(num, denom);
	result.normalize();
	return result;
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is equal to the other rational number, false otherwise
bool RationalNumber::operator==(const RationalNumber& other) const
{
	return (numerator * other.denominator) == (other.numerator * denominator); // Cross-multiply to compare fractions
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is not equal to the other rational number, false otherwise
bool RationalNumber::operator!=(const RationalNumber& other) const
{
	return !(*this == other); // Use the equality operator to determine inequality using *this which is the current object
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is less than the other rational number, false otherwise
bool RationalNumber::operator<(const RationalNumber& other) const
{
	return (numerator * other.denominator) < (other.numerator * denominator); // Cross-multiply to compare fractions
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is less than or equal to the other rational number, false otherwise
bool RationalNumber::operator<=(const RationalNumber& other) const
{
	return (numerator * other.denominator) <= (other.numerator * denominator); // Cross-multiply to compare fractions
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is greater than the other rational number, false otherwise
bool RationalNumber::operator>(const RationalNumber& other) const
{
	return (numerator * other.denominator) > (other.numerator * denominator); // Cross-multiply to compare fractions
}
//precondition: other is a valid RationalNumber object
//postcondition: returns true if the current rational number is greater than or equal to the other rational number, false otherwise
bool RationalNumber::operator>=(const RationalNumber& other) const
{
	return (numerator * other.denominator) >= (other.numerator * denominator); // Cross-multiply to compare fractions
}

//Thanh added this
//precondition: none
//postcondition: displays the rational number in the form of "numerator/denominator"
ostream& operator<<(ostream& out, const RationalNumber& rationalNumber)
{
	if (rationalNumber.denominator == 0)
	{
		out << "undefined";
	}
	else
	{
		out << rationalNumber.numerator << "/" << rationalNumber.denominator;
	}
	return out;
}