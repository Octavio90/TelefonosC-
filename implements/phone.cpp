#include <iostream>
#include <string.h>
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


/* Constructores y Destructores */
Phone::Phone(){}
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
Phone::~Phone(){}

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
float  Phone::Get_Weight(){return weight;}
float  Phone::Get_Version(){return version;}
float  Phone::Get_Camera_f(){return camera_f;}
float  Phone::Get_Camera_t(){return camera_t;}
float  Phone::Get_Price(){return price;}
int    Phone::Get_Mem_ram(){return mem_ram;}
int    Phone::Get_Mem_rom(){return mem_rom;}



/* Metodos */
void Phone::Detail(){
	cout << "Propietario : " << "<implemment>" << endl;
	cout << "Marca     : " << Get_Company() << endl;
	cout << "Modelo    : " << Get_Model() << endl;
	cout << "Peso      : " << Get_Weight() << endl;
	cout << "Version   : " << Get_Version() << endl;
	cout << "Precio    : " << Get_Price() << endl;
	cout << "Camara Frontal: " << Get_Camera_f() << endl;
	cout << "Camara Trasera: " << Get_Camera_t() << endl;
	cout << "Numero Asignado: " << "<implemment>" << endl; 
}


