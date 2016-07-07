#include <iostream>
#include <string.h>
#include "../libs/bill.h"



using namespace std;


/* Constructores y Destructores */
Bill::Bill(){}

Bill::Bill(User &user,Phone &phone,float amount,string date, int idBill){
	Set_User(&user);
	Set_Phone(&phone);
	Set_Amount(amount);
	Set_Date(date);
	Set_IdBill(idBill);
}

Bill::~Bill(){}

/*Getters and Setters*/ 
User*  Bill::Get_User(){return user;}
Phone* Bill::Get_Phone(){return phone;}
string Bill::Get_Date(){return date;}
float  Bill::Get_Amount(){return amount;}
int    Bill::Get_IdBill(){return idBill;}

void   Bill::Set_IdBill(int idBill){this->idBill=idBill;}
void   Bill::Set_User(User *user){this->user=user;}
void   Bill::Set_Phone(Phone *phone){this->phone=phone;}
void   Bill::Set_Amount(float amount){this->amount=amount;}
void   Bill::Set_Date(string date){this->date=date;}

/* Metodos */
void Bill::Detail(){
	cout << endl;
	cout << "===========================================" << endl;
	cout << "   ..:: Comprobante de Compra ::.. "<<endl;
	cout << "===========================================" << endl;
	cout << "ID Factura        : " << Get_IdBill() << endl;
	cout << "Fecha             : " << Get_Date() << endl;
	cout << "Cliente           : " << user->Get_Name() << endl;
	cout << "Monto             : $ " << Get_Amount() << endl;
	cout << "Numero Telefonico : " << phone->Get_PhoneNumber() << endl;
	cout << "-------------------------------------------" << endl;
	cout << "        Detalle del telefono" << endl<<endl;
	cout << "Marca             : "  << phone->Get_Company() << endl;
	cout << "Modelo            : "  << phone->Get_Model() << endl;
	cout << "Peso              : "  << phone->Get_Weight() << " kg" << endl;
	cout << "Version           : "  << phone->Get_Version() << endl;
	cout << "Memoria RAM       : "  << phone->Get_Mem_ram() << " MB" << endl;
	cout << "Memoria ROM       : "  << phone->Get_Mem_rom() << " MB" << endl;
	cout << "Camara Frontal    : "  << phone->Get_Camera_f() << " Mpx" << endl;
	cout << "Camara Trasera    : "  << phone->Get_Camera_t() << " Mpx" << endl;
	cout << "===========================================" << endl;
	cout << "===========================================" << endl << endl;	

}
