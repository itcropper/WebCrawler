#ifndef _pageDown_h_

#define _pageDown_h_

#include "URLInputStream.h"
#include "HTMLTokenizer.h"
#include "HTMLToken.h"
#include "StringUtil.h"
#include "URL_Resolver.h"
#include "LinkQueue.h"
#include "Description.h"
#include "Page.h"
#include "PageList.h"


/*
 * downloads the page and distributes the contents according to what they are
 * based on htmltoken type
 */

using namespace std;

class PageDownloader{
 
	
	private:
		string URL;
		string titleString;
		string headingString;

		URLInputStream * InputStream;
		HTMLTokenizer * hTokZ;
		PageList * pagelist;
		Description * Desc;

		string bodyStrings;
		string allPageText;

		bool _seen_first_header;
		bool scopeIsAlreadySet;
		bool inBody;

		string scopeURL;



	public:
		
	PageDownloader();

	~PageDownloader();


	/*using URL inputStream, the method gets the contents from the page
	 * creates URLInputStream and HTMLTokenizer objects
	 * while the tokenizer is not empty, the method loops through and
	 * distributes the start tags and text ont he page*/
	 void downloadPage(string& pageName, LinkQueue * lq);

	 /*	sets the scope of the searchable links		*/
	 void setScope(string url);

	 //checks to see if the HTMLToken Tag is either a comment, or a TAG_END
	 bool isWorthlessTag(HTMLToken& token);

	 bool isFirstHeader(string potentialFirstHeader);

	 //checks to make sure that the incoming link is in HTML format.
	 //this includes files ending with a '/',
	 //files ending with a word,
	 //or files ending with the extension:
	 //".html", ".htm", ".shtml",
	 //".cgi", ".jsp", ".asp", ".aspx", ".php", ".pl", ".cfm
	 //extensions
	 bool isInHTMLFormat(string url);

	 void getATag(HTMLToken curTok, LinkQueue * lq);

	 /*checks to see what is contained inside the start tage.
	  * if it is a title, it appends the string to the titleString variable
	  * if it is a header, it is sent to the "isFistHeader" method
	  * if it is a link, it is resolved, checked to see if its within scope, then
	  * Inserted into the LinkQue
	  */
	 void processStartTags(HTMLToken curTok, LinkQueue * lq);

	 //gets all the text (excluding header text) and appends it to the allPageText
	 //object
	 void grabText(string remainsOfToken);

	 //checks to see if the URL coming in is inside the scope of the crawl
	 //if it isnt, the link is not added to the LinkQue object
	 bool isInScope(string url);

	 //returns the allPageText variable, representing all the text on the page
	 string getWords();

	 //creates a description from the TEXT on the page and uses it as a parameter
	 //to create a Page object, then adds that page to that pageList
	 void createPageWithNewDescription();

	 //returns all pages that have been added to the PageList object
	 PageList * getPages();


};

#endif

