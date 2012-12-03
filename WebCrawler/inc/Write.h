
#ifndef _Write_CS240_h_

#define _Write_CS240_h_

#include <string>
#include <fstream>
#include <cstdio>
#include "Page.h"
#include "BST.h"
#include "WordIndex.h"
#include "Word.h"
#include "PageList.h"

using namespace std;

class Write{
	private:
		string * startingURL;
		PageList * pages;
		WordIndex * Index;
		ofstream outfile;


	public:

		//opens the file to be written to using 'ofStream'
		Write(string fileName);

		//closes ofStream
		~Write();

		/*
		 * begins the process of writing the output, starting with the incoming startURL
		 * this method then calls writePages and writeIndex
		 */
		void writeOutput(string start);

		/*
		 * write the starting URL
		 */
		void writeStart(string start);

		/*
		 * calls the writetoXML method from Pagelist
		 */
		void writePages();

		/*
		 * calls the write to XML method from WordIndex
		 */
		void writeIndex();

		/*
		 * sets the value of the variable pages equal to incomingPages
		 */
		void setPages(PageList * incomingPages);

		/*
		 * sets the value of Index to incomingIndex
		 */
		void setIndex(WordIndex * incomingIndex);
};

#endif

