
#include <string>


#include "Webcrawler.h"


using namespace std;
/* 
* this main class serves as the driver. and is filled by calling the 
* methods named later int he class.
* this class also instantiates and initializes the objects that 
* it calls.
*/

Webcrawler::Webcrawler(){	
	pDowner = new PageDownloader();
	lQ = new LinkQueue();
	lHis = new LinkHistory();
	stopwords = new StopWords();
	words = new WordIndex();
}


Webcrawler::~Webcrawler(){
	delete pDowner;
	pDowner = NULL;

	delete lQ;
	lQ = NULL;

	delete lHis;
	lHis = NULL;

	delete words;
	words = NULL;

	delete stopwords;
	stopwords = NULL;
}

void Webcrawler::setStopWords(string stopWords){

	stopwords->populateStopWordTree(stopWords);

	words->setStopWords(stopwords);
}

void Webcrawler::placeStartingInfo(const string start){
	lQ->Insert(start);
	pDowner->setScope(start);
}


void Webcrawler::crawl(){

	string nextLink;
	string pageWords;

	while(!lQ->IsEmpty()){
			try{
				nextLink = lQ->getNext();
				size_t found = nextLink.find_last_of("#");
				nextLink = nextLink.substr(0, found);
				if(!lHis->contains(nextLink)){                    
					lHis->add(nextLink);
					
					pDowner->downloadPage(nextLink, lQ);

					pageWords = pDowner->getWords();

					words->placeWord(pageWords, nextLink);
				}
			}
			catch (NetworkException & e){
				cout << "NetworkException "  <<  endl;
			}
			catch (FileException & e){
				cout << "FileException" << endl;
			}
			catch (IOException & e){
				cout << "IOException" << endl;
			}
			catch (InvalidURLException & e){
				cout << "InvalidURLException " << endl;
			}
			catch (InvalidArgumentException & e){
				cout << "InvalidArgumentException" << endl;
			}
			catch (IllegalStateException & e){
				cout << "IllegalStateException" << endl;
			}
			catch (CS240Exception & e){
				cout << "CS240Exception" << endl;
			}
	}
}

PageList * Webcrawler::getPages(){
	return pDowner->getPages();
}

WordIndex * Webcrawler::getWordIndex(){
	return words;
}
