#include <iostream>
#ifndef PHONE_H
#define PHONE_H


using namespace std;

class Phone{
private:
	string company;
	string model;
	float  weight;
	float  version;
	float  camera_f;
	float  camera_t;
	int    mem_ram;
	int    mem_rom;
	float  price;
	
public:
	/*Constructores y Destructores*/
	Phone();
	Phone(string,string,float,float,float,float,int,int,float);
	Phone(string,string);
	~Phone();

	/*Getters and Setters*/ 
	void   Set_Company(string);
	void   Set_Model(string);
	void   Set_Weight(float);
	void   Set_Version(float);
	void   Set_Camera_f(float);
	void   Set_Camera_t(float);
	void   Set_Mem_ram(int);
	void   Set_Mem_rom(int);
	void   Set_Price(float);

	string Get_Company();
	string Get_Model();
	float  Get_Weight();
	float  Get_Version();
	float  Get_Camera_f();
	float  Get_Camera_t();
	int    Get_Mem_ram();
	int    Get_Mem_rom();
	float  Get_Price();

	/*Metodos*/
	void Detail();

};

#endif
