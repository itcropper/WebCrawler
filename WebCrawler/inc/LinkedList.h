#ifndef CS240_LINKED_LIST_H
#define CS240_LINKED_LIST_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T> class LinkedList;

template <typename T> 
class LLNode {
		friend class LinkedList<T>;
		
	public:
		T value;
		LLNode<T> * prev;        
		LLNode<T> * next;   
		
	
	
		//!  Constructor
		LLNode(const T & v, LLNode<T> * p, LLNode<T> * n) :
		  value(v), prev(p), next(n){
		}
		
		//! Copy Constructor 
		LLNode(const LLNode<T> & other) :
		   value(other.value),prev(other.prev),next(other.next){
		}
	
		//!  Read-only public methods for use by clients of the LinkedList class
		const T & GetValue() const{
		  return value;
		}
	
	
		LLNode<T> * GetPrevious()const{
		  return prev;
		}
	
	
		LLNode<T> * GetNext()const{
		  return next;
		}
		
		//! Assignment operator 
		LLNode<T> & operator=(const LLNode & other){
			if(this!=&other){
				value=other.value;
				prev=other.prev;
				next=other.next;
			}
			return *this;
		}
};

//! LinkedList implements a doubly-linked list
template <typename T> 
class LinkedList{
	
	private:
		LLNode<T> * first;
		LLNode<T> * last;
		int size;
		
	public:
		//!  No-arg constructor.  Initializes an empty linked list
		LinkedList() : size(0), first(NULL), last(NULL){
		}

		//!  Copy constructor.  Makes a complete copy of its argument
		LinkedList(const LinkedList<T> & other){
			size = 0;
			copyList(other);
		}

		//!  Destructor
		~LinkedList(){
			Clear();
		}
	
		//! Assignment operator.  Makes a complete copy of its argument
		//! @return A reference to oneself
		LinkedList<T>& operator =(const LinkedList<T> & other){
			if(this != &other){
				Clear();
				copyList(other);
			}
			return *this;
		}
	
		//!  @return true if the list is empty, or false if the list is not empty
		bool IsEmpty() const{
			return (size == 0);
		}
	
	
		//!  Removes all values from the list
		void Clear(){
			while(first !=NULL){
				Remove(first);		
			}
			first = NULL;
			last = NULL;
		}
	
		//!  @return the number of values in the list
		int GetSize() const{
			return size;
		}
	
		//!  @return a pointer to the first node in the list, or NULL if the list is empty
		LLNode<T> * GetFirst()const{
			return first;
		}
	
		//!  @returns a pointer to the last node in the list, or NULL if the list is empty
		LLNode<T> * GetLast()const{
			return last;
		}
	
		//!  Inserts value v into the list after node n
		//!  
		//!  @param v The new value being inserted
		//!  @param n A node that is already in the list after which the new node should 
		//!      be inserted.
		//!      If n is NULL, the new node should be inserted at the beginning of the list.
		//!
		//!  @return a pointer to the newly inserted node
		LLNode<T> * Insert(const T & v, LLNode<T>  * n){
			if(IsEmpty()){
				first = new LLNode<T>(v, NULL, NULL);
				last = first;
				size++;
				return first;
			}
			if(n == NULL){
				LLNode<T> * temp = new LLNode<T>(v, NULL, first);
				first->prev = temp;
				first = temp;
				size++;
				return temp;
			}
			else if(n == last){
				LLNode<T> * temp = new LLNode<T>(v, last, NULL);
				last->next = temp;
				last = temp;
				size++;
				return temp;
			}else{
				LLNode<T> * temp = new LLNode<T>(v, n, n->next);
				n->next->prev = temp;
				n->next = temp;
				size++;
				return temp;
			}
		}
	
	
		//! Searches for the first occurrence of value v that appears in the list 
		//!   after node n
		//!   
		//!  @param v The value being searched for
		//!  @param n The node in the list after which the search should begin.
		//!      If n is NULL, the list should be searched from the beginning.
		//!
		//!  @return a pointer to the node containing v, or NULL if v is not found
		LLNode<T> * Find(const T & v, LLNode<T> * n) const{
			if(IsEmpty())
				return NULL;
			LLNode<T> * current;
			if(n == NULL){
				current = first;
				while(current != NULL){
					if(current->GetValue() != v)
						current = current->next;
					else 
						return current;
				}
				return NULL;
			}
			else {
				current = n->next;
				while(current != NULL){
					if(current->GetValue() == v)
						return current;
					else
						current = current->next;
					}
				}
				return NULL;
		}

		bool contains(const T & v){
			if(this->Find(v, NULL) == NULL)
				return false;
			else
				return true;

		}
	
	
		//!  Removes node n from the list
		//!  
		//!  @param n The node being removed from the list
		void Remove(LLNode<T> * n){
			if(IsEmpty())
				return;
			else{
				if(size == 1){
					first = last = NULL;
					size--;
				}
				else if(n == first){
					first->prev = NULL;
					first = n->next;
					size--;
				}
				else if(n == last){
					last = last->prev;
					last->next = NULL;
					size--;
				}else{
					n->prev->next = n->next;
					n->next->prev = n->prev;
					size--;
				}
			}
			delete n;
		}	
		
		void copyList(const LinkedList<T> & other){
			first = last = NULL;
			size = 0;
			size = other.size;
			LLNode<T> * cur = other.first;
			LLNode<T> * nLast = 0;
			while(cur != NULL){
				LLNode<T> * cNode = new LLNode<T>(cur->value, NULL, NULL);
				if(nLast == NULL){
					first = last = cNode;
					nLast = cNode;
				}else{
					nLast->next = cNode;
					cNode->prev = nLast;
					nLast = cNode;
					last = nLast;
				}
				cur = cur->next;
			}
		}
		
		void print(){
			if(first == NULL)
				return;
			LLNode<T> * current = first;
//			cout << "first = " << first->GetValue() << endl;
			while(current != last){
				cout << current->GetValue() << endl;
				current = current->next;
			}
			cout << current->GetValue() << endl;
		}
		

	
};
#endif

