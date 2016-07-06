#include <iostream>
#include "user.h"
#ifndef PHONE_H
#define PHONE_H


using namespace std;

class Phone{
private:
	string company;
	string model;
	string version;
	float  weight;
	float  camera_f;
	float  price;
	float  camera_t;
	int    mem_ram;
	int    mem_rom;
	char*  phoneNumber;
	User*  owner;

	
public:
	/*Constructores y Destructores*/
	Phone();
	Phone(string,string,string,float,float,float,int,int,float);
	Phone(string,string);
	~Phone();

	/*Getters and Setters*/ 
	void   Set_Company(string);
	void   Set_Model(string);
	void   Set_Version(string);
	void   Set_Weight(float);
	void   Set_Camera_f(float);
	void   Set_Camera_t(float);
	void   Set_Mem_ram(int);
	void   Set_Mem_rom(int);
	void   Set_Price(float);
	void   Set_PhoneNumber(const char*);
	void   Set_Owner(User*);

	string Get_Company();
	string Get_Model();
	string Get_Version();
	float  Get_Weight();
	float  Get_Camera_f();
	float  Get_Camera_t();
	float  Get_Price();
	int    Get_Mem_ram();
	int    Get_Mem_rom();
	char*  Get_PhoneNumber();
	User*  Get_Owner();

	/*Metodos*/
	void Detail();
	bool ValidNumber(const char*);

};

#endif
