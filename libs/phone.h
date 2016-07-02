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
	//string owner;
	int mem_r;
	int mem_rom;
	int weight;
	//int num_Phones;
	//User* contact;
	char* phoneNumber;
	float  price;
	
	
public:
	/*Constructores*/
	Phone();
	Phone(string,string,string,string,string,int,int,int,const char*,float);
	~Phone();

	
	/*Getters and Setters*/ 
	void   Set_Company(string);
	void   Set_Model(string);
	void   Set_Version_SO(string);
	void   Set_Camera_f(string);
	void   Set_Camera_t(string);
	//void   Set_Owner(string);
	void   Set_Mem_r(int);
	void   Set_Mem_rom(int);
	void   Set_Weight(int);
	//void   Set_Num_Phones(int);
	//void   Set_User(*usuario);
	void   Set_PhoneC(const char*);
	void   Set_Price(float);

	string Get_Company();
	string Get_Model();
	string Get_Version_SO();
	string Get_Camera_f();
	string Get_Camera_t();
	//string Get_Owner();
	int Get_Mem_r();
	int Get_Mem_rom();
	int Get_Weight();
	//int Get_Num_Phones();
	//Usuario Get_User();
	char* Get_PhoneC();
	float Get_Price();
	
	/*Metodos*/ 
	void Detail();
	bool ValidNumber(const char*);
};

#endif
