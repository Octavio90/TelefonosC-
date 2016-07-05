#include <iostream>
#ifndef PHONE_H
#define PHONE_H
//#include "libs/user.h"


using namespace std;

class Phone{
private:
	string company;
	string model;
	float weight;
	float version;
	float camera_f;
	float camera_t;
	int mem_ram;
	int mem_rom;
	float price;
	char* phoneNumber;
	int num_Phones;
	User own;

public:
//Getter y Setters
	/*
	void   Set_Company(string comp);
	void   Set_Model(string mol);
	void   Set_Weight(float w);
	void   Set_Version(float v);
	void   Set_Camera_f(float cf);
	void   Set_Camera_t(float ct);
	void   Set_Mem_ram(int mram);
	void   Set_Mem_rom(int mrom);
	void   Set_Price(float p);
	//nuevos vset para telfonos y numero de telefonos
	void   Set_Phone_tel(const char* phoneNumber);
	void   Set_Num_Phones(int num); 	
	*/	
	void   Set_Company(string);
	void   Set_Model(string);
	void   Set_Weight(float);
	void   Set_Version(float);
	void   Set_Camera_f(float);
	void   Set_Camera_t(float);
	void   Set_Mem_ram(int);
	void   Set_Mem_rom(int);
	void   Set_Price(float);
	//nuevos vset para telfonos y numero de telefonos
	void   Set_Phone_tel(const char*);
	void   Set_Num_Phones(int);

	string Get_Company();
	string Get_Model();
	float Get_Weight();
	float Get_Version();
	float Get_Camera_f();
	float Get_Camera_t();
	int Get_Mem_ram();
	int Get_Mem_rom();
	float Get_Price();
	//nuevos gets para telefono y numero de telefono
	char* Get_Phone_tel();
	int	Get_Num_Phones();


	//constructores
	Phone();
	//setear los parametros sin dueño
	Phone(string , string , float ,float ,float , float ,int ,int ,float );
	//compania y modelo
	Phone(string , string);
	//Usuario y telefono 
	Phone(string , string , float ,float ,float , float ,int ,int ,float, const char*,int );
	Phone(User own, string);
	~Phone();

	//Metodos a definir
	void  Detail_Phone();
	void search_Phone();
	bool ValidNumber(const char*);
	//void sign_user(string);
};

#endif
