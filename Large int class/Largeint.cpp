/*
* Largeint.cpp
*
*  Created on: Mar 8, 2017
*      Author: alexandersalazar
*/
#include "Largeint.h"
#include <iostream>
#include <assert.h>
using namespace std;


Largeint::Largeint(int size)
{ //constrcutor

	if(size< 0)
	{
		return;
		//cout<<"The array size must be of Positive Integers";
		//Max = 100;
	}
	else
	{
		Max = size;
		length = 0;
		Array = new int[Max];
	}
	//assert(Array != null);
}


Largeint::Largeint(const Largeint& obj)
{
	// copy constructor
    length = obj.length;
	Max = obj.Max;
	Array = new int[Max];
	assert(Array != NULL);          //No such thing as null in c++...Is capitalized NULL
	                                //Include the library #include<assert.h> in order to use the keyword.
	for(int i = 0; i< length; i++)
	Array[i] = obj.Array[i];
}

Largeint::~Largeint()
{	//destructor
	delete[] Array;
}

Largeint Largeint::operator=(const Largeint obj)
{ //assignment operator
	if(this != &obj){
		delete [] Array;
		Max = obj.Max;
		length = obj.length;
		Array = new int[length];
		//assert(Array != null);
		for(int i = 0; i<length; i++)
		Array[i] = obj.Array[i];
    }
	return obj;
}

bool Largeint:: operator==(const Largeint other)
{ // compartive function

	for( int i =0; i < length; i++)
	{
		if(Array[i] != other.Array[i])
		return false;
	}
	return true;
}
Largeint Largeint::operator+(Largeint secondNum)
{
	Largeint temp;

	if(secondNum.Max>Max)
		temp.Max = secondNum.Max+1;
	else
		temp.Max = Max+1;

	temp.length = 0;
	int num = 0;
	int carry = 0;


	int i = length-1,
        j =secondNum.length-1,
		g = 0;

//for(i,j ; i>=0 ||  j>=0; i--, j--,g++)
	for( ; i>=0 ||  j>=0; i--, j--,g++)
	{
		if(i>=0)
			num += Array[i];
		else if(j>=0)
			num += secondNum.Array[j];

		num+= carry;

		if(num >= 10)
		{
			num = num - 10;
			carry = 1;
		}
		temp.Array[g] = num;
		temp.length++;
		num = 0;
    }

	for(int i = 0; i<temp.Max; i++)
		cout<<"m:" << temp.Array[i];

	//123
	//911
	//1 0 3 4

	return temp;
}

