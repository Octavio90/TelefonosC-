#include <iostream>
#ifndef PHONE_H
#define PHONE_H


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
	//User own;
	//User contact;
	float price;
	string *mi_tel_number;
	
public:

	void   Set_Company(string comp);
	void   Set_Model(string mol);
	void   Set_Weight(float w);
	void   Set_Version(float v);
	void   Set_Camera_f(float cf);
	void   Set_Camera_t(float ct);
	//void   Set_Owner(User *own);
	void   Set_Mem_ram(int mram);
	void   Set_Mem_rom(int mrom);
	//void   Set_Num_Phones(int);
	//void   Set_User(*usuario);
	void   Set_Price(float p);
	//void   Set_Num_Tel(string mi_num);

	string Get_Company();
	string Get_Model();
	float Get_Weight();
	float Get_Version();
	float Get_Camera_f();
	float Get_Camera_t();
	//string Get_Owner();
	int Get_Mem_ram();
	int Get_Mem_rom();
	
	//int Get_Num_Phones(){return ;}
	//Usuario Get_User(){return ;}
	//char* Get_PhoneC(){return ;}
	float Get_Price();

	//constructores
	Phone();

	Phone(string , string , float ,float ,float , float ,int ,int ,float );
	Phone(string , string );
	~Phone();

	//Metodos a definir
	void Detail_Phone();

};

#endif
