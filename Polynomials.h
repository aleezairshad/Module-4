#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Polynomials
{
private:
	int terms;
	double* coefficient;
	bool coefficientStatus;
public:
	Polynomials();
	Polynomials(const Polynomials& p);
	~Polynomials();

	void setTerm(int newTerm);
	int getTerm() const;

	void setCoefficient(int index, double newCoefficient);
	double getCoefficient(int index) const;

	bool getCoefficientStatus() const;

	void evaluate(double x) const;

	Polynomials derivative() const; //create new polynomial for derivative, because derivative is another polynomial anyway

	Polynomials integral() const;

	friend ostream& operator<<(ostream& out, const Polynomials& p);

	//these are for option B

	Polynomials operator+(const Polynomials& secondPolynomial) const;
	Polynomials operator-(const Polynomials& secondPolynomial) const;
	Polynomials operator*(const Polynomials& secondPolynomial) const;
	Polynomials operator*(double constant) const;

	friend Polynomials operator*(double constant, const Polynomials& p);
};

