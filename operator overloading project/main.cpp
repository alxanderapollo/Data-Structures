/*
 * This is the main file of the the Rational Class
 * Created by Alexander Apollo Salazar
 * 2/20
 *
 */

#include "Rational.h"
#include <iostream>
using namespace std;

int main() {

	Rational num1, num2; // create two objects of Rational

	cout << "Enter two in Integers in fraction form a/b ";
	cin >> num1;
	num1.Reduce(); // Reduce's num1 input

	cout << "Enter two in Integers in fraction form a/b ";
	cin >> num2;
	num2.Reduce(); //reduces num2 input

	cout << "\n Adding: Num1 :" << num1 << " + num2 :" << num2 << " = "
			<< num1 + num2; // addition

	cout << "\n Subtraction:" << num1 << " - " << num2 << " = " << num1 - num2; // Subtraction

	cout << "\n Multiplication: " << num1 << " * " << num2 << " = "
			<< num1 * num2; // Multiplication

	cout << "\n Division: " << num1 << " / " << num2 << " =  " << num1 / num2; // Division

	if (num1 == num2) { // equivalent operator
		cout << "\nBoth fractions are equivalent ";
	} else if (num1 != num2) { // not equal operator
		cout << "\nThe Fractions are non equivalent ";
	}

	if (num1 <= num2) { // less than or equal to
		cout << "\nFraction one is less than but equal to Fraction two";
	} else if (num1 >= num2) { // greater than or equal to
		cout << "\nFraction two is Greater than but equal to Fraction one";
	}

	if (num1 < num2) { // less than
		cout << "\nThe first fraction is smaller than the Second Fraction";
	} else if (num2 < num1) {
		cout << "\nThe first fraction is smaller than the Second Fraction";
	}

	return 0;
}
