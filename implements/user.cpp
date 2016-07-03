#include <iostream>
#include <string.h>
#define SIZE 1
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


/* Constructores y Destructores */
User::User(){}

User::User(string name){
	Set_Name(name);
	Set_Address("");	
		phoneNumber = new Phone[SIZE];
		if (phoneNumber == NULL){
		 	cout << "No se pudo crear espacio para los telefonos"
		 } 
	Set_Credit(0);
	Set_NumPhones(0);
}

User::User(string name,string address,float credit,int numPhones){
	Set_Name(name);
	Set_Address(address);
		phoneNumber = new Phone[SIZE];
		if (phoneNumber == NULL){
		 	cout << "No se pudo crear espacio para los telefonos"
		 } 
	Set_Credit(credit);
	Set_NumPhones(numPhones);
}

User::~User(){}

/* Getters y Setters */
string User::Get_Name(){return this->name;}
string User::Get_Address(){return this->address;}
Phone* User::Get_PhoneNumber(){return this->phoneNumber;}
float  User::Get_Credit(){return this->credit;}
int    User::Get_NumPhones(){return this->numPhones;}

void   User::Set_Name(string name){this->name=name;}
void   User::Set_Address(string address){this->address=address;}
void   User::Set_Credit(float credit){this->credit=credit;}
void   User::Set_NumPhones(int numPhones){this->numPhones=numPhones;}


/* Metodos */
void   User::Detail(){
	Phone *phone = Get_PhoneNumber();
	cout << "Nombre   : " << Get_Name() << endl;
	cout << "Telefonos: ";
		if(Get_NumPhones() != 0){
			for(int i=0;i<Get_NumPhones();i++){
				cout << "\t" << (phone+i)->GetPhoneNumber() << endl;
			}
		}
	cout << "Direccion: " << Get_Address() << endl;
	cout << "Credito  : " << Get_Credit() << endl;
	cout << "Cantidad de telefonos: " << Get_NumPhones() << endl;
}

bool   User::ValidNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 10){
		flag=true;
	}

	return flag;
}
