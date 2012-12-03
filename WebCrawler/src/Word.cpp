

#include "Word.h"

Word::Word(){

}

Word::Word(string val, string url){
	this->Value = val;
	Occurence occ(url);
	occurences.Insert(occ);
}

Word::~Word(){
	occurences.Clear();
}

void Word::addNewOccurrenc(string url){
	Occurence occ(url);
	BSTNode<Occurence> * nodeOcc = NULL;
	nodeOcc = occurences.Find(occ);
	if(nodeOcc != NULL){
		nodeOcc->GetValue().addCount();
	}else{
		Occurence occ(url);
		occurences.Insert(occ);
	}
}
Occurence* Word::FindURL(string url){
	return FindRecURL(url, *occurences.GetRoot());
}
Occurence * Word::FindRecURL(string v, BSTNode<Occurence> & node){

	if(&node == NULL){

		return NULL;
	}
	else if(v < node.GetValue().getURL()) {

		return FindRecURL(v, *node.GetLeft());
	}
	else if(v > node.GetValue().getURL()){
		return FindRecURL(v, *node.GetRight());
	}
	else if(v == node.GetValue().getURL()){

		return &node.GetValue();
	}
	return NULL;
}


string Word::getValue(){
	return Value;
}

int Word::compare(Word & other){
	return Value.compare(other.getValue());
}

void Word::wordToXML(std::ofstream& outfile){
	string val = this->getValue();
	StringUtil::EncodeToXml(val);
		outfile<< "\t\t<word>" << endl;
		outfile<<"\t\t\t<value>"<< val <<"</value>"<< endl;
			occurenceToXML(outfile, occurences.GetRoot());
	outfile<< "\t\t</word>" << endl;
}

void Word::occurenceToXML(std::ofstream& outfile, BSTNode<Occurence> * node){
	if(node == NULL)
			return;

	occurenceToXML(outfile,node->GetLeft());
		node->GetValue().OccurenceToXML(outfile);
	occurenceToXML(outfile,node->GetRight());
}


