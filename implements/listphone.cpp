#include <iostream>
#include <string.h>
#include "../libs/listphone.h"


using namespace std;

/************ Node ***************/

NodePhone::NodePhone(string *cad){element = cad;}

string* NodePhone::Get_Element(){return element;}

/************ List ***************/

ListPhone::ListPhone(){
	first = NULL;
	last  = NULL;
	numElements = 0;
}

bool ListPhone::Empty(){
	return (first==NULL);
}

int ListPhone::Get_NumElements(){return numElements;}


void ListPhone::NewElement(string *element){
	NodePhone *temp = new NodePhone(element);
	if(Empty() == true){
		first = temp;
		last  = temp;
	}else{
		last->next = temp;
		last = temp;
	}
	numElements ++;
}

void ListPhone::PrintAll(){
	if(Empty() == true){
		cout << "Lista Vacia " << endl;
	}else{
		NodePhone *aux = first;
		while(aux != NULL){
			cout << "\t    " << *(aux->Get_Element()) << endl;
			aux = aux->next; 
		}
	}
}
