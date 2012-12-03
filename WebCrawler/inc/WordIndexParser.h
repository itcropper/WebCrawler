#ifndef _WordIndexParser_h_
#define _WordIndexParser_h_

 #define DELIM	" \n\t\r\f\v"

using namespace std;

class WordIndexParser{
	/*
	 * this class iterates through the string of words it was given 
	 * and sends that word to WordIndex to be indexed
	 * along with the page's URL that it came from
	 */
	
	 private:
		string * incomingSting;
		string * copyString;
	 
	 public:
		/*
		 * constructor that sets the value of incomingString 
		 * to newString
		 */
		WordIndexParser(string * newString);
		
		/*
		 * this method first makes a copy of the incoming string to
		 * copyString, then tokenizes it based on the delimiters
		 * defined by DELIM
		 * once a single word has been identified, it sends that 
		 * word and the URL it's attatched to, to WordIndex
		 */
		void tokenizeString();
	
};
#endif
