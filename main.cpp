#include <iostream>
#include "libs/user.h"
#include "libs/system.h"

using namespace std;

int main(){

	System system;
	string stemp;
	int    itemp;
	char   telefono[50];
	char   opcion;
	bool   flag;

	cout << endl << endl << "\t\tBienvenido " << endl << endl;

	while(opcion != '0'){
	cout << "\tMenu - Usuarios Resgistrados (" << system.Get_NumUsers() << ")" << endl;	
	cout << "1-Ingresar un nuevo Usario." << endl;
	cout << "2-Registra compra de telefono." << endl;
	cout << "3-Imprimir factura." << endl;
	cout << "4-Buscar usuario por nombre." << endl;
	cout << "5-Buscar usuario por telefono." << endl;
	cout << "6-Buscar usuario por cantidad de telefonos." << endl;
	cout << "7-Mostrar todos usarios." << endl;
	cout << "0-Salir." << endl;

	
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		switch(opcion){
			case '1':
				flag = system.NewUser();
				if(flag == true)
					cout << "Usuario ingresado correctamente !" << endl << endl;
				else
					cout << "Ocurrio un problema, intente nuevamente " << endl << endl;
				break;
			case '4':
				cout << endl;
				cout << "Ingresa el nombre del usario: "; 
				cin  >> stemp;
				system.PrintUser(stemp);
				stemp = "";
				break;
			case '5':
				cout << endl;
				cout << "Ingresa el numero telefonico: "; 
				cin  >> telefono;
				system.PrintUser(telefono);
				break;
			case '6':
				cout << "Cantidad de telefonos: "; 
				cin  >> itemp;
				system.PrintUser(itemp);
				break;
			case '7':
				system.PrintAllUsers();
			case '0':
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
		}
	}
	
	return 0;	
}