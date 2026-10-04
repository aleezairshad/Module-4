#include "ComplexNumber.h"

// Default constructor
ComplexNumber::ComplexNumber()
{
    real = 0.0;
    imaginary = 0.0;
}


// Constructor
ComplexNumber::ComplexNumber(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}


// Set real part
void ComplexNumber::setReal(double real)
{
    this->real = real;
}


// Set imaginary part
void ComplexNumber::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}


// Get real part
double ComplexNumber::getReal() const
{
    return real;
}


// Get imaginary part
double ComplexNumber::getImaginary() const
{
    return imaginary;
}


// Addition with another complex number
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    return ComplexNumber(
        real + other.real,
        imaginary + other.imaginary
    );
}


// Subtraction with another complex number
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    return ComplexNumber(
        real - other.real,
        imaginary - other.imaginary
    );
}


// Multiplication with another complex number
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    double newReal =
        (real * other.real) -
        (imaginary * other.imaginary);

    double newImaginary =
        (real * other.imaginary) +
        (imaginary * other.real);

    return ComplexNumber(newReal, newImaginary);
}


// Division with another complex number
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const
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

    return ComplexNumber(newReal, newImaginary);
}


// Unary negation
ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-real, -imaginary);
}


// Addition with a constant
ComplexNumber ComplexNumber::operator+(double constant) const
{
    return ComplexNumber(
        real + constant,
        imaginary
    );
}


// Subtraction with a constant
ComplexNumber ComplexNumber::operator-(double constant) const
{
    return ComplexNumber(
        real - constant,
        imaginary
    );
}


// Multiplication with a constant
ComplexNumber ComplexNumber::operator*(double constant) const
{
    return ComplexNumber(real * constant, imaginary * constant);
}


// Division with a constant
ComplexNumber ComplexNumber::operator/(double constant) const
{
    return ComplexNumber(real / constant, imaginary / constant);
}


// Equal
bool ComplexNumber::operator==(const ComplexNumber& other) const
{
    return real == other.real && imaginary == other.imaginary;
}


// Not equal
bool ComplexNumber::operator!=(const ComplexNumber& other) const
{
    return !(*this == other);
}


// Display complex number
ostream& operator<<(ostream& out, const ComplexNumber& number)
{
    if (number.real == 0.0 && number.imaginary == 0.0)
    {
        out << 0;
        return out;
    }

    if (number.real == 0.0)
    {
        //Thanh added something here!!
        if (number.imaginary == 1)
        {
            out << "i";
        }
        else if (number.imaginary == -1)
        {
            out << "-i";
        }
        else
        {
            out << number.imaginary << "i";
        }
        //end of amendment

        return out;

        //original
        //out << number.imaginary << "i";
        //return out;
    }

    out << number.real;

    //Thanh added something here!!
    if (number.imaginary > 0.0)
    {
        if (number.imaginary == 1)
        {
            out << " + i";
        }
        else
        {
            out << " + " << number.imaginary << "i";
        }
    }
    else if (number.imaginary < 0.0)
    {
        if (number.imaginary == -1)
        {
            out << " - i";
        }
        else
        {
            out << " - " << -number.imaginary << "i";
        }
    }
    //end of amendment

    //original
    /*
        if (number.imaginary > 0.0)
        out << " + " << number.imaginary << "i";
    else if (number.imaginary < 0.0)
        out << " - " << -number.imaginary << "i";
    */
    return out;
}

// Addition: constant + complex number
ComplexNumber operator+(double constant, const ComplexNumber& number)
{
    return ComplexNumber(constant + number.real, number.imaginary);
}

// Subtraction: constant - complex number
ComplexNumber operator-(double constant, const ComplexNumber& number)
{
    return ComplexNumber(constant - number.real, -number.imaginary);
}

// value * C2
ComplexNumber operator*(double constant, const ComplexNumber& number)
{
    return number * constant;
}
// value / C2
ComplexNumber operator/(double constant, const ComplexNumber& number)
{
    return ComplexNumber(constant, 0.0) / number;
}
