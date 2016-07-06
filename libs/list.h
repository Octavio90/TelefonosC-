#include <iostream>
#include "node.h"
#ifndef LIST_H
#define LIST_H


using namespace std;

template <class T>
class List{
private:
	Node <T> *first;
	Node <T> *last;
	int   numElements;
public:
	List();
	int    Get_NumElements();
	bool   Empty();
	void   NewElement(T &);
	void   PrintALL();
	User*  FindByID(int);
	void   FindByName(string);
	void   FindByNumPhones(int);
	
	void   FindByModel(string);
	void   FindByPrice(float);
	Phone* FindByPhoneNumber(char *);
};

template <class T>
List<T>::List(){
	first = NULL;
	last  = NULL;
	numElements = 0;
}

template <class T>
bool List<T>::Empty(){
	return (first==NULL);
}

template <class T>
int List<T>::Get_NumElements(){return numElements;}


template <class T>
void List<T>::NewElement(T &element){
	Node<T> *temp = new Node<T>(element);
	if(Empty() == true){
		first = temp;
		last  = temp;
	}else{
		last->next = temp;
		last = temp;
	}
	numElements ++;
}

template <class T>
void List<T>::PrintALL(){
	if(Empty() == true){
		cout << "Lista Vacia " << endl;
	}else{
		Node<T> *aux = first;
		while(aux != NULL){
			aux->Get_Element()->Detail();
			cout << "-----------------------------" << endl;
			aux = aux->next; 
		}
		cout << "-----------------------------" << endl;
	}
}

template <class T>
void List<T>::FindByName(string name){

	if(Empty() == true){
		cout << "No se encontro ninguna coincidencia !!! " << endl;
	}else{
		Node<T> *aux = first; 
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

template <class T>
void List<T>::FindByNumPhones(int number){

	if(Empty() == true){
		cout << "No se encontro ninguna coincidencia !!! " << endl;
	}else{
		Node<T> *aux = first;
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

template <class T>
User* List<T>::FindByID(int id){
	User *temp = NULL;
	if(Empty() == true){
		cout << "Lista Vacia !!! " << endl;
	}else{
		Node<T> *aux = first;
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

/* Neto */

template <class T>
void List<T>::FindByModel(string model){
	if(Empty()==true){
		cout<<"no se encontro conincidencia con el nombre de :"<< model<<endl;
	}else{
		Node<T> *aux=first;
		while(aux !=NULL){
			if(aux->Get_Element()->Get_Model()==model){
				aux->Get_Element()->Detail();
				cout<<"------------------------------"<<endl;
			}
			aux=aux->next;
		}
		cout<<"-------------------------"<<endl;
	}
}

template<class T>
void List<T>::FindByPrice(float price){
	if(Empty()==true){
		cout<<"No se encontro ningun telefono con ese precio "<<endl;
	}else{
		Node<T> *aux=first;
		cout<<endl;
		while(aux!=NULL){
			if(aux->Get_Element()->Get_Price()==price){
				aux->Get_Element()->Detail();
				cout<<"---------------------"<<endl;
			}
			aux=aux->next;
		}
		cout<<"-----------------------"<<endl;
	}
}

template<class T>
Phone* List<T>::FindByPhoneNumber(char* phoneNumber){
	Phone *temp=NULL;
	if(Empty()==true){
		cout<<"Lista de numeros Vacia!!! "<<endl;
	}else{
		Node<T> *aux=first;
		cout<<endl;
		while(aux != NULL){
			if(aux->Get_Element()->Get_PhoneNumber()==phoneNumber){
				return aux->Get_Element();
			}
			aux=aux->next;
		}
	}
	return temp;
}

#endif
