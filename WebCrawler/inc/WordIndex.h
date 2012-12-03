
#ifndef _WordIndex_CS240_h

#define _WordIndex_CS240_h

#include "Word.h"
#include "BST.h"
#include "StopWords.h"
#include "Occurence.h"

using namespace std;


class WordIndex{
	private:
		BST<Word> * wordIndex;
		Word word;
		StopWords * stopwords;
		BST<string> * existingWords;
	public:
		WordIndex();
		/*
		 * constructor sets value to word to menber variable value, word
		 * and value to URL to member variable URL
		 */

		~WordIndex();

		Word & getWordValue(const Word & tempWord);

		//checks to see if the incoming word is comtained withing the array of stopWords
		bool isAStopWord(string stopWord) ;
		
		//checks to see if the incoming word would be invalid for any other reason such as being a lone number,
		// or starting with a number
		bool isInvalidWord(string word);

		string removeSpace(string word);

		/*
		 * separates the incoming string into tokens based on the delimiters of space, and invalid puncuation
		 * if a word is unique, a new Word object is created with that word and the incoming URL
		 * if it is not unique, the method Insert Exiting is called
		 */
		 void placeWord(string word, string URL);

		 /*
		  * checks to see whether the URL is contained already in an instance of Occurence in the occurence set
		  * if it is, the count for that page is incremented
		  * if it doesnt then a new Occurence object is create and added to the occurence BST
		  */
		 void InsertExisting(Word * tempWord, string URL);

		 /*
		  * meerly recieves a pointer to the stopWord object in order to exclude words contained within the array
		  */
		 void setStopWords(StopWords  * stopWords);

		 /*
		  * calls the recurse to XML method after printing the necessary values
		  */
		 void IndexToXML(std::ofstream& outfile);

		 /*
		  * recursively calles the print to XML method for each Word object contained within the BST of Word objects
		  * comprising WordIndex
		  */
		 void RecurseToXML(std::ofstream& outfile, BSTNode<Word> * node);
};
#endif
