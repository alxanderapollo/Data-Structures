/*
 * Largeint.h
 *
 *  Created on: Mar 8, 2017
 *     Author: Alexander Apollo Salazar
 *     Purpose  to implement a integer type as a c++ class, that will allow users to store
 *     and manipulate very large integers.
 */
#ifndef LARGEINT_H_
#define LARGEINT_H_
#include <iostream>
#include <string>
using namespace std;

class Largeint
{
	friend ostream &operator<<(ostream &osObject, const Largeint &out)
	{

		//This is the ouput. And you should display the array
		//by using a loop eg.
		for(int i = 0; i<out.length; i++)
		osObject << out.Array[i];

		return osObject; // not sure what to place here
	}

	friend istream &operator>>(istream& in, Largeint& i)
	{
		string str; // create a string
		getline(in, str); // the in object reads the input as a number
		int size = str.length(); // here we return the length of the string

		i.Max = size; // Large int object i equals max equals
		i.length = size; // Large int object i equals the length*/

		i.Array = new int[size];
		for (int j = 0; j<size; j++)
			i.Array[j] = str[j] - '0';

		return in;
	}

public:

	Largeint(int m = 0); // constructor takes maximum
	~Largeint(); // Destructor called at the end of the objects scope
	Largeint(const Largeint& otherobj); //copy constructor

	Largeint operator+(Largeint); //overloads addition operator
	Largeint operator=(Largeint); // overloads the assignment operator
	bool operator==(const Largeint other); // overloads comparison operator

private:
	int Max; // will store the maximum size of the array
	int length; // will store the actual length of the array
	int* Array; // pointer variable

};

#endif

