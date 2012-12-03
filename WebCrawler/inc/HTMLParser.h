
#ifndef _HTMLP_h_

#define _HTMLP_h_

using namespace std;

	class HTMLParser{
	/*
	 *	Iterates through the webpage, and using HTMLTokenizer, parses
	 * the webpage into its separate parts. 
	 */
	private:
		//instantiates the HTMLTokenizer;

	public:
		//default constructor
		HTMLParser();
		/* if URL is already in link History, it is ignored	*/
		bool isInLinkHistory(string * URL);
		
		/*
		 * checks incoming token from HTML tokenizer. If it is an
		 * "A" tag it sends the url inside of that A tag to the LinkQue
		 */
		void grabAllHRefs(string reference);
		
		/*
		 * if token type is "text", it sends that text through the 
		 * wordIndexParser with the current URL
		 */
		void sendTextToWordIndexParser(string text);
		
		
		/* if tag is end, start, or comment, move on to next token	*/
		bool checkIfTokenIsMeaningless(string type);
		
		/* if token is the end token, then it signifies that the stream
		 * for this page is done, and the next link in the queue
		 * can be crawled
		 */
	//	bool checkIfEnd(Token end);
};
#endif
