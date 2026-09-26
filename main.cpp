#include <iostream>
#include <iomanip>
#include "input.h"
#include "Polynomials.h"

//function prototypes
char displayPolynomialMenu();
int displayPolynomialMenuA();

using namespace std;

int main()
{
	char option;
	int optionCaseA;
	do
	{
		system("cls");
		option = displayPolynomialMenu();

		switch (option)
		{
		case 'A':
		{
			system("cls");
			Polynomials test1;
			do
			{
				system("cls");
				optionCaseA = displayPolynomialMenuA();

				switch (optionCaseA)
				{
				case 1:
				{
					int terms = inputInteger("\n\t\tEnter the number of terms (1..100) for the polynomial: ", 1, 100);
					test1.setTerm(terms);
				}
				break;

				case 2:
				{
					for (int i = 0; i < test1.getTerm(); i++)
					{
						cout << "\n\t\tEnter the coefficient for term #" << i + 1 << ": ";
						double coefficientIndex = inputDouble("");
						test1.setCoefficient(i, coefficientIndex);
					}

					cout << "\n\t\tThe P(x) is entered: " << test1 << "\n";
				}
				break;

				case 3:
				{
					cout << "\n\t\tP1(x) = " << test1 << "\n";

					double x = inputDouble("\n\t\tEnter the value of x to evaluate the polynomial: ");

					test1.evaluate(x);
					cout << "\n";
				}
				break;

				case 4:
				{
					Polynomials derivative = test1.derivative();

					cout << "\n\t\tPolynomial(x) = " << test1;
					cout << "\n\t\tDerivative    = " << derivative << "\n";
				}
				break;

				case 5:
				{
					Polynomials integral = test1.integral();

					cout << "\n\t\tPolynomial(x) = " << test1;
					cout << "\n\t\tIntegral      = " << integral << "\n";
				}
				break;

				case 0:
				{

				}
				break;

				default:
				{
					cout << "\n\tERROR: Invalid option";
				}

				}

				system("pause");
			} while (optionCaseA != 0);
		}
		break;

		case 'B':
		{
			system("cls");
			Polynomials first;
			Polynomials second;

			cout << "\n\tB> Two Polynomials";
			int terms = inputInteger("\n\t\tEnter the number of terms (1..100) for the polynomial (P1): ", 1, 100);
			first.setTerm(terms);

			for (int i = 0; i < first.getTerm(); i++)
			{
				cout << "\n\t\t\tEnter the coefficient for term #" << i + 1 << ": ";
				double coefficientIndex = inputDouble("");
				first.setCoefficient(i, coefficientIndex);
			}

			cout << "\n\tThe first polynomial P(1) is entered: " << first << "\n";

			terms = inputInteger("\n\t\tEnter the number of terms (1..100) for the polynomial (P2): ", 1, 100);
			second.setTerm(terms);

			for (int i = 0; i < second.getTerm(); i++)
			{
				cout << "\n\t\t\tEnter the coefficient for term #" << i + 1 << ": ";
				double coefficientIndex = inputDouble("");
				second.setCoefficient(i, coefficientIndex);
			}

			cout << "\n\tThe second polynomial P(2) is entered: " << first << "\n";

			cout << "\n\t\tAddition of polynomials       -> P1 + P2 = " << first + second;
			cout << "\n\t\tSubtraction of polynomials    -> P1 - P2 = " << first- second;
			cout << "\n\t\tMultiplication of polynomials -> P1 * P2 = " << first * second;

			double constant = inputDouble("\n\t\tEnter a constant value: ");

			cout << "\n\t" << fixed << setprecision(6) << constant << " * Polynomial(P1) = " << setprecision(0) << constant * first;
			cout << "\n\t" << fixed << setprecision(6) << "Polynomial(P2) * " << constant << " = " << setprecision(0) << second * constant << "\n";

			system("pause");
		}
		break;

		case '0':
		{

		}
		break;

		default:
		{
			cout << "\n\tERROR: Invalid option";
		}
		}

	} while (option != '0');
	return 0;
}

char displayPolynomialMenu()
{
	//cout << "\n\tDemonstrating Polynomials:";
	//cout << string(90, char(205));

	cout << "\n\tA polynomial is an expression consisting of variables(also called indeterminates) and";
	cout << "\n\tcoefficients, that involves only the operations of addition, subtraction, multiplication,";
	cout << "\n\tand non-negative integer exponentiation of variables.";

	cout << "\n\n\t3> Polynomials";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\tA> A Polynomial";
	cout << "\n\t\tB> Multiple Polynomials";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(90, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("AB0"));
}

int displayPolynomialMenuA()
{
	cout << "\n\tA> Single Polynomial";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1. Enter the number of terms";
	cout << "\n\t\t2. Specify the coefficients";
	cout << "\n\t\t3. Evaluate expression";
	cout << "\n\t\t4. Solve for the derivative";
	cout << "\n\t\t5. Solve for the integral";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(90, char(205));
	return inputInteger("\n\t\tOption: ",0,5);
}