//Name: Hany, Aleeza, and Tuniphn
// Date: 9/18/2026
// Description: Module 4 - Pointer and Dynamic Memory Allocation

#include <iostream>
#include <sstream>
#include <string>
#include "input.h"
#include "RationalNumber.h"
#include "Polynomials.h"


using namespace std;

// Function prototypes
char menuOption();
void Rational(); // Function to handle rational number operations
void rationalOptionA(RationalNumber& rational); // function to handle rational number operations for option A
void rationalOptionB(RationalNumber& rational); // function to handle rational number operations for option B
void reduceFraction(long long& numerator, long long& denominator); // Function to reduce a fraction to its simplest form

//function prototypes
void displayPolynomial();
void displayPolynomialMenuA();

int main()
{
	bool running = true;
	char option;

	while (running)
	{
		system("cls");
		option = menuOption();
		switch (option)
		{
		case '1':
			cout << "\n\tComplex Numbers\n";
			break;
		case '2':
			Rational();
			
			break;
		case '3':
			displayPolynomial();
			
			break;
		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}

	return 0;
}

// Function to display the main menu and get the user's option
char menuOption()
{

	cout << "\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Hany, Aleeza, and Tuniphn (09/18/26)\n";
	cout << "\t" << string(105, char(205));
	cout << "\n\t\t1 > Complex Numbers";
	cout << "\n\t\t2 > Rational Numbers";
	cout << "\n\t\t3 > Polynomials\n";
	cout << "\t" << string(105, char(196));
	cout << "\n\t\t0 > Exit\n";
	cout << "\t" << string(105, char(205));

	char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,0")));
	return option;

}

//precondition: none
//postcondition: displays information about rational numbers and provides options for the user to perform operations on rational numbers
void Rational()
{
	RationalNumber rational;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\t\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
		cout << "\n\t\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
		cout << "\n\t\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
		cout << "\n\t\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
		cout << "\n\t\tIn general, a number that can be written as a fraction while it is in its own form is rational.\n";
		cout << "\n\t\t2> Rational Numbers\n";
		cout << "\t\t" << string(100, char(205));
		cout << "\n\t\t\tA> A Rational Number";
		cout << "\n\t\t\tB> Multiple Rational Numbers\n";
		cout << "\t\t" << string(100, char(196));
		cout << "\n\t\t\t0> Return\n";
		cout << "\t\t" << string(100, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,0")));
		switch (option)
		{
		case 'A':
			rationalOptionA(rational);
			
			break;
		case 'B':
			rationalOptionB(rational);
			
			break;
		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}
}

//precondition: rational is a valid RationalNumber object
//postcondition: provides options for the user to perform operations on a single rational number
void rationalOptionA(RationalNumber& rational)
{
	const int ONE = 1;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\n\t\t2> A Rational Number\n";
		cout << "\t\t" << string(100, char(205));
		cout << "\n\t\t\t1> Enter the numerator";
		cout << "\n\t\t\t2> Enter the denominator";
		cout << "\n\t\t\t3> Display the rational number";
		cout << "\n\t\t\t4> Normalize the rational number";
		cout << "\n\t\t\t5> Negate the rational number";
		cout << "\n\t\t\t6> Add (+) the rational number with a constant";
		cout << "\n\t\t\t7> Subtract (-) the rational number with a constant";
		cout << "\n\t\t\t8> Multiply (*) the rational number with a constant";
		cout << "\n\t\t\t9> Divide (/) the rational number with a constant";
		cout << "\n\t\t" << string(100, char(196));
		cout << "\n\t\t\t0> Return\n";
		cout << "\t\t" << string(100, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("1,2,3,4,5,6,7,8,9,0")));

		switch (option)
		{
		case '1': 
		{
			int numerator = inputInteger("\n\t\t\tEnter an integer for the numerator: "); // Prompt the user for an integer value and validate the input to ensure it is an integer
			rational.setNumerator(numerator); // Set the numerator of the rational number to the user input
			cout << "\n";
			system("pause");
			break;
		}
		case '2':
		{
			int denominator = inputInteger("\n\t\t\tEnter an integer for the denominator: "); // Prompt the user for an integer value and validate the input to ensure it is an integer
			// Check if the denominator is zero and prompt the user to enter a valid denominator if it is
			while (denominator == 0)
			{
				cout << "\t\t\tERROR: Denominator cannot be zero.\n";
				denominator = inputInteger("\n\t\t\tEnter an integer for the denominator: ");
			}
			rational.setDenominator(denominator);
			cout << "\n";
			system("pause");
			break;
		}
		case '3': // Display the rational number in the form of a fraction
		{
			if (rational.getDenominator() == 0) // Check if the denominator is zero and display "undefined" if it is
			{
				cout << "\n\t\t\tRational number R1 = undefine\n";
			}
			else
			{
				cout << "\n\t\t\tRational number R1 = " << rational.getNumerator() << "/" << rational.getDenominator() << "\n";
			}
			cout << "\n";
			system("pause");
			break;
		}
		case '4': // Normalize the rational number by creating a copy of it and calling the normalize() function on the copy
		{
			RationalNumber R2(rational);
			R2.normalize();
			cout << "\n\t\t\tNormalized rational number R2 (a copy of R1)\n\n\t\t\t";
			R2.display();
			cout << "\n\n";
			system("pause");

			break;
		}
		case '5': // Negate the rational number by creating a copy of it and calling the negate() function on the copy
		{
			RationalNumber R2(rational);
			R2.negate();
			cout << "\n\t\t\tNegated rational number R2 (a copy of R1)\n\n\t\t\t";
			cout << "-(" << rational.getNumerator() << "/" << rational.getDenominator() << ") = ";
			R2.display();
			cout << "\n\n";
			system("pause");
			break;
		}
		case '6': // Add the rational number with a constant by creating a copy of it and calling the overloaded + operator with a constant
		{
			int value = inputInteger("\n\t\t\tEnter an integer value: "); 
			RationalNumber R2(rational); // Create a copy of the rational number to perform the addition operation
			RationalNumber constant(value, ONE); // Create a RationalNumber object with the constant value and a denominator of 1

			RationalNumber result1 = R2 + constant; // Call the overloaded + operator to add the rational number with the constant and store the result in a new RationalNumber object
			RationalNumber result2 = constant + R2; // Call the overloaded + operator to add the constant with the rational number and store the result in a new RationalNumber object

			cout << "\n\t\t\tR2 + value\n\t\t\t(";
			R2.display();
			cout << ") + " << value << " = ";
			result1.display();

			cout << "\n\n\t\t\tvalue + R2\n\t\t\t";
			cout << value << " + (";
			R2.display();
			cout << ") = ";
			result2.display();

			cout << "\n\n";
			system("pause");
			break;
		}
		case '7': // Subtract the rational number with a constant by creating a copy of it and calling the overloaded - operator with a constant
		{
			int value = inputInteger("\n\t\t\tEnter an integer value: ");

			RationalNumber R2(rational); // Create a copy of the rational number to perform the subtraction operation
			RationalNumber constant(value, 1); // Create a RationalNumber object with the constant value and a denominator of 1

			RationalNumber result1 = R2 - constant; // Call the overloaded - operator to subtract the constant from the rational number and store the result in a new RationalNumber object
			RationalNumber result2 = constant - R2; // Call the overloaded - operator to subtract the rational number from the constant and store the result in a new RationalNumber object

			cout << "\n\t\t\tR2 - value\n\t\t\t(";
			R2.display();
			cout << ") - " << value << " = ";
			result1.display();

			cout << "\n\n\t\t\tvalue - R2\n\t\t\t";
			cout << value << " - (";
			R2.display();
			cout << ") = ";
			result2.display();

			cout << "\n\n";
			system("pause");
			break;
		}
		case '8': // Multiply the rational number with a constant by creating a copy of it and calling the overloaded * operator with a constant
		{
			int value = inputInteger("\n\t\t\tEnter an integer value: ");

			RationalNumber R2(rational); // Create a copy of the rational number to perform the multiplication operation
			RationalNumber constant(value, ONE); // Create a RationalNumber object with the constant value and a denominator of 1

			RationalNumber result1 = R2 * constant; // Call the overloaded * operator to multiply the rational number with the constant and store the result in a new RationalNumber object
			RationalNumber result2 = constant * R2; // Call the overloaded * operator to multiply the constant with the rational number and store the result in a new RationalNumber object

			cout << "\n\t\t\tR2 * value\n\t\t\t(";
			R2.display();
			cout << ") * " << value << " = ";
			result1.display();

			cout << "\n\n\t\t\tvalue * R2\n\t\t\t";
			cout << value << " * (";
			R2.display();
			cout << ") = ";
			result2.display();

			cout << "\n\n";
			system("pause");
			break;
		}
		case '9': // Divide the rational number with a constant by creating a copy of it and calling the overloaded / operator with a constant
		{
			int value = inputInteger("\n\t\t\tEnter an integer value: ");

			RationalNumber R2(rational); // Create a copy of the rational number to perform the division operation
			RationalNumber constant(value, ONE); // Create a RationalNumber object with the constant value and a denominator of 1

			RationalNumber result1 = R2 / constant; // Call the overloaded / operator to divide the rational number by the constant and store the result in a new RationalNumber object
			RationalNumber result2 = constant / R2; // Call the overloaded / operator to divide the constant by the rational number and store the result in a new RationalNumber object

			cout << "\n\t\t\tR2 / value\n\t\t\t(";
			R2.display();
			cout << ") / " << value << " = ";
			result1.display();

			cout << "\n\n\t\t\tvalue / R2\n\t\t\t";
			cout << value << " / (";
			R2.display();
			cout << ") = ";
			result2.display();

			cout << "\n\n";
			system("pause");
			break;
		}
		case '0':
			running = false;
			cout << "\n";
			system("pause");
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;

		}

	}

}

//precondition: rational is a valid RationalNumber object
//postcondition: provides options for the user to perform operations on two rational numbers
void rationalOptionB(RationalNumber& rational)
{
	RationalNumber R1(rational); // Create a copy of the rational number to perform operations on two rational numbers
	RationalNumber R2(rational); // Create a copy of the rational number to perform operations on two rational numbers
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
		cout << "\n\t\tB> Multiple Rational Numbers\n";
		cout << "\t\t" << string(100, char(205));
		cout << "\n\t\t\t1. Enter rational number R1";
		cout << "\n\t\t\t2. Enter rational number R2";
		cout << "\n\t\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
		cout << "\n\t\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
		cout << "\n\t\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889"; 
		cout << "\n\t\t" << string(100, char(196));
		cout << "\n\t\t\t0> Return\n";
		cout << "\t\t" << string(100, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("1,2,3,4,5,0")));
		switch (option)
		{
		case '1': // Prompt the user to enter the numerator and denominator for R1, validate the input, and set the values for R1
		{
			int numerator = inputInteger("\n\t\t\tEnter the numerator for R1: ");
			int denominator = inputInteger("\t\t\tEnter the denominator for R1: ");
			// Check if the denominator is zero and prompt the user to enter a valid denominator if it is
			while (denominator == 0)
			{
				cout << "\t\t\tERROR: Denominator cannot be zero.\n";
				denominator = inputInteger("\t\t\tEnter the denominator for R1: ");
			}

			R1.setNumerator(numerator); // Set the numerator of R1 to the user input
			R1.setDenominator(denominator); // Set the denominator of R1 to the user input
			R1.normalize(); // Normalize R1 to its simplest form
			cout << "\n\t\t\tR1 = ";
			R1.display();
			cout << "\n\n";
			system("pause");
			break;
		}
		case '2': // Prompt the user to enter the numerator and denominator for R2, validate the input, and set the values for R2
		{
			int numerator = inputInteger("\n\t\t\tEnter the numerator for R2: ");
			int denominator = inputInteger("\t\t\tEnter the denominator for R2: ");
			// Check if the denominator is zero and prompt the user to enter a valid denominator if it is
			while (denominator == 0)
			{
				cout << "\t\t\tERROR: Denominator cannot be zero.\n";
				denominator = inputInteger("\t\t\tEnter the denominator for R2: ");
			}
			R2.setNumerator(numerator); // Set the numerator of R2 to the user input
			R2.setDenominator(denominator); // Set the denominator of R2 to the user input
			R2.normalize(); // Normalize R2 to its simplest form
			cout << "\n\t\t\tR2 = ";
			R2.display();
			cout << "\n\n";
			system("pause");
			break;
		}
		case '3': // Verify the condition operators (==, !=, >=, >, <= and <) of R1 and R2 and display the results
		{
			cout << boolalpha; // Set the output format to display boolean values as "true" or "false" instead of 1 or 0
			cout << "\n\t\t\tR1 == R2 -> (";
			R1.display();
			cout << ") == (";
			R2.display();
			cout << ") ? " << (R1 == R2); // Display the result of the equality operator (==) between R1 and R2
			cout << "\n\t\t\tR2 != R1 -> (";
			R2.display();
			cout << ") != (";
			R1.display();
			cout << ") ? " << (R2 != R1); // Display the result of the inequality operator (!=) between R2 and R1

			cout << "\n\t\t\tR1 >= R2 -> (";
			R1.display();
			cout << ") >= (";
			R2.display();
			cout << ") ? " << (R1 >= R2); // Display the result of the greater than or equal to operator (>=) between R1 and R2
			cout << "\n\t\t\tR2  > R1 -> (";
			R2.display();
			cout << ")  > (";
			R1.display();
			cout << ") ? " << (R2 > R1); // Display the result of the greater than operator (>) between R2 and R1
			cout << "\n\t\t\tR1 <= R2 -> (";
			R1.display();
			cout << ") <= (";
			R2.display();
			cout << ") ? " << (R1 <= R2); // Display the result of the less than or equal to operator (<=) between R1 and R2

			cout << "\n\t\t\tR2  < R1 -> (";
			R2.display();
			cout << ")  < (";
			R1.display();
			cout << ") ? " << (R2 < R1); // Display the result of the less than operator (<) between R2 and R1

			cout << "\n\n";
			system("pause");
			break;
		}
		case '4': // Evaluate the arithmetic operators (+, -, *, /) of R1 and R2 and display the results
		{
			RationalNumber addition = R1 + R2; // Call the overloaded + operator to add R1 and R2 and store the result in a new RationalNumber object
			RationalNumber subtraction = R2 - R1; // Call the overloaded - operator to subtract R1 from R2 and store the result in a new RationalNumber object
			RationalNumber multiplication = R1 * R2; // Call the overloaded * operator to multiply R1 and R2 and store the result in a new RationalNumber object
			RationalNumber division = R2 / R1; // Call the overloaded / operator to divide R2 by R1 and store the result in a new RationalNumber object
			// Display the results of the arithmetic operations
			cout << "\n\t\t\tAddition      : R1 + R2 -> (";
			R1.display();
			cout << ") + (";
			R2.display();
			cout << ") = ";
			addition.display();

			cout << "\n\t\t\tSubtraction   : R2 - R1 -> (";
			R2.display();
			cout << ") - (";
			R1.display();
			cout << ") = ";
			subtraction.display();

			cout << "\n\t\t\tMultiplication: R1 * R2 -> (";
			R1.display();
			cout << ") * (";
			R2.display();
			cout << ") = ";
			multiplication.display();

			cout << "\n\t\t\tDivision      : R2 / R1 -> (";
			R2.display();
			cout << ") / (";
			R1.display();
			cout << ") = ";
			division.display();

			cout << "\n\n";
			system("pause");
			break;
		}
		case '5': // Evaluate the expression (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 and display the steps of the evaluation
		{
			const int THREE = 3;
			const int SEVEN = 7;
			const int NINE = 9;

			RationalNumber R3(621, 889); // Create a RationalNumber object with the value 621/889 to compare with the result of the expression
			cout << "\n\t\t\tR1 = ";
			R1.display();
			cout << "\n\t\t\tR2 = ";
			R2.display();
			cout << "\n\t\t\tR3 = ";
			R3.display();

			cout << "\n\n\t\t\tEvaluating expression...";
			cout << "\n\t\t\t\t    (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 ?";

			// step 1: R1 + R2
			long long step1LeftNum = static_cast<long long>(R1.getNumerator()) * R2.getDenominator() + static_cast<long long>(R2.getNumerator()) * R1.getDenominator(); // Calculate the numerator of the sum of R1 and R2
			long long step1LeftDenom = static_cast<long long>(R1.getDenominator()) * R2.getDenominator(); // Calculate the denominator of the sum of R1 and R2
			reduceFraction(step1LeftNum, step1LeftDenom); // Reduce the fraction to its simplest form
			// step 1: R1 / 9
			long long step1RightNum = R1.getNumerator(); // Calculate the numerator of R1 divided by 9
			long long step1RightDenom = static_cast<long long>(R1.getDenominator()) * NINE; // Calculate the denominator of R1 divided by 9
			reduceFraction(step1RightNum, step1RightDenom); // Reduce the fraction to its simplest form
			// Display the first step of the evaluation
			cout << "\n\t\t\t   step #1: (3 * (";
			cout << step1LeftNum << "/" << step1LeftDenom;
			cout << ") / 7) / (R2 - (";
			cout << step1RightNum << "/" << step1RightDenom;
			cout << ")) >= 621/889 ?";

			// Step 2: 3 * step1Left
			long long step2LeftNum = THREE * step1LeftNum; // Calculate the numerator of 3 times the sum of R1 and R2
			long long step2LeftDenom = step1LeftDenom; // The denominator remains the same as the sum of R1 and R2
			reduceFraction(step2LeftNum, step2LeftDenom); // Reduce the fraction to its simplest form

			// Step 2: R2 - step1Right
			long long step2RightNum = static_cast<long long>(R2.getNumerator()) * step1RightDenom - step1RightNum * R2.getDenominator(); // Calculate the numerator of R2 minus step1Right
			long long step2RightDenom = static_cast<long long>(R2.getDenominator()) * step1RightDenom; // Calculate the denominator of R2 minus step1Right
			reduceFraction(step2RightNum, step2RightDenom); // Reduce the fraction to its simplest form
			// Display the second step of the evaluation
			cout << "\n\t\t\t   step #2: ((";
			cout << step2LeftNum << "/" << step2LeftDenom;
			cout << ") / 7) / (";
			cout << step2RightNum << "/" << step2RightDenom;
			cout << ") >= 621/889 ?";

			// Step 3: step2Left / 7
			long long step3LeftNum = step2LeftNum; // The numerator remains the same as step2Left
			long long step3LeftDenom = step2LeftDenom * SEVEN; // Calculate the denominator of step2Left divided by 7
			reduceFraction(step3LeftNum, step3LeftDenom); // Reduce the fraction to its simplest form
			// Display the third step of the evaluation
			cout << "\n\t\t\t   step #3: (";
			cout << step3LeftNum << "/" << step3LeftDenom;
			cout << ") / (";
			cout << step2RightNum << "/" << step2RightDenom;
			cout << ") >= 621/889 ?";


			// Step 4: step3Left / step2Right
			long long step4Num = step3LeftNum * step2RightDenom; // Calculate the numerator of step3Left divided by step2Right
			long long step4Denom = step3LeftDenom * step2RightNum; // Calculate the denominator of step3Left divided by step2Right
			reduceFraction(step4Num, step4Denom); // Reduce the fraction to its simplest form

			// Display the fourth step of the evaluation
			cout << "\n\t\t\t   step #4: (";
			cout << step4Num << "/" << step4Denom;
			cout << ") >= 621/889 ?";

			// Step 5: Compare step4 with R3
			bool result = step4Num * static_cast<long long>(R3.getDenominator()) >= static_cast<long long>(R3.getNumerator()) * step4Denom; // Compare the two fractions by cross-multiplying to avoid floating-point precision issues
			cout << "\n\t\t\t   step #5: " << boolalpha << result;
			cout << "\n\n";
			system("pause");
			break;
		}
		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}
}

//precondition: numerator and denominator are valid long long integers
//postcondition: reduces the fraction represented by numerator and denominator to its simplest form
void reduceFraction(long long& numerator, long long& denominator)
{
	long long a = numerator;
	long long b = denominator;
	// Ensure that a and b are non-negative for the GCD calculation
	if (a < 0)
	{
		a = -a;
	}
	// Ensure that a and b are non-negative for the GCD calculation
	if (b < 0)
	{
		b = -b;
	}
	// Use the Euclidean algorithm to find the GCD of a and b
	while (b != 0)
	{
		long long remainder = a % b;
		a = b;
		b = remainder;
	}
	// Divide both the numerator and denominator by the GCD to reduce the fraction to its simplest form
	if (a != 0)
	{
		numerator /= a;
		denominator /= a;
	}
	// Ensure that the denominator is positive by negating both the numerator and denominator if the denominator is negative
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}

//precondition: none
//postcondition: displays information about polynomials and provides options for the user to perform operations on polynomials
void displayPolynomial()
{
	Polynomials polynomial;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
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
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,0")));
		switch (option)
		{
		case 'A':
			displayPolynomialMenuA(); // Call the function to display the menu for a single polynomial
			break;
		case 'B':
		{
			system("cls");
			Polynomials first; // Create an instance of the Polynomials class to represent the first polynomial
			Polynomials second; // Create an instance of the Polynomials class to represent the second polynomial
			cout << "\n\tB> Two Polynomials";
			int terms = inputInteger("\n\t\tEnter the number of terms(1..100) for the first polynomial (P1): ", 1, 100);
			first.setTerm(terms);
			// Prompt the user to enter the coefficients for each term of the first polynomial
			for (int i = 0; i < first.getTerm(); i++)
			{
				cout << "\t\t\tEnter the coefficient for term#" << i + 1 << ": ";
				double coefficientIndex = inputDouble("");
				first.setCoefficient(i, coefficientIndex);
			}
			// Display the first polynomial entered by the user
			cout << "\n\tThe first polynomial (P1) is entered: " << first << "\n";
			terms = inputInteger("\n\t\tEnter the number of terms(1..100) for the second polynomial (P2): ", 1, 100);
			second.setTerm(terms);
			// Prompt the user to enter the coefficients for each term of the second polynomial
			for (int i = 0; i < second.getTerm(); i++)
			{
				cout << "\t\t\tEnter the coefficient for term#" << i + 1 << ": ";
				double coefficientIndex = inputDouble("");
				second.setCoefficient(i, coefficientIndex);
			}
			// Display the second polynomial entered by the user
			cout << "\n\tThe second polynomial (P2) is entered: " << second << "\n";
			cout << "\n\t\tAddition of polynomials       -> P1 + P2 = " << first + second;
			cout << "\n\t\tSubtraction of polynomials    -> P1 - P2 = " << first - second;
			cout << "\n\t\tMultiplication of polynomials -> P1 * P2 = " << first * second;
			double constant = inputDouble("\n\n\t\tEnter a constant value: ");
			cout << "\n\t" << fixed << setprecision(6) << constant << " * Polynomial(P1) = ";
			cout << defaultfloat << constant * first;
			// Display the result of multiplying the first polynomial by the constant
			cout << "\n\n\tPolynomial(P2) * " << fixed << setprecision(6) << constant << " = ";
			cout << defaultfloat << second * constant << "\n";
			cout << "\n";
			system("pause");
			break;
		}


		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}


	//return inputChar("\n\t\tOption: ", static_cast<string>("AB0"));
}

//precondition: none
//postcondition: displays information about polynomials and provides options for the user to perform operations on a single polynomial
void displayPolynomialMenuA()
{
	Polynomials polynomial;
	bool running = true;
	char option;
	while (running)
	{
		system("cls");
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
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("1,2,3,4,5,0")));
		switch (option)
		{
		case '1': 
		{
			int terms = inputInteger("\n\t\tEnter the number of terms (1..100) for the polynomial: ", 1, 100);
			polynomial.setTerm(terms);
			cout << "\n";
			system("pause");
			break;
		}
		case '2':
		{
			if (polynomial.getTerm() == 0)
			{
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms.\n\n";
				system("pause");
				break;
			}

			for (int i = 0; i < polynomial.getTerm(); i++)
			{
				cout << "\n\t\tEnter the coefficient for term #" << i + 1 << ": ";

				double coefficientIndex = inputDouble("");
				coefficientIndex += polynomial.getCoefficient(i); // Add the new coefficient to the existing coefficient for the term
				polynomial.setCoefficient(i, coefficientIndex);  // Update the coefficient for the term with the new value
			}
			cout << "\n\t\tThe P(x) is entered: " << polynomial << "\n\n"; // Display the polynomial entered by the user
			system("pause");
			break;
		}

			
		case '3':
		{
			// No terms entered
			if (polynomial.getTerm() == 0)
			{
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms.\n\n";
				system("pause");
				break;
			}

			// For 2 or more terms, coefficients must be specified
			// Do not give this error when there is only 1 term
			if (polynomial.getCoefficient(0) == 0 && polynomial.getTerm() > 1)
			{
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n\n";
				system("pause");
				break;
			}

			// Display the polynomial
			cout << "\n\t\tP1(x) = " << polynomial << "\n";

			double x = inputDouble("\n\t\tEnter the value of x to evaluate the polynomial: "); // Prompt the user to enter a value for x to evaluate the polynomial

			// Evaluate and display the steps
			polynomial.evaluate(x);
			cout << "\n\n";
			system("pause");

			break;
		}

		case '4':
		{
			// No terms entered
			if (polynomial.getTerm() == 0)
			{
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms.\n\n";
				system("pause");
				break;
			}

			// Terms entered, but coefficients not specified
			if (polynomial.getCoefficient(0) == 0 && polynomial.getTerm() > 1)
			{
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n\n";
				system("pause");
				break;
			}

			Polynomials derivative = polynomial.derivative(); // Call the derivative() function to calculate the derivative of the polynomial and store the result in a new Polynomials object
			cout << "\n\t\tPolynomial(x) = " << polynomial;
			cout << "\n\n\t\tDerivative    = " << derivative << "\n\n";

			system("pause");
			break;
		}
		case '5':
		{
			// No terms entered
			if (polynomial.getTerm() == 0)
			{
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms.\n\n";
				system("pause");
				break;
			}

			// Terms entered, but coefficients not specified
			if (polynomial.getCoefficient(0) == 0 && polynomial.getTerm() > 1)
			{
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n\n";
				system("pause");
				break;
			}
			Polynomials integral = polynomial.integral(); // Call the integral() function to calculate the integral of the polynomial and store the result in a new Polynomials object
			cout << "\n\t\tPolynomial(x) = " << polynomial;
			cout << "\n\n\t\tIntegral      = " << integral << "\n\n";

			system("pause");
			break;
		}

		case '0':
			running = false;
			break;
		default:
			cout << "\n\tInvalid option. Please try again.\n";
			break;
		}
	}
}
