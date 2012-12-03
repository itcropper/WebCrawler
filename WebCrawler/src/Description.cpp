
#include "Description.h"


Description::Description(){

}

Description::Description(string incomingTitle, string incomingHeader, string body){

//	cout << body << endl;
	if(incomingTitle != "")
		this->pageDescription = incomingTitle;
	else if(incomingHeader != "")
		this->pageDescription = incomingHeader;
	else if(body != "")
		this->pageDescription = setBodyChars100(body);
	else
		this->pageDescription = "";

}
Description::~Description(){
}

string Description::setBodyChars100(string body){

	int count = 0;
	int charCount = 0;
	string newBody;
	bool spacer = false;
	while(body[count] != 0 && charCount < 100){
		if(isspace(body[count]) && spacer){
			newBody += " ";
			count ++;
			spacer = false;
		}else if(isspace(body[count])){
			count++;
			continue;
		}else{
			newBody += body[count];
			charCount++;
			count ++;
			spacer = true;
		}
	}
	return newBody;
}

string Description::getDescription() const{
	return pageDescription;
}
