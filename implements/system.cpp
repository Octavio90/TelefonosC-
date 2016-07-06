#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include "../libs/system.h"
#include "../libs/list.h"
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
System::System(){}

System::~System(){}

/* Metodos */
void System::NewUser(){

	string name;
	string address;
	float  credit;
	int    id = users.Get_NumElements(); 
	cout << endl;
	//cin.ignore(256,'\n');
	cout << "Nombre: " ;
	cin  >> name;
	//getline(cin,name);
	//cin.ignore(256,'\n');
	cout << "Direccion: " ;
	//getline(cin,name);
	cin  >> address;
	cout << "Credito: " ;
	cin  >> credit;

	User user(name,address,credit,1000+id);
	users.NewElement(user);
	cout << "Usuario registrado exitosamente !!!"<< endl;
}

void System::NewPhone(){
	string company;
	string model;
	string version;
	float  weight;
	float  camera_f;
	float  camera_t;
	int    mem_ram;
	int    mem_rom;
	float  price; 
	char   opcion;
	char   phoneNumber[15];

	cout << endl;
	cout << "Compañia: " ;
	cin  >> company;
	cout << "Modelo: " ;
	cin  >> model;
	cout << "Version (1-Android (default) / 2-iOS): " ;
	cin  >> opcion;	
		switch(opcion){
			case '1':
				version = "Android";
				break;
			case '2':
				version = "iOS";
				break;
			default:
				cout << "Opcion invalida, asignando valor por default (Android)" << endl;
				version = "Android";
				break;
		}
	cout << "Peso (kg): " ;
	cin  >> weight;
	cout << "Resolucion Camara frontal (Mpx): " ;
	cin  >> camera_f;
	cout << "Resolucion Camara trasera (Mpx): " ;
	cin  >> camera_t;
	cout << "Memoria RAM (MB): " ;
	cin  >> mem_ram;
	cout << "Memoria ROM (MB): " ;
	cin  >> mem_rom;
	cout << "Precio : $" ;
	cin  >> price;

	Phone phone(company,model,version,weight,camera_f,camera_t,mem_ram,mem_rom,price);

 	cout << endl << "Deseas Ingresar numero telfonico ? (y/n): ";
 	cin  >> opcion;
 		switch(opcion){
 			case 'Y':
			case 'y':
				cout << endl;
				cout << "Ingrese el numero telefonico: ";
				cin  >> phoneNumber;
				phone.Set_PhoneNumber(phoneNumber);
				break;
			case 'N':
			case 'n':
				break;
			default:
				cout << "Opcion invalida, numero no asignado" << endl;
				break;
		}	
 	
	phones.NewElement(phone);
	cout << "Telefono guardado exitosamente !!!"<< endl;
}

void System::PrintAllUsers(){
	PrintMessage();
	users.PrintALL();
}

void System::PrintAllPhones(){
	PrintMessage();
	phones.PrintALL();
}

int System::NumUsers(){
	return users.Get_NumElements();
}

int System::NumPhones(){
	return phones.Get_NumElements();
}

void System::FindUser(){
	
	char   op;
	int    itemp;
	string stemp;
	User   *user;
	while(op != '0'){
	stemp = "";
	itemp = 0;
	cout << endl;
	cout << "\tBuscar por:"  << endl;
	cout << "1-Por nombre." << endl;
	cout << "2-Por numero telefonico." << endl;
	cout << "3-Por cantidad de telefonos." << endl;
	cout << "4-Por ID del usuario."<< endl;
	cout << "0-Regresar al menu principal" << endl; 
	cout << endl << "Seleccione una opcion: ";
	cin  >> op;

		switch(op){
			case '1':
				cout << endl << "Ingrese el nombre del usuario: ";
				cin  >> stemp;
				PrintMessage();
				users.FindByName(stemp);
				break;
			case '2':
				cout << endl << "Ingrese el numero telefonico: ";
				//cin  >> stemp;
				//users.FindByName(stemp);
				break;
			case '3':
				cout << endl << "Cantidad de telefonos a buscar: ";
				cin  >> itemp;
				PrintMessage();
				users.FindByNumPhones(itemp);
				break;
			case '4':
				cout << endl << "Ingrese el ID del usuario: ";
				cin  >> itemp;
				user = users.FindByID(itemp);
				PrintMessage();
					if(user != NULL)
						user->Detail();
					else
						cout << "Usuario no encontrado" << endl;
				cout << "-----------------------------" << endl;
				cout << "-----------------------------" << endl;
				break;
			case '0':
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
		}
	}
}


void System::FindPhone(){
	char op;
	string motemp;
	float pricetemp;
	char* phoneNumber;
	Phone *phone;
	while(op != '0'){
	motemp = "";
	pricetemp = 0;
	cout << endl;
	cout << "\tBuscar telefono por:"  << endl;
	cout << "1-Por Modelo." << endl;
	cout << "2-Por Precio." << endl;
	cout << "3-Por numero telefonico." << endl;
	cout << "0-Regresar al menu principal" << endl; 
	cout << endl << "Seleccione una opcion: ";
	cin  >> op;
	switch(op){
		case '1':
			cout<<endl<<"Ingrese el modelo del telefono : ";
			cin>>motemp;
			PrintMessage();
			phones.FindByModel(motemp); 
			break;
		case '2':
			cout<<endl<<"Ingrese el precio del telefono : ";
			cin>>pricetemp;
			PrintMessage();
			phones.FindByPrice(pricetemp); 
			break;
		case '3':
			break;
		case '0':
			break;
		default:
			cout << "Opcion invalida !!! " << endl << endl;
			break;
		}
	}
}	


void System::PrintMessage(){
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "\tResultado Busqueda"<<endl;
	cout << "-----------------------------" << endl;
}



void System::ModifyUser(){
	User *user;
	int    itemp;
	float  ftemp;
	string stemp;
	char   op;

	cout << endl;
	cout << endl << "Ingrese el ID del usuario :";
	cin  >> itemp;
	user = users.FindByID(itemp);
	PrintMessage();
		if(user != NULL)
			user->Detail();
		else
			cout << "Usuario no encontrado" << endl;
	cout << "-----------------------------" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	if(user != NULL){

		cout << "\tModificar:" << endl;
		cout << "1-Nombre." << endl;
		cout << "2-Direccion." << endl;
		cout << "3-Credito." << endl;
		cout << "4-Todos los campos." << endl;
		cout << "Seleccione una opcion: ";
		cin  >> op;
		cout << endl;
		switch(op){
			case '1':
				cout << "Ingrese nuevo Nombre: " ;
				cin  >> stemp;
				user->Set_Name(stemp);
				stemp = "";
				break;
			case '2':
				cout << "Ingrese nueva Direccion: " ;
				cin  >> stemp;
				user->Set_Address(stemp);
				stemp = "";
				break;
			case '3':
				cout << "Ingrese nuevo Credito: " ;
				cin  >> ftemp;
				user->Set_Credit(ftemp);
				break;
			case '4':
				cout << "Ingrese nuevo Nombre: " ;
				cin  >> stemp;
				user->Set_Name(stemp);
				stemp = "";
				cout << "Ingrese nueva Direccion: " ;
				cin  >> stemp;
				user->Set_Address(stemp);
				stemp = "";
				cout << "Ingrese nuevo Credito: " ;
				cin  >> ftemp;
				user->Set_Credit(ftemp);
				cout << endl;
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
		}
		cout << "Usuario modificado !!!" << endl;
		user->Detail();
	}
}



void System::ModifyPhone(){
}

