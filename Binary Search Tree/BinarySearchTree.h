/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 6, 2017
 *      Author: alexandersalazar
 *      this is the class of the binary search tree
 */
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "Binarytree.h"
template <class T>
	           class BStree:
	           public bTree<T>{
	           public:
			   void deleteitem(T item);
			   void insert(T item);
			   void search(T item);

	           private:
			   void searchItem(bNode<T> *,T );
			   void deleteItem(bNode<T>*&, T item);
			   void insertREC(bNode<T>*&p, T item);
			   void deleteNode(bNode<T>*&p);
			   T getValue(bNode<T>*p);
             };
#endif /* BINARYSEARCHTREE_H_ */
