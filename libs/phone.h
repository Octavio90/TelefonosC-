#include <iostream>
#ifndef PHONE_H
#define PHONE_H


using namespace std;

class Phone{
private:
	string company;
	string model;
	string version_SO;
	string camera_f;
	string camera_t;
	string owner;
	int mem_r;
	int mem_rom;
	int weight;
	
	User* contact;
	char* phoneNumber;
	float  price;
	
	
public:
	/*Constructores*/
	Phone();
	Phone(string,string,string,string,string,string,int,int,int,User* contacto,char*,float);
	~Phone();

	
	/*Getters and Setters*/ 
	void   Set_Company(string);
	void   Set_Model(string);
	void   Set_Version_SO(string);
	void   Set_Camera_t(string);
	void   Set_Camera_t(string);
	void   Set_Owner(string);
	void   Set_Mem_r(int);
	void   Set_Mem_rom(int);
	void   Set_Wight(int);
	void   Set_User(*usuario);
	void   Set_PhoneC(*char);
	void   Set_Price(float);

	string Get_Marca();
	string Get_Modelo();
	string Get_Versio_SO();
	string Get_Camara_t();
	string Get_Camara_t();
	string Get_Duenio();
	int Get_Mem_r();
	int Get_Mem_rom();
	int Get_Peso();
	Usuario Get_Usuario();
	char* Get_PhoneC();
	float Get_Precio();
	/*Metodos*/ 
	void Detail();
	bool validNumber(char*);
};

#endif
