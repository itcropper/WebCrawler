
#ifndef DESCRIPTION_H_
#define DESCRIPTION_H_


/*
 * create on object 'Description' with input url, string title, string firstheader,
 * and string bodyCharacters.
 * This class returns the string 'Description' in the order of importance
 * 1. title
 * 2. first header
 * 3. first 100 body characters
 * if all of these are NULL, return an empty string value
 */
#include <string>
#include <iostream>

using namespace std;

class Description{
	private:
		string pageDescription;

	public:
		Description();

		Description(string incomingTitle, string incomingHeader, string bodyChars);
		
		~Description();

		//take only the first 100 characters from bodyChars and return them
		string setBodyChars100(string bodyChars);

		//return appropriate Description
		string getDescription() const;

};

#endif
