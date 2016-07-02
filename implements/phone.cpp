#include <iostream>
#include <string.h>
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


/* Constructores y Destructores */
Phone::Phone(){}
// agregar al constructor User *own,int num_Phones
Phone::Phone(string company,string model ,string SO,string cameraf,string camerat,int ram,int rom,int w,const char* number,float price){
	Set_Company(company);
	Set_Model(model);
	Set_Version_SO(SO);
	Set_Camera_f(cameraf);
	Set_Camera_t(camerat);
	//Set_Owner(own);
	Set_Mem_r(ram);
	Set_Mem_rom(rom);
	Set_Weight(w);
	//Set_Num_Phones(num_Phones);
	//Set_User(contact);
	phoneNumber = NULL;	
	Set_PhoneC(number);
	Set_Price(price);
	
	
}
Phone::~Phone(){
	//delete Phone;
}

/* Getters y Setters */

	string Phone::Get_Company(){return this->company;}
	string Phone::Get_Model(){return this->model;}
	string Phone::Get_Version_SO(){return this->version_SO;}
	string Phone::Get_Camera_f(){return this->camera_f;}
	string Phone::Get_Camera_t(){return this->camera_t;}
	//string Phone::Get_Owner(){return this->owner;}
	int Phone::Get_Mem_r(){return this->mem_r;}
	int Phone::Get_Mem_rom(){return this->mem_rom;}
	int Phone::Get_Weight(){return this->weight;}
	//int Phone::Get_Num_Phones(){return this->num_Phones;}
	//UUser::Get_User(){return this->usr}
	char* Phone::Get_PhoneC(){return this->phoneNumber;}
	float Phone::Get_Price(){return this->price;}
	



	void   Phone::Set_Company(string comp){company=comp;}
	void   Phone::Set_Model(string mol){model=mol;}
	void   Phone::Set_Version_SO(string ver){version_SO=ver;}
	void   Phone::Set_Camera_f(string camf){camera_f=camf;}
	void   Phone::Set_Camera_t(string camt){camera_t=camt;}
	//void   Phone::Set_Owner(string own){owner=own;}
	void   Phone::Set_Mem_r(int memr){mem_r=memr;}
	void   Phone::Set_Mem_rom(int mem_Rom){mem_rom=mem_Rom;}
	void   Phone::Set_Weight(int w){weight=w;}
	//void   Phone::Set_Num_Phones(int num_P){num_Phones=num_P;}
//	void   Phone::Set_User(User usr){this->usr;}
	void   Phone::Set_PhoneC(const char* number){
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

	void   Phone::Set_Price(float price){price=price;}
	
/* Metodos */


/*void Phone::Usuario_P(){



}*/

bool   Phone::ValidNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 8){
		flag=true;
	}

	return flag;
}
