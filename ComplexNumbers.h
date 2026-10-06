#pragma once
#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
	double real; // Real part of the complex number
	double imaginary; // Imaginary part of the complex number
public:
    // Constructors
	ComplexNumbers(); // Default constructor
	ComplexNumbers(double real, double imaginary); // Constructor with parameters 
    // Mutators
	void setReal(double real); // Set the real part of the complex number
	void setImaginary(double imaginary); // Set the imaginary part of the complex number
    // Accessors
	double getReal() const; // Get the real part of the complex number
	double getImaginary() const; // Get the imaginary part of the complex number
    // Arithmetic operators with another complex number
	ComplexNumbers operator+(const ComplexNumbers& other) const; // Addition
	ComplexNumbers operator-(const ComplexNumbers& other) const; // Subtraction
	ComplexNumbers operator*(const ComplexNumbers& other) const; // Multiplication
	ComplexNumbers operator/(const ComplexNumbers& other) const; // Division
    // Unary negation
	ComplexNumbers operator-() const; // Negation
    // Arithmetic operators with a constant
	ComplexNumbers operator+(double constant) const; // Addition
	ComplexNumbers operator-(double constant) const; // Subtraction
	ComplexNumbers operator*(double constant) const; // Multiplication
	ComplexNumbers operator/(double constant) const; // Division
    // Comparison operators
	bool operator==(const ComplexNumbers& other) const; // Equality 
	bool operator!=(const ComplexNumbers& other) const; // Inequality
    // Output operator
	friend ostream& operator<<(ostream& out, const ComplexNumbers& number); // Output
    // Addition: constant + complex number
	friend ComplexNumbers operator+(double constant, const ComplexNumbers& number); // Addition: constant + complex number
    // Subtraction: constant - complex number
	friend ComplexNumbers operator-(double constant, const ComplexNumbers& number); // Subtraction: constant - complex number
	friend ComplexNumbers operator*(double constant, const ComplexNumbers& number); // Multiplication: constant * complex number
    // value / C2
	friend ComplexNumbers operator/(double constant, const ComplexNumbers& number); // Division: constant / complex number
};