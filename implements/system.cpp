#include <iostream>
#include <string.h>
#define  SIZE 1
#include "../libs/system.h"
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
System::System(){
	Set_NumUsers(0);
	users = NULL;
	users = new User[SIZE];
		if(users == NULL){
			cout << "No se pudo reservar espacio para guardar usuarios. " << endl;
		}
}

System::~System(){
	if(users != NULL){
		/*for(int i=0;i<Get_NumUsers();i++){
		    delete (users+i);
		}*/
		delete [] users;
	}
}

/* Getters y Setters */

void System::Set_NumUsers(int numUsers){this->numUsers=numUsers;}

int  System::Get_NumUsers(){return numUsers;}


/* Metodos */
void  System::PrintBill(){}

void  System::PrintAllUsers(){
	User *user = users;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;

	for(int i=0;i<Get_NumUsers();i++){
		(user+i)->Detail();
		cout << "-------------------------------------" << endl;
	}
	cout << "-------------------------------------" << endl << endl;
}

void  System::PrintUser(string name){
	User* user = FindUser(name);
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;
	if(user != NULL)
		user->Detail();
	else
		cout << "Usuario NO encontrado." << endl; 
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl << endl;
}

void  System::PrintUser(char* phone){
	User* user = FindUser(phone);
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;
	if(user != NULL)
		user->Detail();
	else
		cout << "Usuario NO encontrado." << endl; 
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl << endl; 
}

bool  System::NewUser(){
	
	float  credit;
	int    itemp;
	char   op;
	char   number[50];
	string stemp = "";
	bool   flag  = false;
	int    idx   = Get_NumUsers();

	
	while(stemp == ""){
		cout << endl << "Nombre de la Persona: ";
		cin  >> stemp;
		if(stemp == ""){
			cout << "El nombre debe tener almenos un caracter !!!" << endl;
		}
	}
	cout << "Numero Telefonico: ";
	cin  >> number;
	User user(stemp,number);

	cout << "Quieres ingresar los demas datos? (y/n):";
	cin  >> op;

	if(op == 'y' || op == 'Y'){
		stemp = "";
		cout << "Direccion: ";
		cin  >> stemp;
		user.Set_Address(stemp);	

		cout << "Credito: ";
		cin  >> credit;
		user.Set_Credit(credit);

		cout << "Cantidad de Telefonos: ";
		cin  >> itemp;
		user.Set_NumPhones(itemp);		
	}
	
	if(idx < SIZE){
		users[idx] = user;
		Set_NumUsers(idx+1);
		flag=true;	
	}
	else{
		User *users2 = new User[Get_NumUsers()+SIZE];
		if(users2 == NULL){
			cout << "Memoria insuficiente !!! " << endl;
		}
		else{
			memcpy( users2, users, Get_NumUsers()*sizeof(User));
			//delete[] users;
			users = users2;
		}
		users[idx] = user;
		Set_NumUsers(idx+1);
		flag=true;
	}
	
	return flag;
}


bool  System::BuyPhone(){}

User* System::FindUser(string name){
	User *user = NULL;
	for(int i=0;i<Get_NumUsers();i++){
		user = (users+i);
		if(user->Get_Name() == name){
			return user;
		}
		else{
			user = NULL;
		}
	}
	return user;
}

User* System::FindUser(char* phone){
	/* Pendiente */
	User *user = NULL;
	for(int i=0;i<Get_NumUsers();i++){
		user = (users+i);
		if(user->Get_PhoneNumber() == phone){
			return user;
		}
		else{
			user = NULL;
		}
	}
	return user;	
}

User* System::FindUser(string name,char* phone){}