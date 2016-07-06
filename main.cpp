#include <iostream>
#include "libs/system.h"

using namespace std;

int main(){
	System system;
	char   opcion;

	cout << endl << endl << "\t\tBienvenido " << endl;

	while(opcion != '0'){
	cout << endl;
	cout << "\tMenu - Usuarios  Resgistrados (" << system.NumUsers() << ")" << endl;	
	cout << "\t       Telefonos Resgistrados (" << system.NumPhones() << ")" << endl;
	cout << "1-Ingresar un nuevo Usario." << endl;
	cout << "2-Registra compra de telefono." << endl;
	cout << "3-Imprimir factura." << endl;
	cout << "4-Buscar usuarios." << endl;
	cout << "5-Modificar usuarios." << endl;
	cout << "6-Mostrar todos usarios." << endl;
	cout << "7-Guardar Telefono." << endl;
	cout << "8-Mostrar todos telefonos." << endl;
	cout << "9-Buscar telefonos." << endl;
	cout << "0-Salir." << endl;

	
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		switch(opcion){
			case '1':
				cout << "\033[2J\033[1;1H";
				system.NewUser();
				break;
			case '2':
				cout << "\033[2J\033[1;1H";
				system.BuyPhone();
				break;
			case '3':
				break;
			case '4':
				cout << "\033[2J\033[1;1H";
				system.FindUser();
				break;
			case '5':
				cout << "\033[2J\033[1;1H";
				system.ModifyUser();
				break;
			case '6':
				cout << "\033[2J\033[1;1H";
				system.PrintAllUsers();
				break;
			case '7':
				cout << "\033[2J\033[1;1H";
				system.NewPhone();
				break;
			case '8':
				cout << "\033[2J\033[1;1H";
				system.PrintAllPhones();
				break;
			case '9':
				cout << "\033[2J\033[1;1H";
				system.FindPhone();
				break;
			case '0':
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
		}
	}	
	cout << "Adios !!!" << endl << endl;
	return 0;
}
