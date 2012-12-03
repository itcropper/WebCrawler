

#include "WordIndex.h"
#include <iostream>




WordIndex::WordIndex(){
	wordIndex = new BST<Word>();
	existingWords = new BST<string>();
}


WordIndex::~WordIndex(){
	delete wordIndex;
	wordIndex = NULL;

//	delete stopwords;
	stopwords = NULL;

	delete existingWords;
	existingWords = NULL;
}

void WordIndex::setStopWords(StopWords * stopWords){
	this->stopwords = stopWords;
}

bool WordIndex::isInvalidWord(string word){
	if(isdigit(word[0]))
		return true;
	else if(isAStopWord(word))
		return true;
	else if(word[0] == '-' || word[0] == '_')
		return true;
	else if(isspace(word[0]))
		return true;
	else return false;
}

bool WordIndex::isAStopWord(string word){
	return stopwords->contains(word);
}

string WordIndex::removeSpace(string word){
	int place = 0;
	string spaceLessWord = "";
	size_t wordSize = word.length();
	while(place < wordSize){
		if(isalnum(word[place]) || word[place] == '-' || word[place] == '_'){
			spaceLessWord += word[place];
			place++;
		}else{
			place++;
		}
	}
	return spaceLessWord;
}

void WordIndex::InsertExisting(Word * existingWord, string URL) {
	if(existingWord->FindURL(URL) != NULL)
		existingWord->FindURL(URL)->addCount();
	else
		existingWord->addNewOccurrenc(URL);
}

void WordIndex::placeWord(string Text, string URL){
	this;
	  string delim = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_0123456789";
//	  size_t first = 0;
	  size_t found = 0;

	  while (found!=string::npos){
		found = 0;
		found = Text.find_first_not_of(delim);

		string textWord = Text.substr(0, found);
		Text = Text.substr(found + 1);

		if (textWord.size() == 0) {
			continue;
		}

		string tempWord(textWord);
		StringUtil::ToLower(tempWord);

		if(isInvalidWord(tempWord)){
			continue;
		}
//		cout << tempWord << endl;
		Word tmp(tempWord, URL);
		
		BSTNode<Word> * wordNode = NULL;
		wordNode = wordIndex->Find(tmp);

		if(wordNode != NULL){
//			cout <<"word value of node is: " <<  wordNode->GetValue().getValue() << endl;
			wordNode->GetValue().addNewOccurrenc(URL);
//			cout << wordNode->GetValue().getValue() << endl;
		}else{
//			cout << tempWord << endl;
			wordIndex->Insert(tmp);

		}
	  }
}

void WordIndex::IndexToXML(std::ofstream& outfile){
	RecurseToXML(outfile, wordIndex->GetRoot());
}

void WordIndex::RecurseToXML(std::ofstream& outfile, BSTNode<Word> * node){

	if(node == NULL)
		return;
	RecurseToXML(outfile,node->GetLeft());
		node->GetValue().wordToXML(outfile);
	RecurseToXML(outfile,node->GetRight());

}

