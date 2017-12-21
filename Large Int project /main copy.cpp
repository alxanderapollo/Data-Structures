
#include "Largeint.h"
#include <iostream>

using namespace std;

int main(){
	Largeint x,y,z;
	cout << "Enter an integer of your choice: ";
	cin >>x;
	cout << "Enter an integer of your choice: ";
	cin >>y;

	if(x==y)
		cout<<"\n\nThe Two numbers entered are equal";
	else
		cout <<"\n\nThe two numbers entered are different";
		z= x+y;

		cout<<"\n\nThe sum of"<<x<<" And " <<y<< "is: "<<z;





	return 0;
}

