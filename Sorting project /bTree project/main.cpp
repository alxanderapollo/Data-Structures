/*
 * this is the main file of the binary tree and binary search tree
 *
 * 11/7
 * author Alexander Apollo Salazar
 *
 * */
#include "BSTreeImp.cpp"
#include "BtreeImp.cpp"

int main(){
		//test class
	BStree<int> TreeRoot;
	  // create dummy function to insert items
	TreeRoot.insert(5);
	TreeRoot.insert(10);
	TreeRoot.insert(1);
	TreeRoot.insert(2);
	TreeRoot.display();


	return 0;
}
