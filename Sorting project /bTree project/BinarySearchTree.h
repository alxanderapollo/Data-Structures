/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 6, 2017
 *      Author: alexandersalazar
 */
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "Binarytree.h"
template <class T>
	           class BStree:
	           public bTree<T>{
	           public:
			   void deleteItem(T item);
			   void insert(T item);
			   void display();
			   //creat min & max function
			   bool searchItem(bNode<T> *,T );
			   void deleteItem(bNode<T>*&, T item);
			   void insertREC(bNode<T>*&p, T item);
			   void deleteNode(bNode<T>*&p);
			   void getValue(bNode<T>*p);
             };
#endif /* BINARYSEARCHTREE_H_ */
