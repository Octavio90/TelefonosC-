#include <iostream>
#include <string>
#include "../libs/node.h"
#include "../libs/user.h"


using namespace std;

//template <class T>
//T Node<T>::Get_Element(){
Node::Node(User &user){
	element.Set_Name(user.Get_Name());
	element.Set_Address(user.Get_Address());
	element.Set_Credit(user.Get_Credit());
	element.Set_NumPhones(user.Get_NumPhones());
	next    = NULL;	
} 

//template <class T>
//Tabla<T>::Tabla(const T *){
User* Node::Get_Element(){
	return &element;
}
