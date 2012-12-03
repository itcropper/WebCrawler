
#include "Occurence.h"
#include "StringUtil.h"

Occurence::Occurence(string url) : count(1){
//	cout << "Occurence URL = " << url << endl;
	this->URL = url;
}
Occurence::~Occurence(){
}

string Occurence::getURL(){
	return URL;
}

int Occurence::getCount(){
	return count;
}

void Occurence::addCount(){
	count++;
}

int Occurence::compare(Occurence & other){
	return URL.compare(other.getURL());
}

void Occurence::OccurenceToXML(std::ofstream& outfile){
	outfile<<"\t\t\t<occurrence>" << endl;
		outfile<< "\t\t\t\t<url>" << endl;
				outfile<<"\t\t\t\t\t" <<  getURL() << endl;
			outfile<< "\t\t\t\t</url>" << endl;
		outfile<< "\t\t\t\t<count>"<< getCount() << "</count>" << endl;
	outfile<<"\t\t\t</occurrence>" << endl;
}
