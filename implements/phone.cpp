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
Phone::~Phone(){
	//delete Phone;
}

/* Getters y Setters */

	void   Phone::Set_Company(string comp){company=comp;}
	void   Phone::Set_Model(string mol){model=mol;}
	void   Phone::Set_Weight(float w){weight=w;}
	void   Phone::Set_Version(float v){version=v;}
	void   Phone::Set_Camera_f(float cf){camera_f=cf;}
	void   Phone::Set_Camera_t(float ct){camera_t=ct;}
	void   Phone::Set_Mem_ram(int mram){mem_ram=mram;}
	void   Phone::Set_Mem_rom(int mrom){mem_rom=mrom;}
	void   Phone::Set_Price(float p){price=p;}

	string Phone::Get_Company(){return company;}
	string Phone::Get_Model(){return model;}
	float Phone::Get_Weight(){return weight;}
	float Phone::Get_Version(){return version;}
	float Phone::Get_Camera_f(){return camera_f;}
	float Phone::Get_Camera_t(){return camera_t;}
	int Phone::Get_Mem_ram(){return mem_ram;}
	int Phone::Get_Mem_rom(){return mem_rom;}
	float Phone::Get_Price(){return price;}
	/*void   Phone::Set_PhoneC(const char* number){
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
	}*/

/* Metodos */
	void Phone::Detail_Phone(){

	}


/*void Phone::Usuario_P(){



}*/

/*bool   Phone::ValidNumber(const char* number){
	bool flag=false;
	int  size=strlen(number);
	char prefix[]={*number,*(++number)};
	number--;
	
	if(prefix[0] == '5' && prefix[1] == '5' && size == 8){
		flag=true;
	}

	return flag;
}*/
