#include <iostream>
#ifndef USER_H
#define USER_H


using namespace std;

class User{
private:
	string name;
	string address;
	char  *phoneNumber;
	float  credit;
	int    numPhones;
	
public:
	/*Constructores*/
	User();
	User(string,char*);
	User(string,string,char*,float);
	~User();

	
	/*Getters and Setters*/ 
	void   Set_Name(string);
	void   Set_Address(string);
	void   Set_PhoneNumber(char*);
	void   Set_Credit(float);

	string Get_Name();
	string Get_Address();
	char  *Get_PhoneNumber();
	float  Get_Credit(); 

	/*Metodos*/ 
	void Detail();
	bool validNumber(char*);
};

#endif