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

	//seteando telefono
	Set_Num_Phones(0);
	phones=NULL;
	
	phones=new Phone[SIZE];
		if (phones==NULL){
			cout << "No se pudo reservar espacio para guardar celulares. " << endl;

		}
}

System::~System(){
	if(users != NULL){
		delete [] users;
	}
	if (phones!=NULL){
		delete[] phones;
	}

}

/* Getters y Setters */

void System::Set_NumUsers(int numUsers){this->numUsers=numUsers;}

int  System::Get_NumUsers(){return numUsers;}
//Para telefono 
void System::Set_Num_Phones(int numPhones){this->numPhones=numPhones;}

int System::Get_Num_Phones(){return numPhones;}


/* Metodos */
void  System::PrintBill(){}
//Metodo para imprimir el celular almacenado 
void System::PrintPhones(){
	Phone *phone=phones;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;

	for(int i=0;i<Get_Num_Phones();i++){
		(phones+i)->Detail_Phone();
		cout << "-------------------------------------" << endl;
	}
	cout << "-------------------------------------" << endl << endl;
}
//----------------------------------------------------------

//MEtodos de Phone





//---------------------------------------------------------


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

void System::PrintUser(int number){
	User* user = FindUser(number);
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;
	if(user != NULL)
		user->Detail();
	else
		cout << "Usuario NO encontrado." << endl; 
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl << endl;	
}

/*void  System::Detail_Phone(){
	
	cout << endl;
	cout << "Compania   : " << Get_Company() << endl;
	cout << "Modelo: " << Get_Model() << endl;
	cout << "Version SO : " << Get_Version() << endl;
	cout << "Pixeles camara frontal  : " << Get_Camera_f() << endl;
	cout << "Pixeles camara trasera  : " << Get_Camera_t() << endl;
	cout << "Capacidad de memoria Ram: " << Get_Mem_ram() << endl;
	cout << "Capacidad de memoria Rom: " << Get_Mem_rom() << endl;
	cout << "Peso : " << Get_Weight() << endl;
	cout << "Precio : " << Get_Price() << endl;

}*/



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
			memcpy(users2, users, Get_NumUsers()*sizeof(User));
			//delete [] users;
			users = users2;
		}
		users[idx] = user;
		Set_NumUsers(idx+1);
		flag=true;
	}
	
	return flag;
}


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
	User *user = NULL;
	char *temp = phone;
	char *cellPhone = NULL;
	int   flag = 0;

	for(int i=0;i<Get_NumUsers();i++){
		user = (users+i);
		flag = 0;
		cellPhone = user->Get_PhoneNumber();
		cout << "Valor Objeto: " << cellPhone ;
		cout << "\t Comparando con: " << phone << endl;
		for(int j=0;j<10;j++){
			cout << "Valor cellPhone: " << *(cellPhone+j);
			cout << "\t Valor phone: " << *(phone+j) << endl;
			if(*(cellPhone+j) == *(phone+j)){
				flag ++;
			}
			else {
				break;
			}
		}
		cout << "Valor flag: " << flag << endl;
		if(flag == 10){
			return user;
		}
		else{
			phone      = temp;
			cellPhone -= flag;
			user       = NULL;
		}
	}
	return user;	
}

User* System::FindUser(int number){
	User *user = NULL;
	for(int i=0;i<Get_NumUsers();i++){
		user = (users+i);
		if(user->Get_NumPhones() == number){
			return user;
		}
		else{
			user = NULL;
		}
	}
	return user;	
}

bool  System::BuyPhone(){
	//valores anteriores
	/*Phone mi_tel;
	string company;
	string model;
	float weight;
	float version;
	float camera_f;
	float camera_t;
	int mem_ram;
	int mem_rom;
	float price;
	int cont=0;

	//bandera para saber si se almaceno el telefono
	int numP=Get_Num_Phones();
	bool flag=false;
	//Nuevos valores para preguntar si el telefono se asignara a un usuario
	*/

	//declarando nuevos valores como para usuario
	char op;
	char number[50];
	string temp=" ";
	bool flag=false;
	int idx=Get_Num_Phones();
	
	string company;
	string model;
	float weight;
	float version;
	float camera_f;
	float camera_t;
	int mem_ram;
	int mem_rom;
	float price;
	/*cout<<"El telefono a dar de alta sera asignado a un usuario? (y/n)";
	cin>>op;
	if(op=='y' || op=='Y'){
			while(temp == ""){
			cout << endl << "Nombre de la Persona: ";
			cin  >> temp;
			if(temp == ""){
				cout << "El nombre debe tener almenos un caracter !!!" << endl;
			}
			cout<<"Numero Telefonico: ";
			cin>>number;
			Phone mi_tel(temp,number);
		}
	}*/

		Phone mi_tel;	

		cout<<"Ingresa el numero de celulares a almacenar : ";
		cin>>idx;
		mi_tel.Set_Num_Phones(idx);
		
			
		cout<<"Ingresa los datos del celular :"<<endl;
		cout<<"Ingresa la Compania del celular : ";
		cin>>company;
		mi_tel.Set_Company(company);
		cout<<"Ingresa la Modelo del celular : ";
		cin>>model;
		mi_tel.Set_Model(model);
		cout<<"Ingresa el Peso del celular : ";
		cin>>weight;
		mi_tel.Set_Weight(weight);
		cout<<"Ingresa la Version del Sistema OP : ";
		cin>>version;
		mi_tel.Set_Version(version);
		cout<<"Ingresa los pixeles de la camara frontal : ";
		cin>>camera_f;
		mi_tel.Set_Camera_f(camera_f);
		cout<<"Ingresa los pixeles de la camara trasera : ";
		cin>>camera_t;
		mi_tel.Set_Camera_t(camera_t);
		cout<<"Capacidad de memoria ram : ";
		cin>>mem_ram;
		mi_tel.Set_Mem_ram(mem_ram);
		cout<<"Capacidad de memoria rom : ";
		cin>>mem_rom;
		mi_tel.Set_Mem_rom(mem_rom);
		cout<<"Precio del celular : ";
		cin>>price;
		mi_tel.Set_Price(price);
		//seteando los valores 
		
				
	//viendo el espacio de almacenamiento para celulares
		if(idx<SIZE){
			phones[idx]=mi_tel;
			cout<<"-----------Numero de telefonos......"<<endl;
			cout<<phones<<endl;
			Set_Num_Phones(idx+1);
			flag=true;
		}
		else{
			Phone *new_Phone=new Phone[Get_Num_Phones()+SIZE];
			if(new_Phone==NULL){
				cout<<"No se pueden almacenar mas celulares en la memoria !"<<endl;
			}else{
				//reservando memoria y copiando los datos anteriores a la nueva memoria
				memcpy(new_Phone,phones,Get_Num_Phones()*sizeof(Phone));
				phones=new_Phone;			
			}
			phones[idx]=mi_tel;
			Set_Num_Phones(idx+1);
			flag=true;
		}
		return flag;
}
/*void System::Detail_Phone(){
		
	
}*/




