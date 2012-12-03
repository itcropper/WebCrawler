
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "HTMLParser.h"
#include "HTMLTokenizer.h"

using namespace std;
/*
 *	Iterates through the webpage, and using HTMLTokenizer, parses
 * the webpage into its separate parts. 
 */

//default constructor
HTMLParser::HTMLParser(){
	
}
/* if URL is already in link History, it is ignored	*/
bool HTMLParser::isInLinkHistory(string * url){
	return false;
}

/*
 * checks incoming token from HTML tokenizer. If it is an
 * "A" tag it sends the url inside of that A tag to the LinkQue
 */
void HTMLParser::grabAllHRefs(string reference){
	
}

/*
 * if token type is "text", it sends that text through the 
 * wordIndexParser with the current URL
 */
void HTMLParser::sendTextToWordIndexParser(string text){
	
}


/* if tag is end, start, or comment, move on to next token	*/
bool HTMLParser::checkIfTokenIsMeaningless(string type){
	return false;
}

/* if token is the end token, then it signifies that the stream
 * for this page is done, and the next link in the queue
 * can be crawled
 
bool HTMLParser::checkIfEnd(Token end){
	
}
*/
