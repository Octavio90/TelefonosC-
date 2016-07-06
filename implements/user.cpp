#include <iostream>
#include <string.h>
#include "../libs/user.h"


using namespace std;


/* Constructores y Destructores */
User::User(){}

User::User(string name,string address){
	Set_Name(name);
	Set_Address(address);	
	Set_Credit(0.0);
	Set_NumPhones(0);	
}

User::User(string name,string address,float credit,int id){
	Set_Name(name);
	Set_Address(address);
	Set_Credit(credit);
	Set_NumPhones(0);
	Set_IdUser(id);			
}

User::~User(){}

/* Getters y Setters */
void   User::Set_Name(string name){this->name=name;}
void   User::Set_Address(string address){this->address=address;}
void   User::Set_NumPhones(int numPhones){this->numPhones=numPhones;}
void   User::Set_IdUser(int id){this->idUser=id;}
void   User::Set_Credit(float credit){
	if(credit < 0){
		cout << endl;
		cout << "El credito NO puede ser negativo !!!. Asignando credito a $0.0";
		cout << endl;
		this->credit = 0;
	}else{
		this->credit=credit;
	}
}

string User::Get_Name(){return name;}
string User::Get_Address(){return address;}
float  User::Get_Credit(){return credit;}
int    User::Get_NumPhones(){return numPhones;}
int    User::Get_IdUser(){return idUser;}

/* Metodos */
void   User::Detail(){
	cout << "ID Usuario: " << Get_IdUser() << endl;
	cout << "Nombre    : " << Get_Name() << endl;
	cout << "Direccion : " << Get_Address() << endl;
	cout << "Credito   : $" << Get_Credit() << endl;
	cout << "Cantidad de Telefonicos: " << Get_NumPhones() << endl;
}


