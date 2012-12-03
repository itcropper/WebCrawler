
#include <iostream>
#include <string>
#include "LinkHistory.h"

using namespace std;

LinkHistory::LinkHistory(){
	lList = new LinkedList<string>();
}
LinkHistory::~LinkHistory(){
	delete lList;
	lList = NULL;
}


void LinkHistory::add(const string & url){
	lList->Insert(url, NULL);
}

bool LinkHistory::contains(string & incomingLink){
	return (lList->contains(incomingLink));
}


