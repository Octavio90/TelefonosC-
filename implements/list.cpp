#include <iostream>
#include <string>
#include "../libs/list.h"
#include "../libs/node.h"
#include "../libs/user.h"
using namespace std;

List::List(){
	first = NULL;
	last  = NULL;
	numElements = 0;
}

bool List::Empty(){
	return (first==NULL);
}

int List::Get_NumElements(){return numElements;}

void List::NewElement(User &user){
	Node<User> *temp = new Node<User>(user);
	if(Empty() == true){
		first = temp;
		last  = temp;
	}else{
		last->next = temp;
		last = temp;
	}
	numElements ++;
}

void List::PrintALL(){
	if(Empty() == true){
		cout << "Lista Vacia " << endl;
	}else{
		Node<User> *aux = first;
		while(aux != NULL){
			aux->Get_Element()->Detail();
			cout << "-----------------------------" << endl;
			aux = aux->next; 
		}
		cout << "-----------------------------" << endl;
	}
}

void List::FindByName(string name){

	if(Empty() == true){
		cout << "No se encontro ninguna coincidencia !!! " << endl;
	}else{
		Node<User> *aux = first; 
		while(aux != NULL){
			if(aux->Get_Element()->Get_Name() == name){
				aux->Get_Element()->Detail();
				cout << "-----------------------------" << endl;
			}
			aux = aux->next; 
		}
		cout << "-----------------------------" << endl;
	}
}

void List::FindByNumPhones(int number){

	if(Empty() == true){
		cout << "No se encontro ninguna coincidencia !!! " << endl;
	}else{
		Node<User> *aux = first;
		cout << endl; 
		while(aux != NULL){
			if(aux->Get_Element()->Get_NumPhones() == number){
				aux->Get_Element()->Detail();
				cout << "-----------------------------" << endl;
			}
			aux = aux->next; 
		}
		cout << "-----------------------------" << endl;
	}
}

User* List::FindByID(int id){
	User *temp = NULL;
	if(Empty() == true){
		cout << "Lista Vacia !!! " << endl;
	}else{
		Node<User> *aux = first;
		cout << endl; 
		while(aux != NULL){
			if(aux->Get_Element()->Get_IdUser() == id){
				return aux->Get_Element();
			}
			aux = aux->next; 
		}
	}
	return temp;
}

