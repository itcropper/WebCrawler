#ifndef CS240_BST_H
#define CS240_BST_H

#include <iostream>

template <typename T> class BST;

template <typename T> 
class BSTNode {
		friend class BST<T>;
		
	private:
		T value;  
		BSTNode<T> * left;    
		BSTNode<T> * right;  	
		
	public:

		BSTNode(T & v) : value(v), left(NULL), right(NULL){
		}
		BSTNode(BSTNode<T> & other) :
		  value(other.value),left(other.left),right(other.right){
		}
		
		T & GetValue(){
		  return value;
		}
	
		BSTNode<T> * GetLeft(){
		  return left;
		}
	
		BSTNode<T> * GetRight(){
		  return right;
		}

		BSTNode<T> & operator=(BSTNode<T> & other){
			if(this!=&other){
				value=other.value;
				left=other.left;
				right=other.right;
			}
			return *this;
		}
//		int compare(BSTNode<T> & other){
//            bool awesome;
////			return this.compare(other.GetValue());
//		}

};

template <typename T>  
class BST {

	private:
		BSTNode<T> * root;
		int size;
		BSTNode<T> * newer;
		
		BSTNode<T> * CopyNode(BSTNode<T> & node){

			if (&node == NULL)
				return &node;
	
			BSTNode<T> * copiedNode = new BSTNode<T>(node);
			copiedNode->left = CopyNode(*node.left);
			copiedNode->right = CopyNode(*node.right);
	
			return copiedNode;
		}
		
		void CopyTree( BST<T> & other){
 		   if (other.root != NULL)
        		root = CopyNode(*other.root);
    		 else
				root = NULL;
				size = other.size;
		}
		
		BSTNode<T> * FindNode(T & v, BSTNode<T> & node){

			if(&node == NULL){  
				return NULL;
			}
			else if(v.compare(node.GetValue()) < 0) {
				return FindNode(v, *node.left);
			}
			else if(v.compare(node.GetValue()) > 0){
				return FindNode(v, *node.right);
			}
			else if(v.compare(node.GetValue()) == 0){
				return &node;
			}
			return NULL;
		}
		
		BSTNode<T> * InsertNode(T & v, BSTNode<T> & node){
			if(&node == NULL){
				BSTNode<T> * newNode = new BSTNode<T>(v);
				size++;
				newer = newNode;
				return newNode;
			}
			else if(v.compare(node.GetValue()) < 0){
				node.left = InsertNode(v, *node.left);
			}
			else if(v.compare(node.GetValue()) > 0){
				node.right = InsertNode(v, *node.right);
			}
			else{ 
				newer = NULL;
			}
			return &node;
		}
		
		
		
		void clearRec(BSTNode<T> * node){
			if(node == NULL)
				return;
			clearRec(node->left);
			clearRec(node->right);
			delete node;
		}
		
	public:
		BST(){
			size = 0;
			root = NULL;
		}
		
		BST(BST<T> & other){
			CopyTree(other);
		}
		~BST(){
			Clear();
		}
			
		BST<T> & operator =( BST<T> & other){
			if(this != &other){
				Clear();
				CopyTree(other);
			}
			return *this;
		}

		BSTNode<T> * GetRoot(){
			return root;
		}
	
		bool IsEmpty() {
			return (size == 0);
		}
	

		void Clear(){
			clearRec(root);
			root = NULL;
			size = 0;
		}
	
		int GetSize() {
			return size;
		}
	
		BSTNode<T> * Insert(T & v){
			if(IsEmpty()){ 
				root = new BSTNode<T>(v);
				size++;
				return root;
			}
			InsertNode(v, *root);
			return newer;
		}

		BSTNode<T> * Find(T & v){
			return FindNode(v, *root);
		}

		bool contains(T & v){
			if(this->Find(v) == NULL)
				return false;
			else
				return true;

		}
};

#endif
