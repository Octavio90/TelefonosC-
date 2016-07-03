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

User::User(string name,string address,float credit,int num){
	Set_Name(name);
	Set_Address(address);
	Set_Credit(credit);
	Set_NumPhones(num);			
}

User::~User(){}

/* Getters y Setters */
void   User::Set_Name(string name){this->name=name;}
void   User::Set_Address(string address){this->address=address;}
void   User::Set_Credit(float credit){this->credit=credit;}
void   User::Set_NumPhones(int numPhones){this->numPhones=numPhones;}

string User::Get_Name(){return name;}
string User::Get_Address(){return address;}
float  User::Get_Credit(){return credit;}
int    User::Get_NumPhones(){return numPhones;}

/* Metodos */
void   User::Detail(){
	cout << "Nombre   : " << Get_Name() << endl;
	cout << "Direccion: " << Get_Address() << endl;
	cout << "Credito  : " << Get_Credit() << endl;
	cout << "Cantidad de Telefonicos: " << Get_NumPhones() << endl;
}


