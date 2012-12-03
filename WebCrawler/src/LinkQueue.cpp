#include <iostream>
#include <string>
#include "LinkQueue.h"

using namespace std;


LinkQueue::LinkQueue(){
	que = new LinkedList<string>();

}
LinkQueue::~LinkQueue(){
	delete que;
	que = NULL;

}

string LinkQueue::getNext(){
	LLNode<string> * tempNode = que->GetLast();
	string tempGet(tempNode->GetValue());
	que->Remove(tempNode);
	return tempGet;
	
}

void LinkQueue::Insert(const string & url){
	que->Insert(url, NULL);
}

bool LinkQueue::IsEmpty(){
	return (que->GetSize() == 0);
}


