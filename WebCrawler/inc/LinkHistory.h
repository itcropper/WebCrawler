
#ifndef _linkHis_h_

#define _linkHis_h_

#include <string>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

using namespace std;
/*
*	this class is a BST of Type string
* 	that stores the links that have been crawled through.
* 
* 	Links that have already been crawled will cause the new link to be 
* 	ignored and not Crawled
* 
* 	New, Unique links will be added to the BST, then crawled
*/
class LinkHistory{
	private:
		LinkedList<string> * lList;
	public:
		/*
		 * default constructor that contains a Binary Search tree
		 */
		LinkHistory();

		//deletes the BST<string> * contained in the class and sets it = to NULL
		~LinkHistory();

		//inserts the string url into the BST
		void add(const string & url);

		//checks to see if the BST contains the incoming link.
		//if yes, return true, if not, return false;
		bool contains(string & incomingLink);

		
};

#endif
