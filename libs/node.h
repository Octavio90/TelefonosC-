#include <iostream>
#include <string>
#include "user.h"
#include "phone.h"
#include "bill.h"
#ifndef NODE_H
#define NODE_H


using namespace std;

template <class T>
class Node{
public:
	T        element;
	Node<T> *next;

	Node(User  &);
	Node(Phone &);
	Node(Bill  &);
	T* Get_Element();
};

template <class T>
Node<T>::Node(User &user){
	element.Set_Name(user.Get_Name());
	element.Set_Address(user.Get_Address());
	element.Set_Credit(user.Get_Credit());
	element.Set_IdUser(user.Get_IdUser());
	next    = NULL;	
} 

template <class T>
Node<T>::Node(Phone &phone){
	element.Set_IdPhone(phone.Get_IdPhone());
	element.Set_Company(phone.Get_Company());
	element.Set_Model(phone.Get_Model());
	element.Set_Weight(phone.Get_Weight());
	element.Set_Version(phone.Get_Version());
	element.Set_Camera_f(phone.Get_Camera_f());
	element.Set_Camera_t(phone.Get_Camera_t());
	element.Set_Mem_ram(phone.Get_Mem_ram());
	element.Set_Mem_rom(phone.Get_Mem_rom());
	element.Set_Price(phone.Get_Price());
	element.Set_Owner(phone.Get_Owner());
	element.Set_PhoneNumber(phone.Get_PhoneNumber());
	next    = NULL;	
} 

template <class T>
Node<T>::Node(Bill &bill){
	element.Set_User(bill.Get_User());
	element.Set_Phone(bill.Get_Phone());
	element.Set_Amount(bill.Get_Amount());
	element.Set_Date(bill.Get_Date());
	element.Set_IdBill(bill.Get_IdBill());
	next    = NULL;	
} 


template <class T>
T* Node<T>::Get_Element(){
	return &element;
}

#endif
