#ifndef _Occ_h_
#define _Occ_h_

#include "Page.h"
#include <string>
#include "BST.h"
#include "StringUtil.h"


using namespace std;

class Occurence{
	/*
	 * this class serves as an opbject to hold a page, attatched to 
	 * the number of times a specific word has been used on that page
	 * each instance of this class coresponds to a specific word on the 
	 * page, also in this class
	 */
	private:
		string URL;
		int count;

	public:

		Occurence();

		/* constructor: sets string URL = to incoming page
		 * increments the count to signify the word
		 * was used again.
		 */
		Occurence(string url);


		~Occurence();

		//returns string URL
		string getURL();

		//returns int get count, representing the number of times
		//the word value of the superclass Word has been seen on this URL
		int getCount();

		//increments the count of an existing occurences object (this)
		void addCount();

		//compares occurences using string URL as the comparable
		int compare(Occurence & other);

		//gets the URL and the Count writes them to the incoming ofStream&
		void OccurenceToXML(std::ofstream& outfile);

};
#endif
