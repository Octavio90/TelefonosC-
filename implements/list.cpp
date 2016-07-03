#include <iostream>
#include <string>
#include "../libs/list.h"
#include "../libs/node.h"
#include "../libs/user.h"
using namespace std;

List::List(){
	first = NULL;
	last  = NULL;
}

bool List::Empty(){
	return (first==NULL);
}

void List::NewElement(){
	string name;
	string address;
	float  credit;
	int    number;
	cout << "Nombre: " ;
	cin  >> name;
	cout << "Direccion: ";
	cin  >> address;
	cout << "Credito: ";
	cin  >> credit;
	cout << "Numero de Telefonos: ";
	cin  >> number;		
	User user(name,address,credit,number); 
	Node *temp = new Node(user);
	if(Empty() == true){
		first = temp;
		last  = temp;
	}else{
		last->next = temp;
		last = temp;
	}
}

void List::PrintALL(){
	if(Empty() == true){
		cout << "Lista Vacia " << endl;
	}else{
		Node *aux = first;
		cout << "Los elementos son:" << endl;
		cout << "-----------------------------" << endl;
		cout << "-----------------------------" << endl; 
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
		Node *aux = first;
		cout << "-----------------------------" << endl;
		cout << "\tResultado Busqueda"<<endl;
		cout << "-----------------------------" << endl; 
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
		Node *aux = first;
		cout << "-----------------------------" << endl;
		cout << "\tResultado Busqueda"<<endl;
		cout << "-----------------------------" << endl; 
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
