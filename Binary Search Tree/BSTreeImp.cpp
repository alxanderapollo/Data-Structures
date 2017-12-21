/*
 *  Author: Alexander Apollo Salazar
 *  This is the implementation file of of the binary search tree class
 */
#include "BinarySearchTree.h"
#include <iostream>


template <class T>
                 void BStree<T>::insert(T item){
				insertREC(this->root, item);
}
template <class T>
                 void BStree<T>::deleteitem(T item){
				 deleteItem(this->root, item);
}
template <class T>
                 void BStree<T>::search(T item){
				 searchItem(this->root, item);
}
template <class T>
                 void BStree<T>::searchItem(bNode<T>*p, T item){


                 if(p == NULL){
                	 std::cout <<"list is empty";
                	 return;
                 }
                 else if(p->info == item){
                	 std::cout<<"Found";
                	 return;
                 }
                 else if(p->info> item)
                	 return searchItem(p->left, item);
                 else{
                	 searchItem(p->right, item);
                	 return;
                 }
                	 return;
             }
template <class T>
                 void BStree<T>::insertREC(bNode<T>*&p, T item){

				 if(p ==NULL){
	            	p = new bNode<T>;
	            	p->info = item;
	            	p->left = 0;
	            	p->right = 0;
	            p->count++;
	             }
	            else if (p->info == item){ // might have to modify this, paragraphs have duplicate words
	             p->count++;
	             //delete[] p;//deallocate used memory
	             return;
	            }
	            else if(p->info > item)
	            	insertREC(p->left, item);
	            else
	            	insertREC(p->right, item);

}
template <class T>
				 void BStree<T>::deleteItem(bNode<T>*&p, T item){
	             if(p == 0){
	            	  std::cout<< "item not found";
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
						 p->info=getValue(p->left);
						 deleteNode(p->left); // this function might be wrong
					 }
}
template <class T>
                 T BStree<T>::getValue(bNode<T>*p){
				while(p->right!=NULL)
					p = p->right;

				return p->info;
}







