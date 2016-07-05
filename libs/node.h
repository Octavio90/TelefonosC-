#include <iostream>
#include <string>
#include "user.h"
#include "phone.h"
#ifndef NODE_H
#define NODE_H


using namespace std;

template <class T>
class Node{
public:
	T        element;
	Node<T> *next;

	Node(T &);
	T* Get_Element();
};

template <class T>
Node<T>::Node(T &t){
	element.Set_Name(t.Get_Name());
	element.Set_Address(t.Get_Address());
	element.Set_Credit(t.Get_Credit());
	element.Set_NumPhones(t.Get_NumPhones());
	element.Set_IdUser(t.Get_IdUser());
	next    = NULL;	
} 


template <class T>
T* Node<T>::Get_Element(){
	return &element;
}

#endif
