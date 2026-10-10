#include "ComplexNumber.h"

// Default constructor
//precondition: none
//postcondition: initializes the real and imaginary parts of the complex number to 0.0
ComplexNumber::ComplexNumber()
{
    real = 0.0;
    imaginary = 0.0;
}


//precondition: real and imaginary are valid double values
//postcondition: initializes the real and imaginary parts of the complex number to the given values
ComplexNumber::ComplexNumber(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}


//precondition: real is a valid double value
//postcondition: sets the real part of the complex number to the given value
void ComplexNumber::setReal(double real)
{
    this->real = real;
}


//precondition: imaginary is a valid double value
//postcondition: sets the imaginary part of the complex number to the given value
void ComplexNumber::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}


//precondition: none
//postcondition: returns the real part of the complex number
double ComplexNumber::getReal() const
{
    return real;
}


//precondition: none
//postcondition: returns the imaginary part of the complex number
double ComplexNumber::getImaginary() const
{
    return imaginary;
}


//precondition: other is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the sum of the current complex number and the other complex number
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}


//precondition: other is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the difference between the current complex number and the other complex number
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}


//precondition: other is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the product of the current complex number and the other complex number
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    double newReal = (real * other.real) - (imaginary * other.imaginary);
    double newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return ComplexNumber(newReal, newImaginary);
}


//precondition: other is a valid ComplexNumber object and not equal to zero
//postcondition: returns a new ComplexNumber object representing the quotient of the current complex number and the other complex number
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const
{
    double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    double newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return ComplexNumber(newReal, newImaginary);
}


//precondition: none
//postcondition: returns a new ComplexNumber object representing the negation of the current complex number
ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-real, -imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumber object representing the sum of the current complex number and the constant
ComplexNumber ComplexNumber::operator+(double constant) const
{
    return ComplexNumber(real + constant, imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumber object representing the difference between the current complex number and the constant
ComplexNumber ComplexNumber::operator-(double constant) const
{
    return ComplexNumber(real - constant, imaginary);
}


//precondition: constant is a valid double value
//postcondition: returns a new ComplexNumber object representing the product of the current complex number and the constant
ComplexNumber ComplexNumber::operator*(double constant) const
{
    return ComplexNumber(real * constant, imaginary * constant);
}


//precondition: constant is a valid double value and not equal to zero
//postcondition: returns a new ComplexNumber object representing the quotient of the current complex number and the constant
ComplexNumber ComplexNumber::operator/(double constant) const
{
    return ComplexNumber(real / constant, imaginary / constant);
}


//precondition: other is a valid ComplexNumber object
//postcondition: returns true if the current complex number is equal to the other complex number, false otherwise 
bool ComplexNumber::operator==(const ComplexNumber& other) const
{
    return real == other.real && imaginary == other.imaginary;
}


//precondition: other is a valid ComplexNumber object
//postcondition: returns true if the current complex number is not equal to the other complex number, false otherwise
bool ComplexNumber::operator!=(const ComplexNumber& other) const
{
    return !(*this == other);
}


//precondition: constant is a valid double value and number is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the sum of the constant and the complex number
ComplexNumber operator+(double constant, const ComplexNumber& number)
{
    return ComplexNumber(constant + number.real, number.imaginary);
}

//precondition: constant is a valid double value and number is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the product of the constant and the complex number
ComplexNumber operator-(double constant, const ComplexNumber& number)
{
    return ComplexNumber(constant - number.real, -number.imaginary);
}

//precondition: constant is a valid double value and number is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the product of the constant and the complex number
ComplexNumber operator*(double constant, const ComplexNumber& number)
{
    return number * constant;
}

//precondition: constant is a valid double value and number is a valid ComplexNumber object
//postcondition: returns a new ComplexNumber object representing the quotient of the constant and the complex number
ComplexNumber operator/(double constant, const ComplexNumber& number)
{
    //Thanh added this
    double denominator = (number.real * number.real) + (number.imaginary * number.imaginary);

    double newReal = (constant * number.real) / denominator;
    double newImaginary = (-constant * number.imaginary) / denominator;

    return ComplexNumber(newReal, newImaginary);
    //Original - wrong
    //return ComplexNumber(constant / number.real, constant / number.imaginary);
}


//precondition: out is a valid ostream object and number is a valid ComplexNumber object
//postcondition: inserts the complex number into the output stream in the form "a + bi" or "a - bi"
ostream& operator<<(ostream& out, const ComplexNumber& complexNumber)
{
    if (complexNumber.real == 0.0 && complexNumber.imaginary == 0.0)
    {
        out << 0;
        return out;
    }

    if (complexNumber.real == 0.0)
    {
        //Thanh added something here!!
        if (complexNumber.imaginary == 1)
        {
            out << "i";
        }
        else if (complexNumber.imaginary == -1)
        {
            out << "-i";
        }
        else
        {
            out << complexNumber.imaginary << "i";
        }
        //end of amendment

        return out;

        //original
        //out << number.imaginary << "i";
        //return out;
    }

    out << complexNumber.real;

    //Thanh added something here!!
    if (complexNumber.imaginary > 0.0)
    {
        if (complexNumber.imaginary == 1)
        {
            out << " + i";
        }
        else
        {
            out << " + " << complexNumber.imaginary << "i";
        }
    }
    else if (complexNumber.imaginary < 0.0)
    {
        if (complexNumber.imaginary == -1)
        {
            out << " - i";
        }
        else
        {
            out << " - " << -complexNumber.imaginary << "i";
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
