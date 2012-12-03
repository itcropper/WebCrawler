#ifndef _STOPWORDS_240_h_

#define _STOPWORDS_240_h_

#include "StringUtil.h"
#include <string.h>
#include "BST.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class StopWords{
	private:
		string * stopWords;
		int numberOfWords;

	public:
		StopWords();

		~StopWords();

		//checks to see if a given line that comes from the file is empty.
		//if it is, it is not added to the array of stopWords
		bool isEmpty(char * singleLine);

		//calls the methods getNumberOfLines and fillArray, in that order
		void populateStopWordTree(string fileName);

		//opens the file using ifStream and goes through the incoming file
		//doing nothing but counting the number of lines contained in the file.
		//the method then initializes the array of stopWords using the number obtained
		void getNumberOfLines(string fileName);

		/*
		 * goes through the file and gets each line, and copies it to the array of stopWords
		 * until there are no more words in the file.
		 */
		void fillArray(string fileName);

		//uses a while loop to continuously cut the array in half to find a match for the
		//incoming word. If it finds the word, true is returned, if never found, false is
		//returned.
		bool contains(string word);

};
#endif
