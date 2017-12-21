/*
 * Binarytree.h
 *
 *  Created on: Nov 6, 2017
 *      Author: alexandersalazar
 *      This is the class of the binary tree
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
template <class T>
                  struct bNode{
	              T info; //node information
	              bNode<T>*  left; //left address
	              bNode<T>*  right; //right address
	              int count = 0; //count for each word in the node
};
template <class T>
                  class  bTree{
                           protected:
	                              bNode<T>* root; //root of the tree
	                              void InOrder(bNode<T>*,void (*function)(T&,int&)); //In order traversal & print
	                              void preOrder(bNode<T> *,void (*function)(T&,int&));
	                              void postOrder(bNode<T> *,void (*function)(T&,int&));

                           public:
	                              bTree();//default constructor
	                              ~bTree();//Destructor

	                              bool isEmpty();
	                              void InOrder(void (*function)(T&,int&));
	                              void preOrder(void (*function)(T&,int&));
	                              void postOrder(void (*function)(T&,int&));
	                              void destroyTree();
	                              bTree(const bTree<T>& otherTree);//copy constructor
                           private:
	                              void copyTree(bNode<T>* &copiedTreeRoot, bNode<T>* otherTreeRoot); //copy tree function
	                              void Destroy(bNode<T>*&);// destroys tree
	                              void operator=(const bTree<T>& otherTree);
};
#endif /* BINARYTREE_H_ */
