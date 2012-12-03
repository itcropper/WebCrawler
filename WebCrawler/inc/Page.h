
#ifndef _page_h_

#define _page_h_

#include <string>
#include <string.h>
#include "LinkedList.h"
#include "BST.h"
#include <iostream>
#include "Description.h"
#include <fstream>
#include "StringUtil.h"


/*
 * this class holds URLs and a description of those URLs, obtained fromt the
 * Description class
 */
using namespace std;
class Page{
	private:
		string URL;
		Description DESC;

		
	public:
		//default constructor
		Page();

		//creates a page with a URL and DeScription as parameters
		Page(string URL, Description desc);
		

		~Page();
				
		//returns string value URL
		string & getURL();

		//compares pages using type string URL as the comparator value
		int compare(Page & other);

		//returns the string value Description obtained from the Description object
		string getDescription();

		//prints out the URL and Description of Page into ofStream&
		void pageToXML(std::ofstream& outfile) ;
};

#endif
