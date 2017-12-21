/*
 * This is the implementation file to the Rational class
 * Created by Alexander Apollo Salazar
 * 2/20/17
 * Here are prototypes, constructors and a void function
 */

#include "Rational.h"

// constructor
Rational:: Rational(int n, int d) // Receives two Arguments from the user, numerator and denominator
{
	 numerator = n;
     denominator = d;

}
//no args constructor
Rational::Rational() //default constructor
{
  numerator = 1; // by default numerator becomes 1
  denominator =1; // by default denominator becomes 1
}

Rational Rational:: operator+(Rational num) // overloads the addition operator
{
	Rational temp; //creates a temporary object
   temp.numerator = (numerator*num.denominator) + (denominator*num.numerator);
   temp.denominator = denominator*num.denominator;

    return temp; // returns the temporary object
}
 Rational Rational:: operator-(Rational num) // subtraction
{
	Rational temp;//creates a temporary object
   temp.numerator = (numerator*num.denominator) - (denominator*num.numerator);
   temp.denominator = denominator*num.denominator;

   return temp; // returns the temporary object

}

Rational Rational:: operator*(Rational num) // multiplication
{
	Rational temp;//creates a temporary object
   temp.numerator = numerator*num.numerator;
   temp.denominator = denominator*num.denominator;
   return temp;// returns the temporary object
}
Rational Rational:: operator/(Rational num) //divison
{
	Rational temp;//creates a temporary object
   temp.numerator = numerator*num.denominator;
   temp.denominator = denominator* num.numerator;

   return temp; // returns the temporary object
}
/*
 * Greatest Common Divisor
 *This function reduces fractions by the use of Euclidean algorithm
 *which implements the modulus sign, this allows us to keep taking out the reminder of a number, giving us
 * the smallest reduced value as possible
 */
  int gcd(int a, int b){

	int t =0; // temporary place holder
	while(b!= 0){ //
		t = b;
		b= a%b; // the modulus sign supplies the remainder
		a = t;
	}
	return a; // returns a
 	 }

void Rational::Reduce(){
	/*
	 *  this function does not return any values
	 *  its purpose is to one, if a negative number is inputed, to format it so that the denominator does not output with a negative sign
	 *  infront of it.
	 */
	if(denominator<0){
		numerator *= -1;
		denominator *= -1;

	}
	int divisionfactor = gcd(numerator, denominator);// this takes both the numerator and denominator
	//and makes it into a reduced form
	numerator/= divisionfactor; // divides numerator by GDC
	denominator/=divisionfactor; // divides denominator by by GCD


}
//The following are the relational operators

bool Rational :: operator==(Rational num) // checks to see if two fractions are equal
{
	return (numerator == num.numerator && denominator == num.denominator);
}
bool Rational :: operator<(Rational num) // checks to see if one is less than the other
{
	return ( numerator < num.numerator && denominator < num.denominator);
}
bool Rational :: operator<=(Rational num) // checks to see if one is less than or equal to the other
{
	return (numerator <= num.numerator && denominator <= num.denominator);
}
bool Rational :: operator>=(Rational num) // checks to see if one is greater than or equal to the other
	{
	return (numerator >= num.numerator && denominator >= num.denominator);
	}
bool Rational ::  operator!=(Rational num) // checks if one is fraction is not equal to another
		{
	return (numerator != num.numerator && denominator != num.denominator);
		}





