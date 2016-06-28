#include <iostream>
#include <string.h>
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
User::User(){}

User::User(string name ,const char* number){
	Set_Name(name);
	Set_Address("");
	phoneNumber = NULL;	
	Set_PhoneNumber(number);
	Set_Credit(1000);
	Set_NumPhones(0);
}

User::User(string name,string address,const char* number,float credit,int numPhones){
	Set_Name(name);
	Set_Address(address);
	phoneNumber = NULL;	
	Set_PhoneNumber(number);
	Set_Credit(credit);
	Set_NumPhones(numPhones);
}

User::~User(){
	delete[] phoneNumber;
}

/* Getters y Setters */
string User::Get_Name(){return this->name;}
string User::Get_Address(){return this->address;}
char*  User::Get_PhoneNumber(){return this->phoneNumber;}
float  User::Get_Credit(){return this->credit;}
int    User::Get_NumPhones(){return this->numPhones;}

void   User::Set_Name(string name){this->name=name;}
void   User::Set_Address(string address){this->address=address;}
void   User::Set_Credit(float credit){this->credit=credit;}
void   User::Set_NumPhones(int numPhones){this->numPhones=numPhones;}
void   User::Set_PhoneNumber(const char* number){

	char cad[50];
	while(validNumber(number) != true){
		cout << "Numero Invalido !!!" << endl;
		cout << "Ingrese de nuevo el numero telefonico: ";
		cin  >> cad;
		number = cad;
	}
	if(phoneNumber != NULL){
		delete[] phoneNumber;
	}
	phoneNumber = new char[strlen(number)+1];
	strcpy(phoneNumber,number);	
}

/* Metodos */
void   User::Detail(){
	cout << endl;
	cout << "Nombre   : " << Get_Name() << endl;
	cout << "Telefono : " << Get_PhoneNumber() << endl;
	cout << "Direccion: " << Get_Address() << endl;
	cout << "Credito  : " << Get_Credit() << endl;
	cout << "Cantidad de telefonos: " << Get_NumPhones() << endl;
}

bool   User::validNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 8){
		flag=true;
	}

	return flag;
}
