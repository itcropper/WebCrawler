
#include <iostream>
#include "PageDownloader.h"

	/* 
	 * accepts a string, URL, and calls 'downloadPage' and inputs 
	 * the peices of the page into 'page' of type Page
	 */
PageDownloader::PageDownloader(){

	_seen_first_header = false;
	scopeIsAlreadySet = false;
	inBody = false;
	pagelist = new PageList();
}

PageDownloader::~PageDownloader(){
	delete pagelist;
	pagelist = NULL;
	allPageText.clear();
	titleString.clear();
	headingString.clear();
	bodyStrings.clear();
}

bool PageDownloader::isWorthlessTag(HTMLToken & token){
	if(token.GetType() == COMMENT)
		return true;
	else if(token.GetType() == TAG_END){
		string bodyClose = token.GetValue();
		StringUtil::ToLower(bodyClose);
		if(bodyClose == "body")
			inBody = false;
		return true;
	}
	else return false;
}

/*
 * We are looking for the first header, not necessarily <h1>.
 * This method checks to see if we have found the first header, then
 * flips the _seen_first_header boolean to signify that the first
 * header has already been found, for other methods
 */
bool PageDownloader::isFirstHeader(string potentialFirstHeader){
	StringUtil::ToLower(potentialFirstHeader);
	if(potentialFirstHeader[0] == 'h' && isdigit(potentialFirstHeader[1]) && !_seen_first_header){
		_seen_first_header = true;
		return true;
	}
	else
		return false;
}
/*
 * checks to see if the incoming link is an appropriate html file
 */
bool PageDownloader::isInHTMLFormat(string url){
	string validFileTypes[10] = {".html", ".htm", ".shtml",
			".cgi", ".jsp", ".asp", ".aspx", ".php", ".pl", ".cfm"};
	if(StringUtil::IsSuffix(url, "/"))
		return true;
	else{
		for(int i = 0; i < 10; i++){
			if(StringUtil::IsSuffix(url, validFileTypes[i])){
				return true;
			}
		}
        for(int i = 0; i < 10; i++){
            if(url.find(validFileTypes[i]) != string::npos)
               return true;
        }
		size_t found = url.find_last_of("/");
		string str = url.substr(found+1);
		found = str.find(".");
		if(found!=string::npos){
			return false;
		}else
			return true;
	}
}

bool PageDownloader::isInScope(string url){
	return (StringUtil::IsPrefix(url, scopeURL));
}

void PageDownloader::setScope(string url){
	size_t found;
	found = url.find_last_of("/");
	scopeURL = url.substr(0,found + 1);
	scopeIsAlreadySet = true;
}
void PageDownloader::getATag(HTMLToken curTok, LinkQueue * lq){
	string url = curTok.GetAttribute("href");
	if(isInHTMLFormat(url)){

		URL_Resolver uRes;
		string tempURL = URL;
		string newLink = uRes.resolveURLs(tempURL, url);

		if(isInScope(newLink)){
			lq->Insert(newLink);
			newLink = "";
		}
		else{
			return;
		}
		tempURL = "";
	}
	lq = NULL;
}

void PageDownloader::processStartTags(HTMLToken curTok, LinkQueue * lq){
	string lowerCaseToken = curTok.GetValue();
	StringUtil::ToLower(lowerCaseToken);

	if(lowerCaseToken == "body")
		inBody = true;

	if(lowerCaseToken == "title"){
		while(curTok.GetType() != TEXT){
			if(curTok.AttributeExists("href")){
				getATag(curTok, lq);
			}
			curTok = hTokZ->GetNextToken();
		}
		titleString = curTok.GetValue();
		allPageText += titleString;

	}else if(inBody){
			if(curTok.AttributeExists("href")){
				getATag(curTok, lq);

		}else if(isFirstHeader(curTok.GetValue())){
			while(curTok.GetType() != TEXT){
				if(curTok.AttributeExists("href")){
					getATag(curTok, lq);
				}
				curTok = hTokZ->GetNextToken();
			}
			headingString = curTok.GetValue();
			allPageText += headingString;
		}
	}
	lq = NULL;
}

void PageDownloader::grabText(string remainsOfToken){
	  size_t found;
	  found=remainsOfToken.find_first_of("\t\v\r\n\f");
	  while (found!=string::npos){
		remainsOfToken[found]= ' ';
	    found=remainsOfToken.find_first_of("\t\v\r\n\f",found+1);
	  }
	  allPageText += " ";
	  allPageText += remainsOfToken;
}
/*
 * opens page of the given URL, and tokenizes it
 */
void PageDownloader::downloadPage(string & url, LinkQueue * lq){

	//reset all values to original values
	_seen_first_header = false;
	titleString = "";
	headingString = "";
	allPageText = "";

	this->URL = url;

	InputStream = new URLInputStream(url);
	hTokZ = new HTMLTokenizer(InputStream);
	InputStream->Close();

	bool inHTML = false;

	 while(hTokZ->HasNextToken()){

		 HTMLToken curTok = hTokZ->GetNextToken();
         
		 if(!inHTML){
			 string htmlTag = curTok.GetValue();
			 StringUtil::ToLower(htmlTag);
			 if(htmlTag == "title" || htmlTag == "body" || htmlTag == "html" ){
				 inHTML = true;
			 }else{
				 continue;
			 }
		 }
		 if(isWorthlessTag(curTok)){ //comment or TAG_END
			 continue;

		 }else if(curTok.GetType() == TAG_START){
			processStartTags(curTok, lq);

		 }else if(curTok.GetType() == TEXT && inBody)
			 grabText(curTok.GetValue());
	 }
	delete hTokZ;
	hTokZ = NULL;
	delete InputStream;
	InputStream = NULL;
	createPageWithNewDescription();
}
void PageDownloader::createPageWithNewDescription(){

	Desc = new Description(titleString, headingString, allPageText);
	pagelist->addNewPage(URL, *Desc);

	delete Desc;
	Desc = NULL;
}
string PageDownloader::getWords(){
	return allPageText;
}

PageList * PageDownloader::getPages(){
	return pagelist;
}
