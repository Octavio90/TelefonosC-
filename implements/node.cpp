#include <iostream>
#include <string>
#include "../libs/node.h"
#include "../libs/user.h"
#include "../libs/phone.h"


using namespace std;

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
