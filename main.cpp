#include <iostream>
#include "libs/system.h"

using namespace std;

int main(){
	System system;
	char   opcion;

	cout << endl << endl << "\t\tBienvenido " << endl;

	while(opcion != '0'){
	cout << endl;
	cout << "\tMenu - Usuarios Resgistrados (" << system.NumUsers() << ")" << endl;	
	cout << "1-Ingresar un nuevo Usario." << endl;
	cout << "2-Registra compra de telefono." << endl;
	cout << "3-Imprimir factura." << endl;
	cout << "4-Buscar usuarios." << endl;
	cout << "5-Mostrar todos usarios." << endl;
	cout << "0-Salir." << endl;

	
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		switch(opcion){
			case '1':
				system.NewUser();
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				system.FindUser();
				break;
			case '5':
				system.PrintAllUsers();
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
