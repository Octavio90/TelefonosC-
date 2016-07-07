#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include "../libs/system.h"
#include "../libs/list.h"

using namespace std;


/* Constructores y Destructores */
System::System(){
	Set_ContUser(0);
	Set_ContPhone(0);
	Set_ContBill(0);
}

System::~System(){}

/* Getters and Setters*/

void System::Set_ContUser(int contUser){this->contUser = contUser;}
void System::Set_ContPhone(int contPhone){this->contPhone = contPhone;}
void System::Set_ContBill(int contBill){this->contBill = contBill;}

int System::Get_ContUser(){return contUser;}
int System::Get_ContPhone(){return contPhone;}
int System::Get_ContBill(){return contBill;} 


/* Metodos */
void System::NewUser(){

	string name;
	string address;
	float  credit;
	cout << endl;
	cin.ignore(256,'\n');
	cout << "Nombre: " ;
	getline(cin,name);
	
	cout << "Direccion: " ;
	getline(cin,address);
	
	cout << "Credito: $" ;
	cin  >> credit;

	User user(name,address,credit,1000+Get_ContUser());
	Set_ContUser(Get_ContUser() + 1);
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
	int    opcion;
	float  price; 
	char   phoneNumber[15];

	cout << endl;
	cin.ignore(256,'\n');
	cout << "Compania: " ;
	getline(cin,company);

	cout << "Modelo: " ;
	getline(cin,model);

	cout << "Version (1-Android (default) / 2-iOS): " ;
	cin  >> opcion;	
		switch(opcion){
			case 1:
				version = "Android";
				break;
			case 2:
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

	Phone phone(company,model,version,weight,camera_f,camera_t,mem_ram,mem_rom,price,1000+Get_ContPhone());
	Set_ContPhone(Get_ContPhone() + 1);

 	cout << endl << "Deseas Ingresar numero telfonico ? (1-Si / 2-No): ";
 	cin  >> opcion;
 		switch(opcion){
			case 1:
				cout << endl;
				cout << "Ingrese el numero telefonico: ";
				cin  >> phoneNumber;
				phone.Set_PhoneNumber(phoneNumber);
				break;
			case 2:
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

void System::PrintAllBills(){
	PrintMessage();
	bills.PrintALL();
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
	cout << "1-Por ID del usuario."<< endl;
	cout << "2-Por nombre." << endl;
	cout << "3-Por numero telefonico." << endl;
	cout << "4-Por cantidad de telefonos." << endl;
	cout << "0-Regresar al menu principal" << endl; 
	cout << endl << "Seleccione una opcion: ";
	cin  >> op;
	cin.ignore(256,'\n');
		switch(op){
			case '1':
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
			case '2':
				cout << endl << "Ingrese el nombre del usuario: ";
				getline(cin,stemp);
				PrintMessage();
				users.FindByName(stemp);
				break;
			case '3':
				cout << endl << "Ingrese el numero telefonico: ";
				cin  >> stemp;
				user = phones.FindByPhoneNumber(stemp)->Get_Owner();
				PrintMessage();
					if(user != NULL)
						user->Detail();
					else
						cout << "Usuario no encontrado" << endl;
				cout << "-----------------------------" << endl;
				cout << "-----------------------------" << endl;
				break;
			case '4':
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


void System::FindPhone(){
	int    itemp;
	string stemp;
	float  pricetemp;
	char   op;
	char  *phoneNumber;
	Phone *phone;

	while(op != '0'){
		stemp = "";
		pricetemp = 0;
		cout << endl;
		cout << "\tBuscar telefono por:"  << endl;
		cout << "1-Por ID del Telefono." << endl;
		cout << "2-Por Modelo." << endl;
		cout << "3-Por Precio." << endl;
		cout << "4-Por numero telefonico." << endl;
		cout << "0-Regresar al menu principal" << endl; 
		cout << endl << "Seleccione una opcion: ";
		cin  >> op;
		cin.ignore(256,'\n');
		switch(op){
			case '1':
				cout<<endl<<"Ingrese el ID del telefono : ";
				cin >> itemp;
				phone = phones.FindPhoneByID(itemp);
				PrintMessage();
					if(phone != NULL)
						phone->Detail();
					else
						cout << "Telefono no encontrado" << endl;
				cout << "-----------------------------" << endl;
				cout << "-----------------------------" << endl;
				break;
			case '2':
				cout<<endl<<"Ingrese el modelo del telefono : ";
				getline(cin,stemp);
				PrintMessage();
				phones.FindByModel(stemp); 
				break;
			case '3':
				cout<<endl<<"Ingrese el precio del telefono : ";
				cin>>pricetemp;
				PrintMessage();
				phones.FindByPrice(pricetemp); 
				break;
			case '4':
				cout << endl << "Ingrese el numero telefonico: ";
				cin  >> stemp;
				phone = phones.FindByPhoneNumber(stemp);
				PrintMessage();
					if(phone != NULL)
						phone->Detail();
					else
						cout << "Telefono no encontrado" << endl;
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
		cin.ignore(256,'\n');
		switch(op){
			case '1':
				cout << "Ingrese nuevo Nombre: " ;
				getline(cin,stemp);
				user->Set_Name(stemp);
				stemp = "";
				break;
			case '2':
				cout << "Ingrese nueva Direccion: " ;
				getline(cin,stemp);
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
				getline(cin,stemp);
				user->Set_Name(stemp);
				stemp = "";
				cout << "Ingrese nueva Direccion: " ;
				getline(cin,stemp);
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
	Phone *phone;
	int    itemp;
	int    opcion;
	string stemp;
	string version;
	float  ftemp;
	char   ctemp[25];

	cout<<endl<<"Ingrese el numero del telefono a modificar\n el numero debe de ser de 10 digitos iniciando con 55 :";
	cin>>stemp;
	phone = phones.FindByPhoneNumber(stemp);
	PrintMessage();
		if(phone != NULL)
			phone->Detail();
		else
			cout << "Telefono no encontrado" << endl;
	cout << "-----------------------------" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

		
	if(phone != NULL){

		cout << "\tModificar:" << endl;
		cout << "1-Compania." << endl;
		cout << "2-Modelo." << endl;
		cout << "3-Version." << endl;
		cout << "4-Peso." << endl;
		cout << "5-Camara frontal." << endl;
		cout << "6-Camara trasera." << endl;
		cout << "7-Memoria ram." << endl;
		cout << "8-Memoria rom" << endl;
		cout << "9-Precio." << endl;
		cout << "10-Numero telefonico"<<endl;
		cout << "11-todas las opciones sin modificar el numero "<<endl;
		cout << "12-todas las opciones "<<endl;
		cout << "Seleccione una opcion: ";
		cin  >> opcion;
		cout << endl;
		cin.ignore(256,'\n');
		switch(opcion){
			case 1:
				cout << "Ingrese la nueva compania: " ;
				getline(cin,stemp);
				phone->Set_Company(stemp);
				stemp = "";
				break;
			case 2:
				cout << "Ingrese nuevo modelo: " ;
				getline(cin,stemp);
				phone->Set_Model(stemp);
				stemp = "";
				break;
			case 3:
				cout << "Version (1-Android (default) / 2-iOS): " ;
				cin  >> itemp;	
					switch(itemp){
						case 1:
							stemp = "Android";
							phone->Set_Version(stemp);
							stemp="";
							break;
						case 2:
							stemp  = "iOS";
							phone->Set_Version(stemp);
							stemp="";
							break;
						default:
							cout << "Opcion invalida, asignando valor por default (Android)" << endl;
							stemp = "Android";
							phone->Set_Version(stemp);
							stemp="";
							break;
					}
				
				break;
			case 4:
				cout << "Ingrese el peso : " ;
				cin  >> ftemp;
				phone->Set_Weight(ftemp);
				break;
			case 5:
				cout << "Resolucion Camara frontal (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_f(ftemp);
				break;
			case 6:
				cout << "Resolucion Camara trasera (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_t(ftemp);
				break;
			case 7:
				cout << "Memoria RAM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_ram(itemp);
				break;
			case 8:
				cout << "Memoria ROM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_rom(itemp);
				break;
			case 9:
				cout << endl;
				cout << "Ingrese el nuevo precio: ";
				cin  >> ftemp;
				phone->Set_Price(ftemp);
				break;
			case 10:
				cout << endl;
				cout << "Ingrese el nuevo numero telefonico: ";
				cin  >> ctemp;
				phone->Set_PhoneNumber(ctemp);
				break;
			case 11:
				cout << "Ingrese la nueva compania: " ;
				getline(cin,stemp);
				phone->Set_Company(stemp);
				stemp = "";
				cout << "Ingrese nuevo modelo: " ;
				getline(cin,stemp);
				phone->Set_Model(stemp);
				stemp = "";
				cout << "Version (1-Android (default) / 2-iOS): " ;
				cin  >> itemp;	
					switch(itemp){
						case 1:
							stemp = "Android";
							break;
						case 2:
							stemp = "iOS";
							break;
						default:
							cout << "Opcion invalida, asignando valor por default (Android)" << endl;
							stemp = "Android";
							break;
					}
				//cin  >> stemp;
				phone->Set_Version(stemp);
				stemp="";
				cout << "Ingrese el peso : " ;
				cin  >> ftemp;
				phone->Set_Weight(ftemp);
				cout << "Resolucion Camara frontal (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_f(ftemp);
				cout << "Resolucion Camara trasera (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_t(ftemp);
				cout << "Memoria RAM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_ram(itemp);
				itemp=0;
				cout << "Memoria ROM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_rom(itemp);
				itemp=0;
				cout<<endl;
				cout << endl;
				cout << "Ingrese el nuevo precio: ";
				cin  >> ftemp;
				phone->Set_Price(ftemp);
				break;
			case 12:
				cout << "Ingrese la nueva compania: " ;
				getline(cin,stemp);
				phone->Set_Company(stemp);
				stemp = "";
				cout << "Ingrese nuevo modelo: " ;
				getline(cin,stemp);
				phone->Set_Model(stemp);
				stemp = "";
				cout << "Version (1-Android (default) / 2-iOS): " ;
				cin  >> itemp;	
					switch(itemp){
						case 1:
							stemp = "Android";
							break;
						case 2:
							stemp = "iOS";
							break;
						default:
							cout << "Opcion invalida, asignando valor por default (Android)" << endl;
							stemp = "Android";
							break;
					}
				//cin  >> stemp;
				phone->Set_Version(stemp);
				stemp="";
				cout << "Ingrese el peso : " ;
				cin  >> ftemp;
				phone->Set_Weight(ftemp);

				cout << "Resolucion Camara frontal (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_f(ftemp);

				cout << "Resolucion Camara trasera (Mpx): " ;
				cin  >> ftemp;
				phone->Set_Camera_t(ftemp);

				cout << "Memoria RAM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_ram(itemp);
				itemp=0;
				cout << "Memoria ROM (MB): " ;
				cin  >> itemp;
				phone->Set_Mem_rom(itemp);
				itemp=0;
				cout << endl;
				cout << "Ingrese el nuevo precio: ";
				cin  >> ftemp;
				phone->Set_Price(ftemp);
				cout << endl;
				cout << "Ingrese el nuevo numero telefonico: ";
				cin  >> ctemp;
				phone->Set_PhoneNumber(ctemp);
				cout<<endl;
				break;
			default:
				cout << "Opcion invalida !!! " << endl;
				break;
		}
			
		cout << "Telefono modificado !!!" << endl;
		phone->Detail();
	}
}

void System::BuyPhone(){

	int    itemp;
	char   op;
	char   op2;
	char   op3;
	char   op4;
	string stemp;
	User   *user;
	Phone  *phone;

	do{
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

		if(user != NULL)
			cout << "Continuar?       (N)"<< endl;
		
		cout << "Cambiar usuario? (C)"<< endl;
		cout << "Salir            (E)"<< endl;
		cout << "Seleccione una Opcion: ";
		cin  >> op;
		
		if(op == 'E' || op == 'e'){break;}
		
		if(user != NULL && (op == 'N' || op == 'n')){
			do{
				cout << endl << "Ingrese el ID telefonico: ";
				cin  >> itemp;
				phone = phones.FindPhoneByID(itemp);
				PrintMessage();
				if(phone != NULL)
					phone->Detail();
				else
					cout << "Usuario no encontrado" << endl;
				cout << "-----------------------------" << endl;
				cout << "-----------------------------" << endl;
				cout << endl;

				if(phone != NULL)
					cout << "Continuar?       (N)"<< endl;
				
				cout << "Cambiar usuario? (C)"<< endl;
				cout << "Salir            (E)"<< endl;
				cout << "Seleccione una Opcion: ";
				cin  >> op2;

				if(op2 == 'E' || op2 == 'e'){break;}

				if(phone != NULL && (op2 == 'N' || op2 == 'n')){

					cout << endl << "Confirmar compra (y/n): " ;
					cin  >> op3;

					if(op3 == 'n' || op3 == 'N'){
						return ;
					}
					else{
						User *oldOwner=phone->Get_Owner();
						if(user->Get_Credit() < phone->Get_Price()){
							cout << "El usuario " << user->Get_Name() << " no cuenta con suficientes fondos !!!" << endl; 
							return ;
						
						}else if(oldOwner != NULL){
							cout << "El numero telefonico que intenta registrar ya tiene un propietario ( ";
							cout << oldOwner->Get_Name() << ")" << endl<< endl;
							return;
						}
						else{
							phone->Set_Owner(user);
							user->Get_Phones()->NewElement(phone->Get_PhoneNumber(op));
							user->Set_Credit(user->Get_Credit() - phone->Get_Price());
							cout << "Compra confirmada de " << user->Get_Name() << " con el numero "; 
							cout << phone->Get_PhoneNumber() << " !!! "<< endl << endl;
							NewBill(*user,*phone);	
							return;
						}
					}
				}
			}while(op2 == 'C' || op2 == 'c');
		}
	}while(op == 'C' || op == 'c');
}


void System::NewBill(User &user, Phone &phone){

	Bill  bill(user,phone,phone.Get_Price(),"07/07/2016",1000+Get_ContBill());
	bills.NewElement(bill);
	Set_ContBill(Get_ContBill() + 1);
}

void System::FindBill(){
	int    itemp;
	string stemp;
	float  ftemp;
	char   op;
	char   phoneNumber[25];
	Bill  *bill;

	while(op != '0'){
		stemp = "";
		ftemp = 0;
		cout << endl;
		cout << "\tBuscar telefono por:"  << endl;
		cout << "1-Por ID de la Factura." << endl;
		cout << "2-Por nombre del cliente." << endl;
		cout << "3-Por Precio." << endl;
		cout << "4-Por numero telefonico." << endl;
		cout << "0-Regresar al menu principal" << endl; 
		cout << endl << "Seleccione una opcion: ";
		cin  >> op;
		cin.ignore(256,'\n');
		switch(op){
			case '1':
				cout<<endl<<"Ingrese el ID de la factura : ";
				cin >> itemp;
				bill = bills.FindBillByID(itemp);
					if(bill != NULL)
						bill->Detail();
					else
						cout << "Factura no encontrado" << endl;
				break;
			case '2':
				cout<<endl<<"Ingrese el nombre del cliente : ";
				getline(cin,stemp);
				bills.FindBillByUser(stemp); 
				break;
			case '3':
				cout<<endl<<"Ingrese el precio de la factura : ";
				cin>>ftemp;
				bills.FindBillByPrice(ftemp); 
				break;
			case '4':
				cout << endl << "Ingrese el numero telefonico: ";
				cin  >> stemp;
				bill = bills.FindBillByPhoneNumber(stemp);
					if(bill != NULL)
						bill->Detail();
					else
						cout << "Factura no encontrado" << endl;
				break;
			case '0':
				break;
			default:
				cout << "Opcion invalida !!! " << endl << endl;
				break;
			}
	}
}	
