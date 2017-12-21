/*
 * This is the implementation file of the binary tree class
 *  Author: Alexander Apollo Salazar
 */
#include "Binarytree.h"
#include <iostream>

template <class T>
                 bTree<T>:: bTree(){
	             root = NULL;
}
template <class T>
                 bTree<T>::~bTree(){
	             Destroy(root);
}
template <class T>
                 void bTree<T>::destroyTree(){
	             Destroy(root);
}
template <class T>
                 void bTree<T>::InOrder(void (*function)(T&,int&)){
				 InOrder(root,*function);
}
template <class T>
                  void bTree<T>::preOrder(void(*function)(T&,int&)){
	             preOrder(root, *function );
}
template <class T>
                 void bTree<T>::postOrder(void(*function)(T&,int&)){
	             postOrder(root, *function);
}
template <class T>
                 void bTree<T>::Destroy(bNode<T>* &p){
	             if(p!=NULL){
	            	 Destroy(p->left);
	            	 Destroy(p->right);
	            	 delete p;
	            	 p = NULL;
	             }
}
template <class T>
                 void bTree<T>::InOrder(bNode<T>*p,void (*function)(T&,int&)){
	             if(p!=NULL){
	            	 InOrder(p->left,*function);
	            	 function(p->info,p->count);
	            	 InOrder(p->right,*function);
	             }
}
template <class T>
                 void bTree<T>::preOrder(bNode<T>*p, void (*function)(T&,int&)){
	             if(p!=NULL){
	            	(*function)(p->info, p->count);
	            	 preOrder(p->left,*function);
	            	 preOrder(p->right,*function);
	             }
}
template <class T>
                 void bTree<T>::postOrder(bNode<T>*p, void (*function)(T&,int&)){
	                 if(p!=NULL){
	             postOrder(p->left,*function);
	             postOrder(p->right, *function);
	            	 (*function)(p->info,p->count);
	             }
}
template <class T>
                 void bTree<T>::operator=(const bTree<T>& otherTree){
	             if(this!= &otherTree){
	            	 if (root!= 0)
		               Destory(root);
	              if(otherTree.root == 0)
	            	  root = 0;
	              else
	            	  copyTree(root, otherTree.root);
	             }
	             return *this;
}
template <class T>
                 bTree<T>::bTree(const bTree<T>& otherTree){
	             if(otherTree.root == NULL){
	            	 root = NULL;
	             }
	            	 else
	            		 copyTree(root, otherTree.root);
}
template <class T>
                 void bTree<T>::copyTree(bNode<T>* &copiedTreeRoot, bNode<T>* otherTreeRoot){
				 if(otherTreeRoot == 0)
					 copiedTreeRoot = 0;
				 else{
					 copiedTreeRoot = new bNode<T>;
					 copiedTreeRoot->info = otherTreeRoot->info;
					 copyTree(copiedTreeRoot->left, otherTreeRoot->left);
					 copyTree(copiedTreeRoot->right, copiedTreeRoot->right);
				 }
}

