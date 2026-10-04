#include "Polynomial.h"

// precondition: none
// postcondition: initializes the number of terms to 0, allocates an empty array for coefficients, and sets the coefficient status to false
Polynomial::Polynomial()
{
    this->terms = 0;
    coefficient = new double[0];
    coefficientStatus = false;
}
// precondition: p is a valid Polynomial object
// postcondition: creates a copy of the given Polynomial object by copying its terms, allocating a new array for coefficients, and copying the coefficient values and status
Polynomial::Polynomial(const Polynomial& p)
{
    terms = p.terms;

    coefficient = new double[terms];

    for (int i = 0; i < terms; i++)
    {
        coefficient[i] = p.coefficient[i];
    }

    coefficientStatus = p.coefficientStatus;
}

// precondition: p is a valid Polynomial object
// postcondition: assigns a deep copy of the given Polynomial object by copying its terms, allocating a new array for coefficients, and copying the coefficient values and status
Polynomial& Polynomial::operator=(const Polynomial& p)
{
    if (this == &p)
    {
        return *this;
    }

    double* newCoefficient = new double[p.terms];

    for (int i = 0; i < p.terms; i++)
    {
        newCoefficient[i] = p.coefficient[i];
    }

    delete[] coefficient;

    coefficient = newCoefficient;
    terms = p.terms;
    coefficientStatus = p.coefficientStatus;

    return *this;
}

// precondition: none
// postcondition: deallocates the memory used for the coefficient array to prevent memory leaks
Polynomial::~Polynomial()
{
    delete[] coefficient;
}
// precondition: newTerm is a valid integer representing the number of terms in the polynomial
// postcondition: sets the number of terms in the polynomial, deallocates the old coefficient array, allocates a new array for coefficients, and sets the coefficient status to false
void Polynomial::setTerm(int newTerm)
{
    this->terms = newTerm;
    delete[] coefficient;
    coefficient = new double[newTerm] {};
    coefficientStatus = false;
}
// precondition: none
// postcondition: returns the number of terms in the polynomial
int Polynomial::getTerm() const
{
    return terms;
}
//precondition: index is a valid integer representing the index of the coefficient to be set, and newCoefficient is a valid double representing the new coefficient value
//postcondition: sets the coefficient at the specified index to the new value and updates the coefficient status to true
void Polynomial::setCoefficient(int index, double newCoefficient)
{
    coefficient[index] = newCoefficient;
    coefficientStatus = true;
}
// precondition: index is a valid integer representing the index of the coefficient to be retrieved
// postcondition: returns the coefficient at the specified index
double Polynomial::getCoefficient(int index) const
{
    return coefficient[index];
}
// precondition: none
// postcondition: returns the status of the coefficients (true if set, false if not)
bool Polynomial::getCoefficientStatus() const
{
    return coefficientStatus;
}

//void Polynomial::evaluate(double x) const
//{
//    double evaluated = 0;
//    double multiplied = 0;
//    for (int i = 0; i < terms; i++)
//    {
//        int exponent = terms - 1 - i; // Calculate the exponent for the current term
//        multiplied = coefficient[i] * pow(x, exponent);
//        evaluated += multiplied;
//        cout << defaultfloat;
//
//        // Last term
//        if (i == terms - 1)
//        {
//            cout << "\n\t\t+" << setw(12) << right << multiplied << " <-" << setw(13) << right << setprecision(2) << fixed << coefficient[i] << "x^" << exponent;
//        }
//        else
//        {
//            cout << "\n\t\t" << setw(13) << right << multiplied << " <-" << setw(13) << right << setprecision(2) << fixed << coefficient[i] << "x^" << exponent;
//        }
//    }
//
//    cout << "\n\t\t" << string(40, char(196));
//    // Return to normal number formatting
//    cout << defaultfloat;
//    cout << "\n\t\t" << setw(13) << right << evaluated; // Display the evaluated result
//}

// precondition: x is a valid double representing the value at which the polynomial is to be evaluated
// postcondition: evaluates the polynomial at the specified value of x and displays the result
void Polynomial::evaluate(double x) const
{
    double evaluated = 0;
    double multiplied = 0;

    for (int i = 0; i < terms; i++)
    {
        int exponent = terms - 1 - i;
        multiplied = coefficient[i] * pow(x, exponent);
        evaluated += multiplied;

        if (i == terms - 1)
        {
            cout << "\n\t\t +" << setw(11) << right << defaultfloat << multiplied << " <-" << setw(13) << setprecision(2) << fixed << coefficient[i] << "x^" << exponent;
        }
        else
        {
			cout << "\n\t\t" << setw(13) << right << defaultfloat << multiplied << " <-" << setw(13) << setprecision(2) << fixed << coefficient[i] << "x^" << exponent;
        }
    }
    cout << "\n\t\t" << string(40, char(196));
    cout << "\n\t\t" << setw(13) << right << defaultfloat << setprecision(6) << evaluated;
}

// precondition: none
// postcondition: creates a new Polynomial object representing the derivative of the current polynomial and returns it
Polynomial Polynomial::derivative() const
{
    Polynomial derivative;

    if (terms == 1)
    {
        derivative.setTerm(1);
        derivative.setCoefficient(0, 0); //This part I had to hard-coded because if the original expression only has 1 term, the derivative will be 0

        return derivative;
    }

    derivative.setTerm(terms - 1); //reduce term by 1 because the last one will turned into 0

    for (int i = 0; i < derivative.getTerm(); i++)
    {
        int exponent = terms - 1 - i;

        double derivativeCoefficient = coefficient[i] * exponent;

        derivative.setCoefficient(i, derivativeCoefficient);
    }

    return derivative;
}

// precondition: none
// postcondition: creates a new Polynomial object representing the integral of the current polynomial and returns it
Polynomial Polynomial::integral() const
{
    const int ONE = 1;
    Polynomial integral;

    integral.setTerm(terms + ONE);

    for (int i = 0; i < terms; i++)
    {
        int exponent = terms - ONE - i;

        int integralExponent = exponent + ONE;

        double integralCoefficient = coefficient[i] / integralExponent;

        integral.setCoefficient(i, integralCoefficient);
    }

    //because the integral create a "0" at the end (it pushed all the terms upward by 1) so I hard-code here too
    integral.setCoefficient(integral.getTerm() - ONE, 0);

    return integral;
}

// precondition: none
// postcondition: outputs the polynomial to the given ostream
ostream& operator << (ostream& out, const Polynomial& p)
{
    bool firstTerm = true; // this is to prevent if the first one/few terms coefficient = 0
    for (int i = 0; i < p.getTerm(); i++)
    {
        double coefficient = p.getCoefficient(i);
        int exponent = p.getTerm() - 1 - i;

        // Skip zero coefficients
        if (coefficient == 0)
        {
            continue;
        }

        // Handle the sign
        if (firstTerm)
        {
            if (coefficient < 0)
            {
                out << "-";
            }
        }
        else
        {
            if (coefficient > 0)
            {
                out << " + ";
            }
            else
            {
                out << " - ";
            }
        }

        // Print coefficient without the negative sign
        if (coefficient < 0)
        {
            coefficient = -coefficient;
        }

        out << coefficient;

        // Print x depending on the exponent
        if (exponent > 1)
        {
            out << "x^" << exponent;
        }
        else if (exponent == 1)
        {
            out << "x";
        }

        firstTerm = false;
    }

    // All coefficients were zero
    if (firstTerm)
    {
        out << "0";
    }


    return out;
}

// precondition: secondPolynomial is a valid Polynomial object
// postcondition: returns a new Polynomial object representing the sum of the current polynomial and the secondPolynomial
Polynomial Polynomial::operator+(const Polynomial& secondPolynomial) const
{
    int largerTerms = 0; //to compare which one has larger term
    int smallerTerms = 0;
    Polynomial result;

    if (terms < secondPolynomial.getTerm())
    {
        smallerTerms = terms;
        largerTerms = secondPolynomial.getTerm();
        result.setTerm(largerTerms);

        int offset = largerTerms - smallerTerms;

        //loop from the largerTerms term 
        for (int i = 0; i < result.getTerm(); i++)
        {
            if (i < offset)
            {
                result.setCoefficient(i, secondPolynomial.getCoefficient(i));
            }
            else
            {
                int smallerTermsIndex = i - offset;

                result.setCoefficient(i, secondPolynomial.getCoefficient(i) + coefficient[smallerTermsIndex]);
            }
        }

        return result;
    }
    else if (terms > secondPolynomial.getTerm())
    {
        smallerTerms = secondPolynomial.getTerm();
        largerTerms = terms;
        result.setTerm(largerTerms);

        int offset = largerTerms - smallerTerms;

        //loop from the largerTerms term 
        for (int i = 0; i < result.getTerm(); i++)
        {
            if (i < offset)
            {
                result.setCoefficient(i, coefficient[i]);
            }
            else
            {
                int smallerTermsIndex = i - offset;

                result.setCoefficient(i, secondPolynomial.getCoefficient(smallerTermsIndex) + coefficient[i]);
            }
        }

        return result;
    }
    else
    {
        result.setTerm(terms);
        for (int i = 0; i < result.getTerm(); i++)
        {
            result.setCoefficient(i, coefficient[i] + secondPolynomial.coefficient[i]);
        }
        return result;
    }
}

// precondition: secondPolynomial is a valid Polynomial object
// postcondition: returns a new Polynomial object representing the difference between the current polynomial and the secondPolynomial
Polynomial Polynomial::operator-(const Polynomial& secondPolynomial) const
{
    Polynomial result;

    int largerTerms = 0; //to compare which one has larger term
    int smallerTerms = 0;

    if (terms < secondPolynomial.getTerm())
    {
        smallerTerms = terms;
        largerTerms = secondPolynomial.getTerm();
        result.setTerm(largerTerms);

        int offset = largerTerms - smallerTerms;

        //loop from the largerTerms term 
        for (int i = 0; i < result.getTerm(); i++)
        {
            if (i < offset)
            {
                result.setCoefficient(i, 0 - secondPolynomial.getCoefficient(i));
            }
            else
            {
                int smallerTermsIndex = i - offset;

                result.setCoefficient(i, coefficient[smallerTermsIndex] - secondPolynomial.getCoefficient(i));
            }
        }

        return result;
    }
    else if (terms > secondPolynomial.getTerm())
    {
        smallerTerms = secondPolynomial.getTerm();
        largerTerms = terms;
        result.setTerm(largerTerms);

        int offset = largerTerms - smallerTerms;

        //loop from the largerTerms term 
        for (int i = 0; i < result.getTerm(); i++)
        {
            if (i < offset)
            {
                result.setCoefficient(i, coefficient[i]);
            }
            else
            {
                int smallerTermsIndex = i - offset;

                result.setCoefficient(i, coefficient[i] - secondPolynomial.getCoefficient(smallerTermsIndex));
            }
        }

        return result;
    }
    else
    {
        result.setTerm(terms);
        for (int i = 0; i < result.getTerm(); i++)
        {
            result.setCoefficient(i, coefficient[i] - secondPolynomial.coefficient[i]);
        }
        return result;
    }
}

// precondition: secondPolynomial is a valid Polynomial object
// postcondition: returns a new Polynomial object representing the product of the current polynomial and the secondPolynomial
Polynomial Polynomial::operator*(const Polynomial& secondPolynomial) const
{
    Polynomial result;

    result.setTerm(terms + secondPolynomial.terms - 1);

    for (int i = 0; i < terms; i++)
    {
        for (int j = 0; j < secondPolynomial.terms; j++)
        {
            int resultIndex = i + j;
            double multiplied = coefficient[i] * secondPolynomial.coefficient[j];

            result.coefficient[resultIndex] += multiplied;
        }
    }

    return result;
}

// precondition: constant is a valid double representing the constant value to multiply with the polynomial
// postcondition: returns a new Polynomial object representing the product of the current polynomial and the constant
Polynomial Polynomial::operator*(double constant) const
{
    Polynomial result;

    result.setTerm(terms);

    for (int i = 0; i < result.getTerm(); i++)
    {
        result.setCoefficient(i, coefficient[i] * constant);
    }

    return result;
}

// precondition: constant is a valid double representing the constant value to multiply with the polynomial, and polynomial is a valid Polynomial object
// postcondition: returns a new Polynomial object representing the product of the constant and the polynomial
Polynomial operator*(double constant, const Polynomial& polynomial)
{
    return polynomial * constant;
}