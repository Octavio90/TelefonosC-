#include <iostream>
#include "libs/system.h"

using namespace std;

int main(){
	System system;
	int    opcion;

	cout << endl << endl << "\t\tBienvenido " << endl;

	while(opcion != 0){
	cout << endl;
	cout << "\tMenu - Usuarios  Resgistrados (" << system.NumUsers() << ")" << endl;	
	cout << "\t       Telefonos Resgistrados (" << system.NumPhones() << ")" << endl;
	cout << "1-Ingresar un nuevo Usario." << endl;
	cout << "2-Registra compra de telefono." << endl;
	cout << "3-Imprimir todas  las factura." << endl;
	cout << "4-Buscar facturas." << endl;
	cout << "5-Buscar usuarios." << endl;
	cout << "6-Modificar usuarios." << endl;
	cout << "7-Mostrar todos usarios." << endl;
	cout << "8-Guardar Telefono." << endl;
	cout << "9-Mostrar todos telefonos." << endl;
	cout << "10-Buscar telefonos." << endl;
	cout << "0-Salir." << endl;

	
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		switch(opcion){
			case 1:
				cout << "\033[2J\033[1;1H";
				system.NewUser();
				break;
			case 2:
				cout << "\033[2J\033[1;1H";
				system.BuyPhone();
				break;
			case 3:
				cout << "\033[2J\033[1;1H";
				system.PrintAllBills();
				break;
			case 4:
				cout << "\033[2J\033[1;1H";
				system.FindBill();
				break;
			case 5:
				cout << "\033[2J\033[1;1H";
				system.FindUser();
				break;
			case 6:
				cout << "\033[2J\033[1;1H";
				system.ModifyUser();
				break;
			case 7:
				cout << "\033[2J\033[1;1H";
				system.PrintAllUsers();
				break;
			case 8:
				cout << "\033[2J\033[1;1H";
				system.NewPhone();
				break;
			case 9:
				cout << "\033[2J\033[1;1H";
				system.PrintAllPhones();
				break;
			case 10:
				cout << "\033[2J\033[1;1H";
				system.FindPhone();
				break;
			case 0:
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
		}
	}	
	cout << "Adios !!!" << endl << endl;
	return 0;
}
