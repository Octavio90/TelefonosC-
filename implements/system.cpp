#include <iostream>
#include <string.h>
#define  SIZE 1
#include "../libs/system.h"
#include "../libs/user.h"
#include "../libs/phone.h"

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
	cout<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"-------------------------------------"<<endl;

	for(int i=0;i<Get_NumUsers();i++){
		(user+i)->Detail();
		cout<<"-------------------------------------"<<endl;
	}
	cout<<"-------------------------------------"<<endl<<endl;
}

void  System::PrintUser(string name){
	User* user = FindUser(name);
	user->Detail(); 
}

void  System::PrintUser(char* phone){
	User* user = FindUser(phone);
	user->Detail(); 
}

void  System::Detail_Phone(){
	cout << endl;
	cout << "Compania   : " << Get_Company() << endl;
	cout << "Version SO : " << Get_Version_SO() << endl;
	cout << "Modelo: " << Get_Model() << endl;
	cout << "Pixeles camara frontal  : " << Get_Camera_f() << endl;
	cout << "Pixeles camara trasera  : " << Get_Camera_t() << endl;
	//cout << "Duenio : " << Get_Owner() << endl;
	cout << "Capacidad de memoria Ram: " << Get_Mem_r() << endl;
	cout << "Capacidad de memoria Rom: " << Get_Mem_rom() << endl;
	cout << "Peso : " << Get_Weight() << endl;
	cout << "Numero Asignado: " << Get_PhoneC() << endl;
	cout << "Precio : " << Get_Price() << endl;

}


bool System::NewPhone(){
	Phone tel;
	
	string company="Telcel";
	string model="Uawey 2.5";
	string version_SO="android 2.5";
	string camera_f="13 mega pixels";
	string camera_t="12 Mpx";
	//string owner;
	int mem_r=8;
	int mem_rom=2;
	int weight=8;
	//int num_Phones;
	//User* contact;
	char number[50];
	float  price=1255.00;

	

	tel.Set_Company(company);
	tel.Set_Model(model);
	tel.Set_Version_SO(version_SO);
	tel.Set_Camera_f(camera_f);
	tel.Set_Camera_t(camera_t);
	tel.Set_Mem_r(mem_r);
	tel.Set_Mem_rom(mem_rom);
	tel.Set_Weight(weight);
	tel.Set_PhoneC(number);
	tel.Set_Price(price);
	flag =true;

	return flag;


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
User* System::FindUser(string name){}
User* System::FindUser(char* phone){}
User* System::FindUser(string name,char* phone){}