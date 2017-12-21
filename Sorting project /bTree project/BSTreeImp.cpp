#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


template <class T>
                 void BStree<T>::insert(T item){
				insertREC(this->root, item);
}
template <class T>
                 void BStree<T>::display(){
				 getValue(this->root);
}

template <class T>
                 bool BStree<T>::searchItem(bNode<T>*p, T item){


                 if(p == NULL){
                	 return false;
                 }
                 else if(p->info == item)
                	 return true;
                 else if(p->info> item)
                	 return searchItem(p->left, item);
                 else
                	 return searchItem(p->right, item);
}
template <class T>
                 void BStree<T>::insertREC(bNode<T>*&p, T item){

				 if(p ==NULL){
	            	p = new bNode<T>;
	            	p->info = item;
	            	p->left = 0;
	            	p->right = 0;
	            	p->count = 1;
	             }
	            //else if (p->info == item){ // might have to modify this, paragraphs have duplicate words
	            	//cout<<" no duplicates";
	            	//return;
	            //}
	            else if(p->info > item)
	            	insertREC(p->left, item);
	            else
	            	insertREC(p->right, item);

}
template <class T>
				 void BStree<T>::deleteItem(bNode<T>*&p, T item){
	             if(p == 0){
	            	  cout<< "item not found";
	            	  return;
	              }
	              else{
	            	  if(p->info == item)
	            		  deleteNode(p);
	            	  else if(p->info > item)
	            		  deleteItem(p->left, item);
	            	  else
	            		  deleteItem(p->right, item);
	              }



}
template <class T>
				 void BStree<T>::deleteNode(bNode<T>*&p){
					 bNode<T>*q;
					 q=p;
					 if(p->left == 0){
					 p = p->right;
					 delete q;
					 }
					 else if(p->right == 0){
						 p=p->left;
						 delete q;
					 }
					 else
					 {
						 p->info =getValue(p->left);
						 deleteItem(p->left); // this function might be wrong
					 }
}

template <class T>
                 void BStree<T>::getValue(bNode<T>*p){

					if(p == NULL){
						cout<<"empty list";
						return;
					}
					else if(p!=NULL){
						 getValue (p->right);
						 cout<< p->info<<"\n";
						 getValue(p->left);

					}




             }

