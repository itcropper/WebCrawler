

#include "StopWords.h"

using namespace std;

StopWords::StopWords(){

}
StopWords::~StopWords(){
	delete[] stopWords;
	stopWords = NULL;
}


bool StopWords::isEmpty(char * singleLine){
	for(unsigned int i = 0; i < strlen(singleLine); i++){
		if(!isspace(singleLine[i]))
			return false;
	}
	return true;
}

void StopWords::populateStopWordTree(string fileName){
	getNumberOfLines(fileName);
	fillArray(fileName);
}

void StopWords::getNumberOfLines(string fileName){
	numberOfWords = 0;

	ifstream file;
	try{
		file.open(fileName.c_str());
		char singleLine[500];
		memset(singleLine,0,500);
		while(file.getline(singleLine, 500)){
			numberOfWords++;
		}
		file.close();
	}catch(ifstream::failure e){
		cout << "Invalid file..." << endl;
	}
	stopWords = new string[numberOfWords];
}
void StopWords::fillArray(string fileName){

	ifstream file;
	try{
		file.open(fileName.c_str());
		char singleLine[200];
		memset(singleLine,0,200);
		for(int i = 0; i < numberOfWords; i++){
			file.getline(singleLine, 200);
			stopWords[i] = singleLine;
		}
		file.close();
	}catch(ifstream::failure e){
		cout << "Invalid file..." << endl;
	}
}

bool StopWords::contains(string word) {

	int lowerBound = 0;
	int upperBound = numberOfWords-1;
	int midPoint = 0;

	while(lowerBound <= upperBound) {
		midPoint = (upperBound + lowerBound)/2; //add the two & divide by two to get the midpoint

	if(stopWords[midPoint].compare(word) == 0)
		return true;
	else if(stopWords[midPoint].compare(word) < 0)
		lowerBound = midPoint + 1;
	else if(stopWords[midPoint].compare(word) > 0)
		upperBound = midPoint - 1;
	}
	return false;
}
