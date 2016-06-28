#include <iostream>
#ifndef USER_H
#define USER_H


using namespace std;

class User{
private:
	string name;
	string address;
	char*  phoneNumber;
	float  credit;
	int    numPhones;
	
public:
	/*Constructores*/
	User();
	User(string,const char*);
	User(string,string,const char*,float,int);
	~User();

	
	/*Getters and Setters*/ 
	void   Set_Name(string);
	void   Set_Address(string);
	void   Set_PhoneNumber(const char*);
	void   Set_Credit(float);
	void   Set_NumPhones(int);

	string Get_Name();
	string Get_Address();
	char*  Get_PhoneNumber();
	float  Get_Credit(); 
	int    Get_NumPhones();

	/*Metodos*/ 
	void Mostrar_Info();
	bool validNumber(const char*);
	void Detail();
};

#endif
