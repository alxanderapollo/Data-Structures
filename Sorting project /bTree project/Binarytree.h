/*
 * Binarytree.h
 *
 *  Created on: Nov 6, 2017
 *      Author: alexandersalazar
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
template <class T>
                  struct bNode{
	              T info; //node information
	              bNode<T>*  left; //left address
	              bNode<T>*  right; //right address
	              int count; //count for each word in the node
};
template <class T>
                  class  bTree{
                           protected:
	                              bNode<T>* root; //root of the tree

                           public:
	                              bTree();//default constructor
	                              ~bTree();//Destructor

	                              bool isEmpty();
	                              void inOrder();
	                              void preOrder();
	                              void postOrder();
	                              void destroyTree();

	                              //void insert(T item);

	                              bTree(const bTree<T>& otherTree);//copy constructor
	                              void copyTree(bNode<T>* &copiedTreeRoot, bNode<T>* otherTreeRoot); //copy tree function
	                              void InOrder(bNode<T> *); //In order traversal & print
	                              void preOrder(bNode<T> *);
	                              void postOrder(bNode<T> *);
	                              void Destroy(bNode<T>*&);// destroys tree
	                              void operator=(const bTree<T>& otherTree);
};
#endif /* BINARYTREE_H_ */
