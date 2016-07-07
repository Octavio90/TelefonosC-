#include <iostream>
#include "libs/system.h"

using namespace std;

int main(){
	System system;

	int    opcion = -1;

	cout << endl << endl << "\t\tBienvenido " << endl;

	while(opcion != 0){
	cout << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "| Menu - Usuarios  Resgistrados (" << system.NumUsers() << ")   |" << endl;	
	cout << "|        Telefonos Resgistrados (" << system.NumPhones() << ")   |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "|             Usuario                 |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "| 1-Alta usuario.                     |" << endl;
	cout << "| 2-Modificar usuario.                |" << endl;
	cout << "| 3-Buscar usuario.                   |" << endl;
	cout << "| 4-Mostrar todos los usarios.        |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "|            Telefonos                |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "| 5-Alta telefono.                    |" << endl;
	cout << "| 6-Compra telefono.                  |" << endl;
	cout << "| 7-Buscar telefonos.                 |" << endl;
	cout << "| 8-Mostrar todos telefonos.          |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "|             Facturas                |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "| 9-Imprimir todas las facturas.      |" << endl;
	cout << "| 10-Buscar facturas.                 |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "|             Mensajes                |" << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "| 11-Enviar Mensajes.                 |" << endl;
	cout << "| 12-Ver Mensajes                     |" << endl;
	cout << "| 0-Salir.                            |" << endl;
	cout << "+-------------------------------------+" << endl << endl;	

	
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		switch(opcion){
				/*  Opciones Usuario */
			case 1:
				cout << "\033[2J\033[1;1H";
				system.NewUser();
				break;
			case 2:
				cout << "\033[2J\033[1;1H";
				system.ModifyUser();
				break;
			case 3:
				cout << "\033[2J\033[1;1H";
				system.FindUser();
				break;
			case 4:
				cout << "\033[2J\033[1;1H";
				system.PrintAllUsers();
				break;
				/*  Opciones Telefono */
			case 5:
				cout << "\033[2J\033[1;1H";
				system.NewPhone();
				break;
			case 6:
				cout << "\033[2J\033[1;1H";
				system.BuyPhone();
				break;
			case 7:
				cout << "\033[2J\033[1;1H";
				system.FindPhone();
				break;
			case 8:
				cout << "\033[2J\033[1;1H";
				system.PrintAllPhones();
				break;
			case 9:
				cout << "\033[2J\033[1;1H";
				system.PrintAllBills();
				break;
			case 10:
				cout << "\033[2J\033[1;1H";
				system.FindBill();
				break;
			case 11:
				cout << "\033[2J\033[1;1H";
				system.SendMessage();
				break;
			case 12:
				cout << "\033[2J\033[1;1H";
				system.ViewMessage();
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
