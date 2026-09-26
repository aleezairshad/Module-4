#include "ComplexNumbers.h"

// Default constructor
ComplexNumbers::ComplexNumbers()
{
    real = 0.0;
    imaginary = 0.0;
}


// Constructor
ComplexNumbers::ComplexNumbers(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}


// Set real part
void ComplexNumbers::setReal(double real)
{
    this->real = real;
}


// Set imaginary part
void ComplexNumbers::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}


// Get real part
double ComplexNumbers::getReal() const
{
    return real;
}


// Get imaginary part
double ComplexNumbers::getImaginary() const
{
    return imaginary;
}


// Addition with another complex number
ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other) const
{
    return ComplexNumbers(
        real + other.real,
        imaginary + other.imaginary
    );
}


// Subtraction with another complex number
ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& other) const
{
    return ComplexNumbers(
        real - other.real,
        imaginary - other.imaginary
    );
}


// Multiplication with another complex number
ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& other) const
{
    double newReal =
        (real * other.real) -
        (imaginary * other.imaginary);

    double newImaginary =
        (real * other.imaginary) +
        (imaginary * other.real);

    return ComplexNumbers(newReal, newImaginary);
}


// Division with another complex number
ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& other) const
{
    double denominator =
        (other.real * other.real) +
        (other.imaginary * other.imaginary);

    double newReal =
        ((real * other.real) +
            (imaginary * other.imaginary))
        / denominator;

    double newImaginary =
        ((imaginary * other.real) -
            (real * other.imaginary))
        / denominator;

    return ComplexNumbers(newReal, newImaginary);
}


// Unary negation
ComplexNumbers ComplexNumbers::operator-() const
{
    return ComplexNumbers(-real, -imaginary);
}


// Addition with a constant
ComplexNumbers ComplexNumbers::operator+(double constant) const
{
    return ComplexNumbers(
        real + constant,
        imaginary
    );
}


// Subtraction with a constant
ComplexNumbers ComplexNumbers::operator-(double constant) const
{
    return ComplexNumbers(
        real - constant,
        imaginary
    );
}


// Multiplication with a constant
ComplexNumbers ComplexNumbers::operator*(double constant) const
{
    return ComplexNumbers(real * constant, imaginary * constant);
}


// Division with a constant
ComplexNumbers ComplexNumbers::operator/(double constant) const
{
    return ComplexNumbers(real / constant, imaginary / constant);
}


// Equal
bool ComplexNumbers::operator==(const ComplexNumbers& other) const
{
    return real == other.real && imaginary == other.imaginary;
}


// Not equal
bool ComplexNumbers::operator!=(const ComplexNumbers& other) const
{
    return !(*this == other);
}


// Display complex number
ostream& operator<<(ostream& out, const ComplexNumbers& number)
{
    if (number.real == 0.0 && number.imaginary == 0.0)
    {
        out << 0;
        return out;
    }

    if (number.real == 0.0)
    {
        out << number.imaginary << "i";
        return out;
    }

    out << number.real;

    if (number.imaginary > 0.0)
        out << " + " << number.imaginary << "i";
    else if (number.imaginary < 0.0)
        out << " - " << -number.imaginary << "i";

    return out;
}

// Addition: constant + complex number
ComplexNumbers operator+(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant + number.real, number.imaginary);
}

// Subtraction: constant - complex number
ComplexNumbers operator-(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant - number.real, -number.imaginary);
}

// value * C2
ComplexNumbers operator*(double constant, const ComplexNumbers& number)
{
    return number * constant;
}
// value / C2
ComplexNumbers operator/(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant, 0.0) / number;
}
