#ifndef _pageList_h_

#define _pageList_h_

#include "BST.h"
#include "LinkedList.h"
#include "Page.h"


using namespace std;
class PageList{
	/*
	 * this class serves as a set of instances of 'Occurence'
	 * created by the class WordIndex to keep track of how 
	 * often words occur on a given webpage
	 */
	private:
		BST<Page> * pageList;
	public:
	
		PageList();

		~PageList();
		
		/*
		 * adds the incoming page to the BST<Page>
		 */
		void addNewPage(string url, Description desc);

		/*
		 * checks to see if there are any elements in the BST pageList
		 */
		bool IsEmpty();

		//if the pageList is not empty, it calls the RecurseToXML method
		void InfixToXML(std::ofstream& outfile);

		/*
		 * recursively goes through and calls the write-to-XML method for Each page
		 */
		void RecurseToXML(std::ofstream& outfile, BSTNode<Page> * node);
	
};
#endif
