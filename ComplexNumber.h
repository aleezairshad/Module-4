#pragma once
#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    double real;
    double imaginary;
public:
    // Constructors
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    // Mutators
    void setReal(double real);
    void setImaginary(double imaginary);
    // Accessors
    double getReal() const;
    double getImaginary() const;
    // Arithmetic operators with another complex number
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;
    // Unary negation
    ComplexNumber operator-() const;
    // Arithmetic operators with a constant
    ComplexNumber operator+(double constant) const;
    ComplexNumber operator-(double constant) const;
    ComplexNumber operator*(double constant) const;
    ComplexNumber operator/(double constant) const;
    // Comparison operators
    bool operator==(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;
    // Output operator
    friend ostream& operator<<(ostream& out, const ComplexNumber& number);
    // Addition: constant + complex number
    friend ComplexNumber operator+(double constant, const ComplexNumber& number);
    // Subtraction: constant - complex number
    friend ComplexNumber operator-(double constant, const ComplexNumber& number);
    friend ComplexNumber operator*(double constant, const ComplexNumber& number);
    // value / C2
    friend ComplexNumber operator/(double constant, const ComplexNumber& number);
};