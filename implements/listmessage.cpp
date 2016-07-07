#include <iostream>
#include <string.h>
#include "../libs/listmessage.h"


using namespace std;

/************ Node ***************/

NodeMessage::NodeMessage(Message &message){
	element.Set_Flag(message.Get_Flag());
	element.Set_Text(message.Get_Text());
 	element.Set_Date(message.Get_Date());
 	element.Set_Sender(message.Get_Sender());
 	element.Set_NumSender(message.Get_NumSender());
}

Message* NodeMessage::Get_Element(){return &element;}

/************ List ***************/

ListMessage::ListMessage(){
	first = NULL;
	last  = NULL;
	numElements = 0;
}

bool ListMessage::Empty(){
	return (first==NULL);
}

int ListMessage::Get_NumElements(){return numElements;}


void ListMessage::NewElement(Message &element){
	NodeMessage *temp = new NodeMessage(element);
	if(Empty() == true){
		first = temp;
		last  = temp;
	}else{
		last->next = temp;
		last = temp;
	}
	numElements ++;
}

void ListMessage::PrintAll(){
	if(Empty() == true){
		cout << "Lista Vacia " << endl;
	}else{
		NodeMessage *aux = first;
		while(aux != NULL){
			aux->Get_Element()->Detail();
			cout << "-----------------------------" << endl;
			aux = aux->next; 
		}
	}
}