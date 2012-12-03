
#ifndef _webcrawler_h
#define _webcrawler_h

#include "CS240Exception.h"
#include "StopWords.h"
#include "LinkQueue.h"
#include "LinkHistory.h"
#include "PageDownloader.h"
#include "Description.h"
#include "HTMLParser.h"
#include "WordIndex.h"
#include "Page.h"


#include <string>
/* 
 * this main class serves as the driver. and is filled by calling the 
 * methods named later int he class.
 * this class also instantiates and initializes the objects that 
 * it calls.
 */
using namespace std;
 
class Webcrawler{
	private:
		LinkQueue * lQ;
		LinkHistory * lHis;
		PageDownloader * pDowner;

 		bool scope;
 		WordIndex * words;
 		StopWords * stopwords;
		

	public:

		Webcrawler();

		~Webcrawler();
		
		/*
		 * uses the incoming file to  populate the stopword Objects
		 */
		void setStopWords(string stopWords);
		/*
		 * sets the starting URL in the linkQue and sets the scope of the pending crawl
		 */
		void placeStartingInfo(const string start);
		
		/*
		 * uses a while loop to crawl the pages obtained from the linkeQue so long as it is not empty
		 * it also handles all exceptions
		 */
		void crawl();
		
		//returns pages from the PageList Object that is gradually filled as the pages are downloaded
		PageList * getPages();

		//returns the index of words that are gradually filled as the pages are downloaded
		WordIndex * getWordIndex();


};
#endif
