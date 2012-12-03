
#include "StringUtil.h"
#include "URL_Resolver.h"

URL_Resolver::URL_Resolver(){
	schemeIsWeb = false;
	noPath = false;
	pathCount = 0;
	backCount = 0;
}
URL_Resolver::~URL_Resolver(){

}

void URL_Resolver::getScheme(string base){
	SCHEME = string();

	for(unsigned int i = 0; i < FileSize; i++){
		SCHEME += base[i];

		if(SCHEME == WEB_PREFIX || SCHEME == FILE_PREFIX){
			
			if(SCHEME == WEB_PREFIX)
				schemeIsWeb = true;
			return;
		}else
			continue;
	}
}
void URL_Resolver::getNET_LOC(string base){
	
	int count = SCHEME.size();
	
	while(base[count] != '/' && base[count] != 0){
		NET_LOC += base[count];
		count++;
	}
	

	if(base[count] == '/')
		NET_LOC += base[count];
}

void URL_Resolver::parsePath(string base){
	
	int count = SCHEME.size() + NET_LOC.size();
	string localPath = base.substr(count);
	size_t found = localPath.find_first_of("/");

	while (found!=string::npos){
		

		 PATH[pathCount] = localPath.substr(0, found + 1);
		 //cout  << "PATH[" << pathCount << "] : " << PATH[pathCount] << endl;

		 localPath = localPath.substr(found + 1);
		 pathCount++;
		 found = localPath.find_first_of("/");


	}
	int currentDirectoryChar = 0;

	while(localPath[currentDirectoryChar] != 0 && 
			localPath[currentDirectoryChar] != ' '){
		PATH[pathCount] += localPath[currentDirectoryChar];
		currentDirectoryChar++;
	}
	//cout  << "PATH[" << pathCount << "] : " << PATH[pathCount] << endl;
}

void URL_Resolver::parseBase(string base){
	getScheme(base);
	if(schemeIsWeb){
		getNET_LOC(base);
	}
	parsePath(base);
    StringUtil::ToLower(SCHEME);
    StringUtil::ToLower(NET_LOC);

}
bool URL_Resolver::isStartOfRelPath(char symbol){
	if(symbol == '~' || isalnum(symbol))
		return true;
	else
		return false;
}

void URL_Resolver::parseRelative(string relative){
	backCount = 1;
	if(relative[0] == '#'){
		backCount = 0;
		RELATIVE = relative.substr(1);
	}else if(relative[0] == '?'){
		combineQueries();
		
	}else if(isStartOfRelPath(relative[0])){
		RELATIVE = relative;
		backCount = 1;
	}else if(relative[0] == '/'){
		noPath = true;
        string newRel = relative.substr(1);
		RELATIVE = newRel;
//        RELATIVE.append()
	}else{
		while(StringUtil::IsPrefix(relative, "../") || StringUtil::IsPrefix(relative, "./")){
			if(StringUtil::IsPrefix(relative, "../")){
				relative = relative.substr(3);
				backCount++;
			}else if(StringUtil::IsPrefix(relative, "./")){
				relative = relative.substr(2);
//				//cout  << "\nrelative after substr " << relative << "\n" << endl;
			}else
				break;
		}
		RELATIVE = relative;
	}
}
void URL_Resolver::combineQueries(){
	size_t found;
	found = BASEURL.find('?');
	RESOLVED += BASEURL.substr(0, found);
	RESOLVED += RELATIVE.substr(1);
	
}
void URL_Resolver::joinBaseAndRel(){
	StringUtil::ToLower(SCHEME);
	RESOLVED += SCHEME;
	StringUtil::ToLower(NET_LOC);
	RESOLVED += NET_LOC;
	//path is case SENSITIVE, so ToLower is not called
	if(!noPath){
		for(int i = 0; i <= pathCount-backCount; i++){
			RESOLVED += PATH[i];
//			//cout  << "new Resolved path " << RESOLVED << endl;
		}

	}
	RESOLVED += RELATIVE;
}
bool URL_Resolver::isRelative(string RELATIVE){
	string tempRel = RELATIVE;
	StringUtil::ToLower(tempRel);
	bool webYes = StringUtil::IsPrefix(tempRel, "http://");
	bool fileYes = StringUtil::IsPrefix(tempRel, "file:///");
	if(webYes || fileYes){
//        getScheme(RELATIVE);
//      getNET_LOC(RELATIVE);
//        parsePath(RELATIVE);
//        StringUtil::ToLower(SCHEME);
//        StringUtil::ToLower(NET_LOC);
//        RESOLVED += SCHEME;
//        RESOLVED += NET_LOC;
//        for(int i = 0; i <= pathCount; i++){
//            RESOLVED += PATH[i];
//        }

		return false;
	}else
		return true;
}

string URL_Resolver::resolveURLs(string base, string relative){
	this->BASEURL = base;
	this->RELATIVE = relative;
//	cout  << "\nbase = " << base << endl;
//	cout  << "rel =  " << relative  << endl;
	if(isRelative(RELATIVE)){
		parseBase(base);
		parseRelative(RELATIVE);
		joinBaseAndRel();
		return RESOLVED;
	}else{
		return RESOLVED;
	}
	
}

bool URL_Resolver::Test(ostream & os){
	bool success = true;

	/* string URLs to test with */
	string url1 = "http://www.cnn.com/world/news/events/today.html";
	string url2 = "./archives/news/word.html";
	string url3 = "http://www.cnn.com/world/news/events/archives/news/word.html";
	
	string url4 = "http://www.cnn.com/world/news/events/today.html";
	string url5 = "/archives/news/word.html";
	string url6 = "http://www.cnn.com/archives/news/word.html";


	resolveURLs(url1, url2);

	if(RESOLVED == url3){
		success = true;
		cout << "Passed test 1" << endl;
	}else{
		success = false;
		cout << "Failed test 1" << endl;
	}
		
	resolveURLs(url4, url5);
	
	if(RESOLVED == url6){
		success = true;
		cout << "Passed test 2" << endl;
	}else{
		success = false;
		cout << "Failed test 2" << endl;
		cout << "printed\n" << RESOLVED << endl;
		cout << "expected: \nhttp://www.cnn.com/archives/news/word.html" << endl;
	}

	return success;
}

