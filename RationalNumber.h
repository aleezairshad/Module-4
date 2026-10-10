#pragma once
#include <iostream>
using namespace std;
class RationalNumber
{
private:
	int numerator;
	int denominator;

public:
	RationalNumber(); //default constructor
	//copy constructor
	RationalNumber(const RationalNumber& other);
    RationalNumber(int num, int denom); //constructor with numerator and denominator
	void setNumerator(int num); //setter for numerator
	void setDenominator(int denom); //setter for denominator
	int getNumerator() const; //getter for numerator
	int getDenominator() const; //getter for denominator
	int gcd(int a, int b) const; //function to calculate the greatest common divisor
    void normalize(); //function to normalize the rational number
    //void display() const; //function to display the rational number
	void negate(); //function to negate the rational number

	RationalNumber operator+(const RationalNumber& other) const; //overloaded + operator
	RationalNumber operator-(const RationalNumber& other) const; //overloaded - operator
	RationalNumber operator*(const RationalNumber& other) const; //overloaded * operator
	RationalNumber operator/(const RationalNumber& other) const; //overloaded / operator

	bool operator==(const RationalNumber& other) const; //overloaded == operator
	bool operator!=(const RationalNumber& other) const; //overloaded != operator
	bool operator<(const RationalNumber& other) const;  //overloaded < operator
	bool operator<=(const RationalNumber& other) const; //overloaded <= operator
	bool operator>(const RationalNumber& other) const;	//overloaded > operator
	bool operator>=(const RationalNumber& other) const; //overloaded >= operator

	//Thanh added this
	friend ostream& operator<<(ostream& out, const RationalNumber& rationalNumber);
};

