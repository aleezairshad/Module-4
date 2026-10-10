#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Polynomial
{
private:
	int terms;
	double* coefficient;
	bool coefficientStatus;
public:
	Polynomial();
	Polynomial(const Polynomial& polynomial);
	Polynomial& operator=(const Polynomial& polynomial);
	~Polynomial();

	void setTerm(int newTerm);
	int getTerm() const;

	void setCoefficient(int index, double newCoefficient);
	double getCoefficient(int index) const;

	bool getCoefficientStatus() const;

	void evaluate(double x) const;
	Polynomial derivative() const; //create new polynomial for derivative, because derivative is another polynomial anyway
	Polynomial integral() const;

	//these are for option B

	Polynomial operator+(const Polynomial& other) const;
	Polynomial operator-(const Polynomial& other) const;
	Polynomial operator*(const Polynomial& other) const;
	Polynomial operator*(double constant) const;
	friend Polynomial operator*(double constant, const Polynomial& polynomial);

	friend ostream& operator<<(ostream& out, const Polynomial& polynomial);
};

