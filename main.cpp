#include <iostream>
#include "libs/user.h"
#include "libs/system.h"

using namespace std;

int main(){

	System system;
	char opcion;
	bool flag;

	cout << endl << endl << "\tBienvenido " << endl << endl;

	while(opcion != '0'){
	cout << "Menu - Usuarios Resgistrados (" << system.Get_NumUsers() << ")" << endl;	
	cout << "1-Ingresar un nuevo Usario." << endl;
	cout << "2-Registra compra de telefono." << endl;
	cout << "3-Imprimir factura." << endl;
	cout << "4-Buscar usuario." << endl;
	cout << "5-Mostrar todos usarios." << endl;
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
			case '5':
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