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
	int    id = users.Get_NumElements(); 
	cout << endl;
	cout << "Nombre: " ;
	cin  >> name;
	cout << "Direccion: " ;
	cin  >> address;
	cout << "Credito: " ;
	cin  >> credit;

	User user(name,address,credit,1000+id);
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

void System::PrintMessage(){
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "\tResultado Busqueda"<<endl;
	cout << "-----------------------------" << endl;
}



void System::ModifyUsers(){
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



