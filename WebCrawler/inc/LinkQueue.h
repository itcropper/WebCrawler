#ifndef _LQ_h_
#define _LQ_h_

#include <string>
#include "LinkedList.h"

class LinkQueue{
	/*
	 * uses LinkedList as a que for incoming URLs
	 */
	private:
		LinkedList<string> * que;
		string tempGet;
	public:
	
		/* 
		 * default constructor consisting of a LinkedList
		 */
		LinkQueue();
		
		//deletes the LinkedList<string> * and sets the value = to NULL
		~LinkQueue();
		
		

		/* 
		 * gets the nextURL on queue by accessing the last node of LList
		 * the method then moves the pointer "checked" ahead in the list
		 * to signify that that element has been used. It is kept in the
		 * Queue
		 */
		string getNext();
		
		
		/* 
		 * puts a URL in the queue by inserting the value (URL) into the 
		 * LinkedList at position 'first' 
		 */
		void Insert(const string & url);

		//gets size of queue
		bool IsEmpty();
		
};
#endif
