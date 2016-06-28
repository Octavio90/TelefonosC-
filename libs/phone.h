#include <iostream>
#ifndef PHONE_H
#define PHONE_H


using namespace std;

class Phone{
private:
	string marca;
	string modelo;
	string version_SO;
	string camara_f;
	string camara_t;
	string duenio;
	int mem_r;
	int mem_rom;
	int peso;
	
	User* contacto;
	char* phoneNumber;
	float  precio;
	;
	
public:
	/*Constructores*/
	Phone();
	Phone(string,string,string,string,string,string,int,int,int,User* contacto,char*,float);
	~Phone();

	
	/*Getters and Setters*/ 
	void   Set_Marca(string);
	void   Set_Modelo(string);
	void   Set_Versio_SO(string);
	void   Set_Camara_t(string);
	void   Set_Camara_t(string);
	void   Set_Duenio(string);
	void   Set_Mem_r(int);
	void   Set_Mem_rom(int);
	void   Set_Peso(int);
	void   Set_Usuario(*usuario);
	void   Set_PhoneC(*char);
	void   Set_Precio(precio);

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
