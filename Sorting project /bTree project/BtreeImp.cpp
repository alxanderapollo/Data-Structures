#include "Binarytree.h"
#include <iostream>
using namespace std;

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
                 void bTree<T>::inOrder(){
	             InOrder(root);
}
template <class T>
                 void bTree<T>::preOrder(){
	             preOrder(root);
}
template <class T>
                 void bTree<T>::postOrder(){
	             postOrder(root);
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
                 void bTree<T>::InOrder(bNode<T>*p){
	             if(p!=NULL){
	            	 InOrder(p->left);
	            	 cout <<p->info;
	            	 InOrder(p->left);
	             }
}
template <class T>
                 void bTree<T>::preOrder(bNode<T>*p){
	                 if(p!=NULL){
	                 cout <<p->info;
	            	 preOrder(p->left);
	            	 preOrder(p->right);
	             }
}
template <class T>
                 void bTree<T>::postOrder(bNode<T>*p){
	                 if(p!=NULL){
	            	 preOrder(p->left);
	            	 preOrder(p->right);
	            	 cout <<p->info;
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

