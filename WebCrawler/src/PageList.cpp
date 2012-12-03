

#include <iostream>
#include <string>
#include "PageList.h"

/*
* this class serves as a set of instances of 'Occurence'
* created by the class WordIndex to keep track of how 
* often words occur on a given webpage
*/
using namespace std;
PageList::PageList(){
	pageList = new BST<Page>();
}

PageList::~PageList(){
	delete pageList;
	pageList = NULL;
}

/*
 * this method will be called by 'placeWord()' in WordIndex.
 * after certain validations have been made, this method is 
 * called which creates a new instance of Page, passing
 * in 'word' and 'page' and adds it to the set
 */
void PageList::addNewPage(string url, Description desc){
//	cout << "getting here" << endl;
	Page page = Page(url, desc);

	pageList->Insert(page);
//	cout <<  "................. " << endl;
}

bool PageList::IsEmpty(){
	return pageList->IsEmpty();
}

void PageList::InfixToXML(std::ofstream& outfile){
	if(!IsEmpty()){
		RecurseToXML(outfile, pageList->GetRoot());
	}else
		return;
}
void PageList::RecurseToXML(std::ofstream& outfile, BSTNode<Page> * node){

	if(node == NULL)
		return;
	node->GetValue().pageToXML(outfile);
	RecurseToXML(outfile,node->GetLeft());
	RecurseToXML(outfile,node->GetRight());

}
