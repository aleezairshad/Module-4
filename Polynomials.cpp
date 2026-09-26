#include "polynomials.h"
Polynomials::Polynomials()
{
	this->terms = 0;
	coefficient = new double[0];
	coefficientStatus = false;
}

Polynomials::Polynomials(const Polynomials& p)
{
    terms = p.terms;

    coefficient = new double[terms];

    for (int i = 0; i < terms; i++)
    {
        coefficient[i] = p.coefficient[i];
    }

    coefficientStatus = p.coefficientStatus;
}

Polynomials::~Polynomials()
{
	delete[] coefficient;
}

void Polynomials::setTerm(int newTerm)
{
	this->terms = newTerm;
	delete[] coefficient;
    coefficient = new double[newTerm] {};
	coefficientStatus = false;
}

int Polynomials::getTerm() const
{
	return terms;
}

void Polynomials::setCoefficient(int index, double newCoefficient)
{
	coefficient[index] = newCoefficient;
	coefficientStatus = true;
}

double Polynomials::getCoefficient(int index) const
{
	return coefficient[index];
}

bool Polynomials::getCoefficientStatus() const
{
	return coefficientStatus;
}

void Polynomials::evaluate(double x) const
{
    double evaluated = 0;
    double multiplied = 0;

    for (int i = 0; i < terms; i++)
    {
        int exponent = terms - 1 - i;
        multiplied = coefficient[i] * pow(x,exponent);
        evaluated += multiplied;

        if (i == terms - 1)
        {
            cout << "\n\t\t +" << setw(11) << right << setprecision(2) << fixed << multiplied << " <-" << setw(13) << coefficient[i] << "x^" << exponent;
        }
        else
        {
            cout << "\n\t\t" << setw(13) << right << setprecision(2) << fixed << multiplied << " <-" << setw(13) << coefficient[i] << "x^" << exponent;
        }
    }
    cout << "\n\t\t" << string(40, char(196));
    cout << "\n\t\t" << setw(13) << right << setprecision(2) << fixed << evaluated << setprecision(0);
}

Polynomials Polynomials::derivative() const
{
    Polynomials derivative;

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

        derivative.setCoefficient(i,derivativeCoefficient);
    }

    return derivative;
}

Polynomials Polynomials::integral() const
{
    Polynomials integral;

    integral.setTerm(terms + 1);

    for (int i = 0; i < terms; i++)
    {
        int exponent = terms - 1 - i;

        int integralExponent = exponent + 1;

        double integralCoefficient = coefficient[i] / integralExponent;

        integral.setCoefficient(i, integralCoefficient);
    }

    //because the integral create a "0" at the end (it pushed all the terms upward by 1) so I hard-code here too
    integral.setCoefficient(integral.getTerm() - 1, 0);

    return integral;
}

ostream& operator << (ostream& out, const Polynomials& p)
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

Polynomials Polynomials::operator+(const Polynomials& secondPolynomial) const
{
    int largerTerms = 0; //to compare which one has larger term
    int smallerTerms = 0;
    Polynomials result;

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

                result.setCoefficient(i,secondPolynomial.getCoefficient(i) + coefficient[smallerTermsIndex]);
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

                result.setCoefficient(i,secondPolynomial.getCoefficient(smallerTermsIndex) + coefficient[i]);
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

Polynomials Polynomials::operator-(const Polynomials& secondPolynomial) const
{
    Polynomials result;

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

Polynomials Polynomials::operator*(const Polynomials& secondPolynomial) const
{
    Polynomials result;

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

Polynomials Polynomials::operator*(double constant) const
{
    Polynomials result;

    result.setTerm(terms);

    for (int i = 0; i < result.getTerm(); i++)
    {
        result.setCoefficient(i,coefficient[i] * constant);
    }

    return result;
}

Polynomials operator*(double constant, const Polynomials& polynomial)
{
    return polynomial * constant;
}