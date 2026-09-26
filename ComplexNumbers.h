#pragma once
#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
    double real;
    double imaginary;
public:
    // Constructors
    ComplexNumbers();
    ComplexNumbers(double real, double imaginary);
    // Mutators
    void setReal(double real);
    void setImaginary(double imaginary);
    // Accessors
    double getReal() const;
    double getImaginary() const;
    // Arithmetic operators with another complex number
    ComplexNumbers operator+(const ComplexNumbers& other) const;
    ComplexNumbers operator-(const ComplexNumbers& other) const;
    ComplexNumbers operator*(const ComplexNumbers& other) const;
    ComplexNumbers operator/(const ComplexNumbers& other) const;
    // Unary negation
    ComplexNumbers operator-() const;
    // Arithmetic operators with a constant
    ComplexNumbers operator+(double constant) const;
    ComplexNumbers operator-(double constant) const;
    ComplexNumbers operator*(double constant) const;
    ComplexNumbers operator/(double constant) const;
    // Comparison operators
    bool operator==(const ComplexNumbers& other) const;
    bool operator!=(const ComplexNumbers& other) const;
    // Output operator
    friend ostream& operator<<(ostream& out, const ComplexNumbers& number);
    // Addition: constant + complex number
    friend ComplexNumbers operator+(double constant, const ComplexNumbers& number);
    // Subtraction: constant - complex number
    friend ComplexNumbers operator-(double constant, const ComplexNumbers& number);
    friend ComplexNumbers operator*(double constant, const ComplexNumbers& number);
    // value / C2
    friend ComplexNumbers operator/(double constant, const ComplexNumbers& number);
};