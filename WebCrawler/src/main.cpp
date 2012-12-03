

#define _RUNMAIN_
#ifdef _RUNMAIN_



#include "Webcrawler.h"
#include "Write.h"
#include "PageDownloader.h"
#include "StopWords.h"
#include <iostream>
#include <string>

using namespace std;

Webcrawler * wc;
Write * writer;


int main(int argc, char * argv[]){

	char ** ptr = argv;
		while(*ptr != NULL)
			++ptr;
		size_t argSize = ptr - argv;
		if(argSize != 4){
			cout << "usage: crawler <start-url> "
				 << "<output-file> <stopword-file>"
				 << endl;
			return 1;
		}
	
	string start(argv[1]);
	string outputFile(argv[2]);
	string stopword(argv[3]);

	//create a webcrawler
	wc = new Webcrawler();

	//fill that crawler with the stop words
	wc->setStopWords(stopword);

	//insert the first url into the que, and
	wc->placeStartingInfo(start);

	//crawl the web
	wc->crawl();

	//create a new Write object with the filename
	writer = new Write(outputFile);

	//get the Page objects from webcrawler and give them to writer
	writer->setPages(wc->getPages());

	//get the Word objects from Webcrawler and give them to writer
	writer->setIndex(wc->getWordIndex());

	//five the starting URL to writer and start the writing.
	writer->writeOutput(start);

//	wc->deleteStopWords();

	delete wc;
	wc = NULL;

	delete writer;
	writer = NULL;

	return 0;

}
#endif
