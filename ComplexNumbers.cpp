#include "ComplexNumbers.h"

// Default constructor
//precondition: none
//postcondition: initializes the real and imaginary parts of the complex number to 0.0
ComplexNumbers::ComplexNumbers()
{
    real = 0.0;
    imaginary = 0.0;
}


//precondition: real and imaginary are valid double values
//postcondition: initializes the real and imaginary parts of the complex number to the given values
ComplexNumbers::ComplexNumbers(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}


//precondition: real is a valid double value
//postcondition: sets the real part of the complex number to the given value
void ComplexNumbers::setReal(double real)
{
    this->real = real;
}


//precondition: imaginary is a valid double value
//postcondition: sets the imaginary part of the complex number to the given value
void ComplexNumbers::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}


//precondition: none
//postcondition: returns the real part of the complex number
double ComplexNumbers::getReal() const
{
    return real;
}


//precondition: none
//postcondition: returns the imaginary part of the complex number
double ComplexNumbers::getImaginary() const
{
    return imaginary;
}


//precondition: other is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the sum of the current complex number and the other complex number
ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other) const
{
    return ComplexNumbers(real + other.real, imaginary + other.imaginary);
}


//precondition: other is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the difference between the current complex number and the other complex number
ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& other) const
{
    return ComplexNumbers(real - other.real, imaginary - other.imaginary);
}


//precondition: other is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the product of the current complex number and the other complex number
ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& other) const
{
    double newReal = (real * other.real) - (imaginary * other.imaginary);
    double newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return ComplexNumbers(newReal, newImaginary);
}


//precondition: other is a valid ComplexNumbers object and not equal to zero
//postcondition: returns a new ComplexNumbers object representing the quotient of the current complex number and the other complex number
ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& other) const
{
    double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    double newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return ComplexNumbers(newReal, newImaginary);
}


//precondition: none
//postcondition: returns a new ComplexNumbers object representing the negation of the current complex number
ComplexNumbers ComplexNumbers::operator-() const
{
    return ComplexNumbers(-real, -imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumbers object representing the sum of the current complex number and the constant
ComplexNumbers ComplexNumbers::operator+(double constant) const
{
    return ComplexNumbers( real + constant, imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumbers object representing the difference between the current complex number and the constant
ComplexNumbers ComplexNumbers::operator-(double constant) const
{
    return ComplexNumbers(real - constant, imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumbers object representing the product of the current complex number and the constant
ComplexNumbers ComplexNumbers::operator*(double constant) const
{
    return ComplexNumbers(real * constant, imaginary * constant);
}


//precondition: constant is a valid double value and not equal to zero
//postcondition: returns a new ComplexNumbers object representing the quotient of the current complex number and the constant
ComplexNumbers ComplexNumbers::operator/(double constant) const
{
    return ComplexNumbers(real / constant, imaginary / constant);
}


//precondition: other is a valid ComplexNumbers object
//postcondition: returns true if the current complex number is equal to the other complex number, false otherwise 
bool ComplexNumbers::operator==(const ComplexNumbers& other) const
{
    return real == other.real && imaginary == other.imaginary;
}


//precondition: other is a valid ComplexNumbers object
//postcondition: returns true if the current complex number is not equal to the other complex number, false otherwise
bool ComplexNumbers::operator!=(const ComplexNumbers& other) const
{
    return !(*this == other);
}


//precondition: out is a valid ostream object and number is a valid ComplexNumbers object
//postcondition: inserts the complex number into the output stream in the form "a + bi" or "a - bi"
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

//precondition: constant is a valid double value and number is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the sum of the constant and the complex number
ComplexNumbers operator+(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant + number.real, number.imaginary);
}

//precondition: constant is a valid double value and number is a valid ComplexNumbers object
ComplexNumbers operator-(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant - number.real, -number.imaginary);
}

//precondition: constant is a valid double value and number is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the product of the constant and the complex number
ComplexNumbers operator*(double constant, const ComplexNumbers& number)
{
    return number * constant;
}

//precondition: constant is a valid double value and number is a valid ComplexNumbers object
//postcondition: returns a new ComplexNumbers object representing the quotient of the constant and the complex number
ComplexNumbers operator/(double constant, const ComplexNumbers& number)
{
    return ComplexNumbers(constant / number.real, constant / number.imaginary);
}
