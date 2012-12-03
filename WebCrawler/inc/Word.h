
#ifndef _Word_CS240_h_
#define _Word_CS240_h_

#include <string>
#include "Occurence.h"
#include "BST.h"
#include "StringUtil.h"

using namespace std;
class Word{


private:
	string Value;
	string URL;
	BST<Occurence> occurences;

public:

	Word();
	Word(string val, string url);

	Word(BST<Occurence> & other);

	~Word();

	/*
	 * returns the word value of the object
	 */
	string getValue();

	/*
	 * creates a new occurence object with the incoming URL
	 */
	void addNewOccurrenc(string url);
	
	/*
	 * calls the methodod FindRecURL, with the incoming URL, and the root of the Occurence set
	 * contained in this object
	 */
	Occurence* FindURL(string url);

	//recursively goes through the occurences to see if the URL is already contained in an instance of Occurence
	Occurence * FindRecURL(string v, BSTNode<Occurence> & node);

	//compares Word objects using the word Value as the comparator object
	int compare(Word & other);

	//calls the occurence to XML method
	void  wordToXML(std::ofstream& outfile);

	//recursively calls the write to XML method of each occurence object
	void occurenceToXML(std::ofstream& outfile, BSTNode<Occurence> * node);

};
#endif
