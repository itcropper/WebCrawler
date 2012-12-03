
#include "Page.h"

using namespace std;

Page::Page(){
	
}

Page::Page(string URL, Description desc){
	this->URL = URL;
	this->DESC = desc;
}

Page::~Page(){
}

string & Page::getURL(){
  return URL;
}

string Page::getDescription(){
	return DESC.getDescription();
}


int Page::compare(Page & other){
	return URL.compare(other.getURL());
}

void Page::pageToXML(std::ofstream& outfile){
	string desc = this->getDescription();
	StringUtil::EncodeToXml(desc);
	outfile << "\t\t<page>" << endl;
		outfile << "\t\t\t<url>"<< endl;
			outfile << "\t\t\t\t" << URL << endl;
			outfile << "\t\t\t</url>"<< endl;
	outfile << "\t\t\t<description>" << endl;
			outfile << "\t\t\t\t" << desc << endl;
		outfile << "\t\t\t</description>" << endl;
	outfile << "\t\t</page>" << endl;
}

