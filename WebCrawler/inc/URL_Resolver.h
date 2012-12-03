#ifndef _URLRes_h_
#define _URLRes_h_

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>

#define WEB_PREFIX "http://"
#define FILE_PREFIX "file:///"
#define FileSize 9

using namespace std;

class URL_Resolver{
	private:

		

		string SCHEME;
		string NET_LOC;
		string PATH[64];
		
		string RELATIVE;
		string BASEURL;
		
		bool schemeIsWeb;
		bool noPath;
		
		
		int pathCount;
		int backCount;
		
		string RESOLVED;
		
	public:

		URL_Resolver();
		~URL_Resolver();

		/*
		 * retreives the scheme of type 'file:///'
		 * of of type 'http://' from the incoming base URL
		 */
		void getScheme(string base);

		/*
		 * gets the net-location from the base URL
		 * if the URL is a local URL, the the empy string is
		 * appended to the netLoc variable
		 */
		void getNET_LOC(string base);

		/*
		 * parses the BASE url path using '/' as a delimiter
		 */
		void parsePath(string base);
		/*
		 * calls the methods getScheme(), getNetLoc(), and parsePath()
		 */
		void parseBase(string base);
		/*
		 * parses the relative URL searching for the key starting options
		 * of #, /, ../, ./, or nothing
		 */
		void parseRelative(string relitive);
		
		/*
		 * if the relative URL starts with a '?', this method is called
		 * whci searches for a '?' in the base URL, and contatinates
		 * the baseURL and RelativeURL from that point in the baseURL
		 */
		void combineQueries();

		/*
		 * combines the base url and the relative URL in the order that they need to be
		 * based on the prefix of the relative URL
		 */
		void joinBaseAndRel();

		/*
		 * checks to see if the 'relative' URL is a relative URL. if it is,
		 * then it calls the methods, parse base, parse relative and joinBaseAndRel
		 */
		string resolveURLs(string base, string relative);

		//checks to see whether the incoming relative URL is a relative URL that needs
		//resolving, or if it cane be used as a full URL
		bool isRelative(string relative);

		//meerly checks to see whay type of symbols are in the URLs and what they start with
		bool isStartOfRelPath(char symbol);

		bool Test(ostream & os);

};

#endif
