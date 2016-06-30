#include <iostream>
#include "phone.h"
#ifndef USER_H
#define USER_H


using namespace std;

class User{
private:
	string  name;
	string  address;
	Phone*  phoneNumber;
	float   credit;
	int     numPhones;
	
public:
	/*Constructores y Destructores*/
	User();
	User(string);
	User(string,string,float,int);
	~User();

	
	/*Getters and Setters*/ 
	void   Set_Name(string);
	void   Set_Address(string);
	void   Set_Credit(float);
	void   Set_NumPhones(int);

	string  Get_Name();
	string  Get_Address();
	Phone*  Get_PhoneNumber();
	float   Get_Credit(); 
	int     Get_NumPhones();

	/*Metodos*/ 

	void Detail();
	bool AddPhoneNumber(const Phone &);
};

#endif
