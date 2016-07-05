#include <iostream>
#include <string.h>
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


/* Constructores y Destructores */
Phone::Phone(){}
// agregar al constructor User *own,int num_Phones
Phone::Phone(string comp, string model, float weight,float version,float cameraf, float camerat,int mem_ram,int mem_rom,float price){
	Set_Company(comp);
	Set_Model(model);
	Set_Weight(weight);
	Set_Version(version);
	Set_Camera_f(cameraf);
	Set_Camera_t(camerat);
	Set_Mem_ram(mem_ram);
	Set_Mem_rom(mem_rom);
	Set_Price(price);	
}

//constructor para validar el numero 
Phone::Phone(string comp, string model, float weight,float version,float cameraf, float camerat,int mem_ram,int mem_rom,float price,const char* phoneNumber,int num){
	Set_Company(comp);
	Set_Model(model);
	Set_Weight(weight);
	Set_Version(version);
	Set_Camera_f(cameraf);
	Set_Camera_t(camerat);
	Set_Mem_ram(mem_ram);
	Set_Mem_rom(mem_rom);
	Set_Price(price);
	phoneNumber = NULL;
	Set_Phone_tel(phoneNumber);
	Set_Num_Phones(num);
}

Phone::~Phone(){
	//delete Phone;
}

/* Getters y Setters */
	string Phone::Get_Company(){return this->company;}
	string Phone::Get_Model(){return this->model;}
	float Phone::Get_Weight(){return this->weight;}
	float Phone::Get_Version(){return this->version;}
	float Phone::Get_Camera_f(){return this->camera_f;}
	float Phone::Get_Camera_t(){return this->camera_t;}
	int Phone::Get_Mem_ram(){return this->mem_ram;}
	int Phone::Get_Mem_rom(){return this->mem_rom;}
	float Phone::Get_Price(){return this->price;}
	char* Phone::Get_Phone_tel(){return this->phoneNumber;}
	int Phone::Get_Num_Phones(){return this->num_Phones;}

	void   Phone::Set_Company(string comp){this->company=comp;}
	void   Phone::Set_Model(string mol){this->model=mol;}
	void   Phone::Set_Weight(float w){this->weight=w;}
	void   Phone::Set_Version(float v){this->version=v;}
	void   Phone::Set_Camera_f(float cf){this->camera_f=cf;}
	void   Phone::Set_Camera_t(float ct){this->camera_t=ct;}
	void   Phone::Set_Mem_ram(int mram){this->mem_ram=mram;}
	void   Phone::Set_Mem_rom(int mrom){this->mem_rom=mrom;}
	void   Phone::Set_Price(float p){this->price=p;}
	void   Phone::Set_Num_Phones(int num){this->num_Phones=num;}
	void   Phone::Set_Phone_tel(const char* number){
				char cad[50];
				while(ValidNumber(number) != true){
					cout << "Numero Invalido !!!" << endl;
					cout << "Debe contener 10 caracteres y empezar en '55'" << endl;
					cout << "Ingrese de nuevo el numero telefonico: ";
					cin  >> cad;
					number = cad;
				}
				if(phoneNumber != NULL){
					delete [] phoneNumber;
				}
				phoneNumber = new char[strlen(number)+1];
				strcpy(phoneNumber,number);	
			}

	
/* Metodos */
	void Phone::Detail_Phone(){
	cout << "Compania   : " << Get_Company() << endl;
	cout << "Modelo: " << Get_Model() << endl;
	cout << "Version SO : " << Get_Version() << endl;
	cout << "Pixeles camara frontal  : " << Get_Camera_f() << endl;
	cout << "Pixeles camara trasera  : " << Get_Camera_t() << endl;
	cout << "Capacidad de memoria Ram: " << Get_Mem_ram() << endl;
	cout << "Capacidad de memoria Rom: " << Get_Mem_rom() << endl;
	cout << "Peso : " << Get_Weight() << endl;
	cout << "Precio : " << Get_Price() << endl;
	//cout << "numero de Telefono :"<<Get_Phone_tel()<<endl;

	}


/*void Phone::Usuario_P(){



}*/

bool   Phone::ValidNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 10){
		flag=true;
	}

	return flag;
}