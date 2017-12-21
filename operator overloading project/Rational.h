/*
 * This is the Rational class file
 * Created by Alexander Apollo Salazar
 * 2/20/17
 * The purpose of the program:
 *
 * To overload assignment operators (i.e +, -, =, *), as well as Relational operators(i.e.  and the extraction
 * and insertion operator. In this program we take inputs in the form of a/b, b/c and either multiply, add, subtract
 * or Divide.
 * Then we use Relational operators to determine if one is bigger, or smaller, or equal to one another
 */

#include <iostream>
using namespace std;

#ifndef Project_h
#define Project_h

class Rational
{
	//overloading extraction operator
	friend ostream  &operator<<(ostream &osObject, const Rational &num)
	{
		 return osObject << num.numerator << "/" << num.denominator;

	}
	// overloading insertion operator
	friend istream &operator>>(istream &isObject, Rational &num)
	{
	  char ch; // this is a place holder for when the user inputs "/"
	   return isObject >> num.numerator>> ch >>num.denominator;
	}




public:
  Rational(int n, int d); //Constructor Takes two arguments, n for numerator, d for denominator
  Rational(); // no argument constructor
  void Reduce(); // this is a function prototype, Returns nothing, its purpose to reduce fractions.


   /*This next piece of code overloads the assignment operators, and allows us manipulate two objects accordingly
    * The first is the addition assignment
    * next is the subtraction assignment
    * then the multiplication assignment
    * finally the division assignment
    */
  Rational operator+(Rational); // (a/b) + (c/d)
  Rational operator-(Rational); // (a/b) - (c/d)
  Rational operator*(Rational); //(a/b) * (c/d)
  Rational operator/(Rational); // (a/b) / (c/d)

  /*The next piece of code overloads the relational operators
   * first check to see if something is equivalent to another fraction by comparing numbers
   * the following checks if something is less than something else
   * next we check to see if something is greater than something else
   * we check to see if something is less than or equal to something else
   * we check to see if something is greater than or equal to something else
   * finally we check to see if something is not equal to something else
   */
  bool operator==(Rational); // (a/b) == (c/d)
  bool operator<(Rational); // (a/b) < (c/d)
  bool operator>(Rational); // (a/b) > (c/d)
  bool operator<=(Rational); // (a/b) <= (c/d)
  bool operator >=(Rational); // (a/b) >= (c/d)
  bool operator !=(Rational); // (a/b) != (c/d)



private:
  int numerator; // private member numerator
  int denominator;// private member denominator

};
#endif
