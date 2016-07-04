#include <iostream>
#include <string.h>
#include "../libs/system.h"
#include "../libs/list.h"
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
System::System(){}

System::~System(){}

/* Getters y Setters */
void System::NewUser(){
	string name;
	string address;
	float  credit; 
	cout << endl;
	cout << "Nombre: " ;
	cin  >> name;
	cout << "Direccion: " ;
	cin  >> address;
	cout << "Credito: " ;
	cin  >> credit;

	User user(name,address,credit);
	users.NewElement(user);
	cout << "Usuario registrado exitosamente !!!"<< endl;
}

void System::PrintAllUsers(){
	PrintMessage();
	users.PrintALL();
}

int System::NumUsers(){
	return users.Get_NumElements();
}

void System::FindUser(){
	
	char   op;
	int    itemp;
	string stemp;

	while(op != '0'){
	stemp = "";
	itemp = 0;
	cout << endl;
	cout << "\tBuscar por:"  << endl;
	cout << "1-Por nombre." << endl;
	cout << "2-Por numero telefonico." << endl;
	cout << "3-Por cantidad de telefonos." << endl;
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