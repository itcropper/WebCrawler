
#include "Write.h"


Write::Write(string fileName){
	outfile.open(fileName.c_str());
}

Write::~Write(){

	startingURL = NULL;
	pages = NULL;
	Index = NULL;
	outfile.close();
}

void Write::setPages(PageList * incomingPages){
	this->pages = incomingPages;
}

void Write::setIndex(WordIndex * incomingIndex){
	this->Index = incomingIndex;
}

void Write::writeOutput(string start){
	outfile << "<website>" << endl;
	writeStart(start);
	writePages();
	writeIndex();
	outfile << "</website>" << endl;
}

void Write::writeStart(string start){
	outfile << "\t<start-url>" << endl;

		outfile <<"\t\t" << start << endl;

	outfile << "\t</start-url>" << endl;
}

void Write::writePages(){
	outfile <<"\t<pages>" << endl;

		pages->InfixToXML(outfile);

	outfile << "\t</pages>" << endl;
}

void Write::writeIndex(){
	outfile << "\t<index>" << endl;

		Index->IndexToXML(outfile);

	outfile << "\t</index>" << endl;
}





