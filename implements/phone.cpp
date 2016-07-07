#include <iostream>
#include <string.h>
#include <string>
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


/* Constructores y Destructores */
Phone::Phone(){}
Phone::Phone(string comp, string model,string version,float weight,float cameraf, float camerat,int mem_ram,int mem_rom,float price,int idx){
	Set_Company(comp);
	Set_Model(model);
	Set_Weight(weight);
	Set_Version(version);
	Set_Camera_f(cameraf);
	Set_Camera_t(camerat);
	Set_Mem_ram(mem_ram);
	Set_Mem_rom(mem_rom);
	Set_Price(price);
	Set_IdPhone(idx);
	Set_Owner(NULL);
}
Phone::~Phone(){}

/* Getters y Setters */
string Phone::Get_Company(){return company;}
string Phone::Get_Model(){return model;}
string Phone::Get_Version(){return version;}
string Phone::Get_PhoneNumber(){return phoneNumber;}
string* Phone::Get_PhoneNumber(char op){return &phoneNumber;}
float  Phone::Get_Weight(){return weight;}
float  Phone::Get_Camera_f(){return camera_f;}
float  Phone::Get_Camera_t(){return camera_t;}
float  Phone::Get_Price(){return price;}
int    Phone::Get_Mem_ram(){return mem_ram;}
int    Phone::Get_Mem_rom(){return mem_rom;}
int    Phone::Get_IdPhone(){return idPhone;}
User*  Phone::Get_Owner(){return owner;}

void   Phone::Set_Company(string comp){company=comp;}
void   Phone::Set_Model(string mol){model=mol;}
void   Phone::Set_Version(string v){version=v;}
void   Phone::Set_Weight(float w){weight=w;}
void   Phone::Set_Camera_f(float cf){camera_f=cf;}
void   Phone::Set_Camera_t(float ct){camera_t=ct;}
void   Phone::Set_Mem_ram(int mram){mem_ram=mram;}
void   Phone::Set_IdPhone(int idx){idPhone = idx;}
void   Phone::Set_Mem_rom(int mrom){mem_rom=mrom;}
void   Phone::Set_Price(float p){price=p;}
void   Phone::Set_Owner(User *owner){this->owner = owner;}
void   Phone::Set_PhoneNumber(string number){phoneNumber = number;}
void   Phone::Set_PhoneNumber(const char *number){
	if(number !=NULL){
		char cad[25];
		while(ValidNumber(number) != true){
			cout << "Numero Invalido !!!" << endl;
			cout << "Debe contener 10 caracteres y empezar en '55'" << endl;
			cout << "Ingrese de nuevo el numero telefonico: ";
			cin  >> cad;
			number = cad;
		}
		string temp(number);
		phoneNumber = temp;
	}
}



/* Metodos */
void Phone::Detail(){
	cout << "ID Telefono      : " << Get_IdPhone() << endl;
	if(Get_Owner() != NULL)
		cout << "Propietario      : " << Get_Owner()->Get_Name() << endl;
	else
		cout << "Propietario      : Telefono sin propietario" << endl;
	cout << "Marca            : " << Get_Company() << endl;
	cout << "Modelo           : " << Get_Model() << endl;
	cout << "Peso             : " << Get_Weight() << " kg" << endl;
	cout << "Version          : " << Get_Version() << endl;
	cout << "Precio           : $" << Get_Price() << endl;
	cout << "Memoria RAM      : " << Get_Mem_ram() << " MB" << endl;
	cout << "Memoria ROM      : " << Get_Mem_rom() << " MB" << endl;
	cout << "Camara Frontal   : " << Get_Camera_f() << " Mpx" << endl;
	cout << "Camara Trasera   : " << Get_Camera_t() << " Mpx" << endl;
	if(Get_PhoneNumber() != "")
		cout << "Numero Telefonico: " << Get_PhoneNumber() << endl;
	else
		cout << "Numero Telefonico: Sin numero asignado." << endl;
}


bool Phone::ValidNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 10){
		flag=true;
	}
	return flag;
}

